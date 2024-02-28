/**
 * Copyright @ 2023 iAuto Software(Shanghai) Co., Ltd.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are NOT permitted except as agreed by
 * iAuto Software(Shanghai) Co., Ltd.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#ifndef INCLUDE_NESOMEIP_PARSER_DEFINE_H
#define INCLUDE_NESOMEIP_PARSER_DEFINE_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation(use a .cpp suffix)
#endif

#include <stdint.h>
#include <string>

// Define return value 
const int NE_SOMEIP_PARSER_RET_ERROR   = -1;
const int NE_SOMEIP_PARSER_RET_NO_ERROR   = 0;

// Define enum for someip log level
enum NE_SOMEIP_PARSER_LOG_LEVEL {
    NE_SOMEIP_PARSER_LOG_LEVEL_NOLOG = 0,
    NE_SOMEIP_PARSER_LOG_LEVEL_FATAL = 1,
    NE_SOMEIP_PARSER_LOG_LEVEL_ERROR = 2,
    NE_SOMEIP_PARSER_LOG_LEVEL_WARNING = 3,
    NE_SOMEIP_PARSER_LOG_LEVEL_INFO = 4,
    NE_SOMEIP_PARSER_LOG_LEVEL_DEBUG = 5,
    NE_SOMEIP_PARSER_LOG_LEVEL_UNKNOW = 0XFF,
};

// Define enum for someip message type
enum NESomeIPMessageType {
    NESomeIPMessageType_Request = 0x00,             // methodrequest or field getter/setter request
    NESomeIPMessageType_Request_NoReturn = 0x01,    // methodrequest FireForget
    NESomeIPMessageType_Notification = 0x02,        // event or field notify
    NESomeIPMessageType_Response = 0x80,            // methodresponse or field getter/setter response
    NESomeIPMessageType_Error = 0x81,               // methodresponse or field getter/setter response(with error)
    NESomeIPMessageType_Unknown = 0xFF,             // Invalid value
};

#endif  // INCLUDE_NESOMEIP_PARSER_DEFINE_H
/* EOF */
