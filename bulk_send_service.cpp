#include "bulk_send_service.h"

void BulkSendService::send(std::string message) {
    for(double i = startTime_; i < stopTime_; i += delay_) {
        // 패킷 생성

        // 패킷 전송
        
    } 
}

void BulkSendService::received(Packet* packet) {
    return;
}