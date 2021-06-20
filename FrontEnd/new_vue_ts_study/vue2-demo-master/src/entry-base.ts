import Vue from 'vue';
import Meta from 'vue-meta';
import App from './app.vue';
import { createStore } from './store';
import { createRouter } from './router';
import { createRequest } from './request';

Vue.use(Meta);

export { App, createStore, createRouter, createRequest };
