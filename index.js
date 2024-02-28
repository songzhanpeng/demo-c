const ffi = require("ffi-napi");

const parser = ffi.Library("./x84_64/libsomeip_parser_ics.so", {
  // 定义共享对象文件中的函数及其参数和返回值类型
  'loadFormatJson': ['void', ['string']],
  'deserializebyMethodID': ['string', ['int', 'int', 'int', 'uint8*', 'string*']]
});

parser.loadFormatJson("./TotalJsonFormat.json");
