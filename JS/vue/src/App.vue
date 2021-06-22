<template>
  <div id="app">
    <header>
      <button @click="test">Test Button
      </button>
    </header>
  </div>
</template>

<script>
export default {
  name: 'App',
  components: {},
  methods: {
    test: function () {
      const {Authorizer} = require("casbin.js");
      const sub = "testUser";
      const obj = "/upload/*";
      const act = "read";
      const url = `http://localhost:3000/permissions`;
      const auth = new Authorizer(
          "auto", // mode
          {endpoint: url}
      );
      auth.setUser(sub).then(() => {
        // eslint-disable-next-line no-unused-vars
        const perms = auth.can(act, obj);
      });
    }
  }
}
</script>
