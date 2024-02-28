const ffi = require("ffi-napi");

console.log("Before ffi.Library initialization");
const parser = ffi.Library("./x84_64/libsomeip_parser_ics.so", {
  // 定义共享对象文件中的函数及其参数和返回值类型
  'loadFormatJson': ['void', ['string']],
  'deserializebyMethodID': ['string', ['int', 'int', 'int', 'uint8*', 'string*']]
});
console.log("After ffi.Library initialization");


console.log("Before calling loadFormatJson");
parser.loadFormatJson("./TotalJsonFormat.json");
console.log("After calling loadFormatJson");
