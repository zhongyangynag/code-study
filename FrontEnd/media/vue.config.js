const { version } = require('./package.json')
module.exports = {
  publicPath: process.env.NODE_ENV === 'production' ? `https://fe-1252759886.cos.ap-guangzhou.myqcloud.com/wly-mp/${version}/` : '/',
  filenameHashing: false,
  devServer: {
    proxy: {
      '/content/media/admin-api': {
        target: 'http://yapi.qqten.com/mock/30',
        // target: 'https://wly-me.wiiqq.com',
        changeOrigin: true
        // pathRewrite: {
        //   '^/mp': ''
        // }
      },
      '/content/media-category/category-api': {
        target: 'http://yapi.qqten.com/mock/30',
        // target: 'http://wly-me.wiiqq.com',
        changeOrigin: true
        // pathRewrite: {
        //   '^/mp': ''
        // }
      },
      '/content2/media/admin-api': {
        target: 'http://yapi.qqten.com/mock/30',
        changeOrigin: true
      },
      '/content2/media-category/category-api': {
        target: 'http://yapi.qqten.com/mock/30',
        changeOrigin: true
      }
    }
  },
  css: {
    loaderOptions: {
      less: {
        javascriptEnabled: true
      }
    }
  }
}
