import CosCloud from 'cos-js-sdk-v5'
import SparkMD5 from 'spark-md5'

class RocketCos {
  constructor ({ appId, bucket, region, folder, authUrl }) {
    this.appId = appId
    this.bucket = bucket
    this.region = region
    this.folder = folder
    this.initCos(authUrl)
  }

  initCos (url) {
    this.cos = new CosCloud({
      FileParallelLimit: 5,
      ChunkParallelLimit: 5,
      ChunkMbSize: 8 * 1024 * 1024,
      getAuthorization: function (options, callback) {
        let xhr = new XMLHttpRequest()
        xhr.open('GET', url, true)
        xhr.onload = function (e) {
          let response = null
          try {
            response = JSON.parse(e.target.responseText)
          } catch (e) {}
          let { ret, data } = response
          if (ret === 0) {
            callback.call(this, {
              TmpSecretId: data.credentials && data.credentials.tmpSecretId,
              TmpSecretKey: data.credentials && data.credentials.tmpSecretKey,
              XCosSecurityToken: data.credentials && data.credentials.sessionToken,
              ExpiredTime: data.expiredTime
            })
          }
        }
        xhr.send()
      }
    })
  }

  upload ({ file, fileName, originalFileName, originalFileExt, type, onProgress, onSuccess, onError }) {
    let that = this
    const md5Name = SparkMD5.hash(fileName)
    const key = `${that.folder}/${md5Name}/${originalFileName}${originalFileExt}`
    // const key = `${that.folder}/${md5Name}`
    console.log('key', key, `https://${that.bucket}-${that.appId}.cos.${that.region}.myqcloud.com/${that.folder}/${md5Name}/${originalFileName}${originalFileExt}`
    )
    const object = {
      Bucket: `${that.bucket}-${that.appId}`,
      Region: that.region,
      Key: key,
      Body: file
    }
    // if (type === 'image') {
    //   object.Headers = { 'Pic-Operations': JSON.stringify({ 'is_pic_info': 1, 'rules': [{ 'fileid': `${md5Name}_100x100`, 'rule': 'style/100x100' }, { 'fileid': `${md5Name}_335x445`, 'rule': 'style/335x445' }] }) }
    //   that.cos.putObject(object, function (err, data) {
    //     if (err) {
    //       onError.call(this, err)
    //     } else {
    //       const data = {
    //         file_type: file.type,
    //         size: file.size,
    //         name: fileName,
    //         resource_path: `/${that.appId}/${that.bucket}/${that.folder}/${md5Name}`
    //       }
    //       if (type === 'attachment') {
    //         data.attachment_url = `https://${that.bucket}-${that.appId}.cos.${that.region}.myqcloud.com/${that.folder}/${md5Name}`
    //       } else {
    //         data.img_url = `https://${that.bucket}-${that.appId}.cos.${that.region}.myqcloud.com/${that.folder}/${md5Name}`
    //       }
    //       onSuccess.call(this, { data })
    //     }
    //   })
    // } else {
    that.cos.sliceUploadFile(object, function (err, data) {
      if (err) {
        onError.call(this, err)
      } else {
        const data = {
          file_type: file.type,
          size: file.size,
          name: fileName,
          resource_path: `/${that.appId}/${that.bucket}/${that.folder}/${md5Name}`
        }
        const url = `https://${that.bucket}-${that.appId}.cos.${that.region}.myqcloud.com/${that.folder}/${md5Name}/${originalFileName}${originalFileExt}`
        if (type === 'attachment') {
          data.attachment_url = url
        } else {
          data.img_url = url
        }
        onSuccess.call(this, { data })
      }
    })
    // }
  }
}

export default RocketCos
