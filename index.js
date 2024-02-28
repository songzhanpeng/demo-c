const ffi = require("ffi-napi");

const hello = ffi.Library("./hello.so", {
  hello: ["void", ["string"]],
});

hello.hello("Alice");
