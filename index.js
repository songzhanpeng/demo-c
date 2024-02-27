const ffi = require('ffi-napi');

// 载入共享对象文件
const hello = ffi.Library('./hello', {
    'hello': ['void', ['string']]
});

// 传入参数调用 hello 函数
hello.hello('Alice');
