# wly-media

## Project setup
```
npm install
```

### Compiles and hot-reloads for development
```
npm run serve
```

### Compiles and minifies for production
```
npm run build
```

### Run your tests
```
npm run test
```

### Lints and fixes files
```
npm run lint
```
### 调试注意事项
yarn serve 调试时需要打开proxifier代理
如果请求接口提示缺少source_id
可在资讯中台
https://tme.wltong.cn/content2/oss/v3#/iframe4?type=image
在请求：
https://tme.wltong.cn/content2/oss/default/get_url?type=image
获取素材中心地址后的query参数
https://tme.wltong.cn/content2/media/index/image?c_source_id=5d906b551500ef212833e909&c_timestamp=1570593720&c_sign=cddb63672fb21241d4fb6e9fc89b16df&source_id=5d906b551500ef212833e909

添加hosts配置
111.230.120.152	dev.zt.wiiqq.com


## 路由

http://localhost:8082/content/media/index/image 图片
http://localhost:8082/content/media/index/video 视频
http://localhost:8082/content/media/index/audio 音频
http://localhost:8082/content/media/picker/image 选择图片
http://localhost:8082/content/media/picker/video 选择视频
http://localhost:8082/content/media/picker/audio 选择音频

## 发布

打包上传
```
yarn patch
yarn deploy
```
然后打开浏览器访问下列需要更新的环境，需要先更新最后的version，即可

更新素材中心前端版本号（开发环境）
http://dev.zt.wiiqq.com/content/media/admin-api/update_front_version?version=0.0.45
更新素材中心前端版本号（测试环境）
https://wly-me.wiiqq.com/content/media/admin-api/update_front_version?version=0.0.45
更新素材中心前端版本号（绿道）
https://tgr-me.wiiqq.com/content/media/admin-api/update_front_version?version=0.0.45
https://http://oss.tfgreenroad.com//content/media/admin-api/update_front_version?version=0.0.45
更新素材中心前端版本号（洛阳）
https://lywc.lyta.gov.cn/content/media/admin-api/update_front_version?version=0.0.27
广交会（测试环境）
https://tcms.cantonfair.org.cn/content/media/admin-api/update_front_version?version=0.0.54
广交会（正式环境）
https://cms.cantonfair.org.cn/content/media/admin-api/update_front_version?version=0.0.56
雄安
https://xiongan.wiiqq.com/content/media/admin-api/update_front_version?version=

## 参数

### query参数 -- limit

- 限制picker选择素材个数，超过则弹出提示并不允许选中
- 如{host}/content/media/picker/image?limit=2

### query参数 -- subtype

- 类型不是attachment时，设置这个参数来限制支持上传的文件MIMEType的subtype，跟类型构成如```image/jpg```
- 多个类型用```,```分隔
- 需要encode
- 如{host}/content/media/picker/image?subtype=png%2Cjpg

### query参数 -- attachmenttype


- 类型为attachment时，设置这个参数来限制支持上传的文件MIMEType
- 多个类型用```,```分隔
- 需要encode
- 如{host}/content/media/picker/attachment?attachmenttype=application%2Foctet-stream

### query参数-- setImgWidth,setImg

- 在picker中使用，并且类型为image时生效
- 设置后页面出现图片宽度/扩展参数输入框
- 用户填写了扩展参数后，会给引入的图片加上这个配置。并忽略图片宽度。如`imageView2/2/w/333/q/100`
- 用户填写了图片宽度后，会给引入的图片加上`?imageMogr2/format/jpg|imageView2/2/w/${宽度}/q/85`

### query参数-- uploadCoverToCos

- 为true值则上传视频封面图到cos，否则和原来一样上传到vod

### query参数-- maxCategoryLength
- 默认支持 30 个自定义分组，maxCategoryLength 可以随意设置前端部分的分组数量