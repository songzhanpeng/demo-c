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

#ifndef INCLUDE_NESOMEIP_PARSER_API_H
#define INCLUDE_NESOMEIP_PARSER_API_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation(use a .cpp suffix)
#endif

#include <string>
#include <vector>
#include "NESomeIPParserDefine.h"
using namespace std;

namespace NESomeIP
{
    class NESomeIPParser;
    class NESomeIPParserAPI{
        public:
            NESomeIPParserAPI();
            ~NESomeIPParserAPI();

            /**
             * function         : load Json format file generated by iDeveleper
             * path[in]         : string -> json file/dir path
            */
            int loadFormatJson(string path);

            /**
             * function         : deserialize binary payload to json string by methodID 
             * serviceID[in]    : int   -> service ID
             * methodID[in]     : int   -> method ID
             * messageType[in]  : int   -> message type in someip header , defined in NESomeIPMessageType
             * payload[in]      : std::vector<uint8_t>  -> payload binary data
             * jsonStr[out]:    : string -> deserialized json object string
            */
            int deserializebyMethodID(int serviceID, int methodID, int messageType, std::vector<uint8_t>& payload, string& jsonStr);

            /**
             * function         : serialize json string to binary payload by methodID 
             * serviceID[in]    : int   -> service ID
             * methodID[in]     : int   -> method ID
             * messageType[in]  : int   -> message type in someip header , defined in NESomeIPMessageType
             * jsonStr[in]:     : string ->  json object string to serialize
             * payload[out]     : std::vector<uint8_t>  -> serialized payload binary data
            */       
            int serializebyMethodID(int serviceID, int methodID, int messageType, string& jsonStr, std::vector<uint8_t>& payload);

            /**
             * function         : get the json string format by methodID 
             * serviceID[in]    : int   -> service ID
             * methodID[in]     : int   -> method ID
             * messageType[in]  : int   -> message type in someip header , defined in NESomeIPMessageType
             * jsonStr[out]:    : string ->  json format object string to be modified
            */       
            int getMethodFormatbyID(int serviceID, int methodID, int messageType, string& jsonStr);

        private:
            NESomeIPParser* m_pParser;
            
    };
}


#endif // INCLUDE_NESOMEIP_PARSER_API_H
/* EOF */