<template>
  <!-- <img alt="Vue logo" src="./assets/logo.png" /> -->
  <!-- <HelloWorld msg="Hello Vue 3 + TypeScript + Vite" /> -->
  <router-view />
 
</template>

<script lang="ts" setup>
import { defineComponent } from 'vue'
import HelloWorld from './components/HelloWorld.vue'
import {useRouter} from 'vue-router'
import Test from './components/Test.vue'

const router =useRouter();
</script>

<style lang="less" scoped>


#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  /* margin-top: 60px; */
}
</style>
