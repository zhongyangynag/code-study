import Vue from 'vue'

import Category from '@/components/Category'
import CategoryBtn from '@/components/CategoryBtn'
import Uploader from '@/components/Uploader'
import MediaList from '@/components/MediaList'
import Toolbar from '@/components/Toolbar'
import Image from '@/components/Image'
import PhotoSwipe from '@/components/PhotoSwipe'

let components = [Category, CategoryBtn, Uploader, MediaList, Toolbar, Image, PhotoSwipe]

components.forEach(comp => {
  Vue.component(comp.name, comp)
})
