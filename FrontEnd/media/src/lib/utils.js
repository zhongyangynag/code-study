import { saveAs } from 'file-saver'
import { isPlainObject } from 'lodash'

const image2base64 = img => {
  const canvas = document.createElement('canvas')
  canvas.width = img.width
  canvas.height = img.height
  const ctx = canvas.getContext('2d')
  ctx.drawImage(img, 0, 0, img.width, img.height)
  const mime = img.src.substring(img.src.lastIndexOf('.') + 1).toLowerCase()
  const dataUrl = canvas.toDataURL('image/' + mime)
  return dataUrl
}

const dataUrl2Blob = dataUrl => {
  var arr = dataUrl.split(',')
  var mime = arr[0].match(/:(.*?);/)[1]
  var bStr = atob(arr[1])
  var n = bStr.length
  var unit8Array = new Uint8Array(n)
  while (n--) {
    unit8Array[n] = bStr.charCodeAt(n)
  }
  return new Blob([unit8Array], { type: mime })
}

const downloadImage = (url, name) => {
  const image = new Image()
  image.setAttribute('crossOrigin', 'Anonymous')
  image.src = url + '?' + new Date().getTime()
  image.onload = function () {
    const imageDataUrl = image2base64(image)
    const imageBlobData = dataUrl2Blob(imageDataUrl)
    saveAs(imageBlobData, name)
  }
}

const getImageSize = url => {
  return new Promise((resolve, reject) => {
    let img = new Image()
    img.onload = () => resolve(img)
    img.onerror = reject
    img.src = url
  })
}

const download = (data, fileName, mimeType) => {
  var self = window // this script is only for browsers anyway...
  var defaultMime = 'application/octet-stream' // this default mime also triggers iframe downloads
  mimeType = mimeType || defaultMime
  var payload = data
  var url = !fileName && !mimeType && payload
  var anchor = document.createElement('a')
  var toString = function (a) {
    return String(a)
  }
  var MyBlob = self.Blob || self.MozBlob || self.WebKitBlob || toString
  fileName = fileName || 'download'
  var blob
  var reader
  MyBlob = MyBlob.call ? MyBlob.bind(self) : Blob

  if (String(this) === 'true') {
    // reverse arguments, allowing download.bind(true, "text/xml", "export.xml") to act as a callback
    payload = [payload, mimeType]
    mimeType = payload[0]
    payload = payload[1]
  }

  if (url && url.length < 2048) {
    // if no filename and no mime, assume a url was passed as the only argument
    fileName = url
      .split('/')
      .pop()
      .split('?')[0]
    anchor.href = url // assign href prop to temp anchor
    if (anchor.href.indexOf(url) !== -1) {
      // if the browser determines that it's a potentially valid url path:
      var ajax = new XMLHttpRequest()
      ajax.open('GET', url, true)
      ajax.responseType = 'blob'
      ajax.onload = function (e) {
        download(e.target.response, fileName, defaultMime)
      }
      setTimeout(function () {
        ajax.send()
      }, 0) // allows setting custom ajax headers using the return:
      return ajax
    } // end if valid url?
  } // end if url?

  // go ahead and download dataURLs right away
  if (/^data:[\w+-]+\/[\w+-]+[,;]/.test(payload)) {
    if (payload.length > 1024 * 1024 * 1.999 && MyBlob !== toString) {
      payload = dataUrlToBlob(payload)
      mimeType = payload.type || defaultMime
    } else {
      return navigator.msSaveBlob // IE10 can't do a[download], only Blobs:
        ? navigator.msSaveBlob(dataUrlToBlob(payload), fileName)
        : saver(payload) // everyone else can save dataURLs un-processed
    }
  } // end if dataURL passed?

  blob =
    payload instanceof MyBlob
      ? payload
      : new MyBlob([payload], { type: mimeType })

  function dataUrlToBlob (strUrl) {
    var parts = strUrl.split(/[:;,]/)
    var type = parts[1]
    var decoder = parts[2] === 'base64' ? atob : decodeURIComponent
    var binData = decoder(parts.pop())
    var mx = binData.length
    var i = 0
    var uiArr = new Uint8Array(mx)

    for (i; i < mx; ++i) uiArr[i] = binData.charCodeAt(i)

    return new MyBlob([uiArr], { type: type })
  }

  function saver (url, winMode) {
    if ('download' in anchor) {
      // html5 A[download]
      anchor.href = url
      anchor.setAttribute('download', fileName)
      anchor.className = 'download-js-link'
      anchor.innerHTML = 'downloading...'
      anchor.style.display = 'none'
      document.body.appendChild(anchor)
      setTimeout(function () {
        anchor.click()
        document.body.removeChild(anchor)
        if (winMode === true) {
          setTimeout(function () {
            self.URL.revokeObjectURL(anchor.href)
          }, 250)
        }
      }, 66)
      return true
    }

    // handle non-a[download] safari as best we can:
    if (
      /(Version)\/(\d+)\.(\d+)(?:\.(\d+))?.*Safari\//.test(navigator.userAgent)
    ) {
      url = url.replace(/^data:([\w/\-+]+)/, defaultMime)
      if (!window.open(url)) {
        // popup blocked, offer direct download:
        if (
          confirm(
            'Displaying New Document\n\nUse Save As... to download, then click back to return to this page.'
          )
        ) {
          location.href = url
        }
      }
      return true
    }

    // do iframe dataURL download (old ch+FF):
    var f = document.createElement('iframe')
    document.body.appendChild(f)

    if (!winMode) {
      // force a mime that will download:
      url = 'data:' + url.replace(/^data:([\w/\-+]+)/, defaultMime)
    }
    f.src = url
    setTimeout(function () {
      document.body.removeChild(f)
    }, 333)
  } // end saver

  if (navigator.msSaveBlob) {
    // IE10+ : (has Blob, but not a[download] or URL)
    return navigator.msSaveBlob(blob, fileName)
  }

  if (self.URL) {
    // simple fast and modern way using Blob and URL:
    saver(self.URL.createObjectURL(blob), true)
  } else {
    // handle non-Blob()+non-URL browsers:
    if (typeof blob === 'string' || blob.constructor === toString) {
      try {
        return saver('data:' + mimeType + ';base64,' + self.btoa(blob))
      } catch (y) {
        return saver('data:' + mimeType + ',' + encodeURIComponent(blob))
      }
    }

    // Blob but not URL support:
    reader = new FileReader()
    reader.onload = function (e) {
      saver(this.result)
    }
    reader.readAsDataURL(blob)
  }
  return true
}

const downloadBinary = (url, fileName = 'file', mimeType = 'image/gif') => {
  fetch(url).then(res => res.blob()).then(blob => {
    download(blob, fileName, mimeType)
  })
}

function loadImage (url) {
  return new Promise((resolve, reject) => {
    let img = new Image()
    img.onload = () => resolve(img)
    img.onerror = reject
    img.src = url
  })
}

const formatImageData = (urls, callback) => {
  let pr = []
  let imgs = []
  urls.forEach(url => {
    if (isPlainObject(url)) {
      url = url.img_url
    }
    let p = loadImage(url)
      .then(img => {
        imgs.push({
          src: url,
          w: img.width,
          h: img.height
        })
      })
    pr.push(p)
  })

  Promise.all(pr)
    .then((res) => {
      callback.call(this, imgs)
    }).catch()
}

export { downloadImage, getImageSize, download, downloadBinary, formatImageData }
