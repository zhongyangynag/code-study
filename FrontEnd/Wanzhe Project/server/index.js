const express = require('express')

const app = express()

//这里是为用户登录后设置的密钥,其实应该在环境变量里面,只是为了方便写在了代码里面
app.set('secret', 'qweewqewqsadad25315')

//跨域
app.use(require('cors')())
//post请求
app.use(express.json())

app.use('/uploads', express.static(__dirname + '/uploads'))

require('./plugins/db')(app)
require('./routes/admin/index')(app)

app.listen(3000, () => {
  console.log('running http://localhost:3000')
})
