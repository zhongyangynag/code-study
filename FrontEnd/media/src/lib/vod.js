import TcVod from 'vod-js-sdk-v6'
import reuqest from '@/lib/request'

function getSignatureFunction (authUrl) {
  return function getSignature () {
    return reuqest({ url: authUrl, data: JSON.stringify({ 'Action': 'GetUgcUploadSign' }) }).then(res => {
      return res.signature
    })
  }
}

class RocketVod {
  constructor ({ authUrl }) {
    this.initVod(authUrl)
  }

  initVod (authUrl) {
    this.vod = new TcVod({
      getSignature: getSignatureFunction(authUrl)
    })
  }

  upload ({ file, fileName, onProgress, onSuccess, onError }) {
    this.vod.upload({
      mediaFile: file
    }).on('cover_upload', (info) => {
    }).on('media_progress', (info) => {
    }).done().then(res => {
      let { fileId, video } = res
      let { url } = video
      onSuccess.call(this, {
        data: {
          file_type: file.type,
          size: file.size,
          name: fileName,
          file_id: fileId,
          play_url: url
        }
      })
    }).catch(err => {
      onError.call(this, err)
    })
  }

  uploadCover ({ fileId, coverFile, onSuccess, onError }) {
    this.vod.upload({
      coverFile: coverFile,
      fileId: fileId
    }).on('cover_upload', info => {
    }).done().then(res => {
      onSuccess.call(this, res)
    }).catch(err => {
      onError.call(this, err)
    })
  }
}

export default RocketVod
