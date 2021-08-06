/* eslint-disable */

import Vue from "vue"
import {
  Button,
  Row,
  Col,
  Menu,
  MenuGroup,
  Submenu,
  MenuItem,
  Icon,
  Message,
  Alert,
  Notice,
  Modal,
  Poptip,
  Form,
  FormItem,
  Input,
  Select,
  Option,
  Page,
  CheckboxGroup,
  Checkbox,
  RadioGroup,
  Radio,
  Tag,
  Spin
} from "iview"

let components = [
  Button,
  Row,
  Col,
  Menu,
  MenuGroup,
  Submenu,
  MenuItem,
  Icon,
  Message,
  Alert,
  Modal,
  Poptip,
  Form,
  FormItem,
  Input,
  Select,
  Option,
  Page,
  CheckboxGroup,
  Checkbox,
  RadioGroup,
  Radio,
  Tag,
  Spin
]

Vue.prototype.$Message = Message
Vue.prototype.$Notice = Notice
Vue.prototype.$Modal = Modal


components.map(item => {
  Vue.component(item.name, item)
})

import "iview/dist/styles/iview.css"
