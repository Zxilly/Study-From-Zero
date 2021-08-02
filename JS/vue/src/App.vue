<template>
  <div id="app">
    <header>
      <button @click="test">Test Button
      </button>
    </header>
  </div>
</template>

<script>
import PasteClient from "pastebin-api";

export default {
  name: 'App',
  components: {},
  methods: {
    test: function () {
      const client = new PasteClient("DEV_KEY_HERE");
    }
  }
}
</script>
