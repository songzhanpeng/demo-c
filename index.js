const ffi = require('ffi-napi');

class FFIWrapper {
    constructor() {
        // 载入共享对象文件
        this.lib = ffi.Library('./x84_64/libsomeip_parser_ics', {
            // 定义共享对象文件中的函数及其参数和返回值类型
            'loadFormatJson': ['void', ['string']],
            'deserializebyMethodID': ['string', ['int', 'int', 'int', 'uint8*', 'string*']]
            // 添加更多函数定义...
        });
    }

    // 加载 JSON 文件并解析
    loadFormatJson(jsonPath) {
        console.log("🚀 ~ FFIWrapper ~ loadFormatJson ~ jsonPath:", jsonPath)
        this.lib.loadFormatJson(jsonPath);
    }

    // 反序列化方法
    deserializebyMethodID(serviceID, methodID, messageType, payload) {
        return this.lib.deserializebyMethodID(serviceID, methodID, messageType, payload);
    }

    // 添加更多函数调用方法...
}


const ffiWrapper = new FFIWrapper()
ffiWrapper.loadFormatJson('./TotalJsonFormat.json')