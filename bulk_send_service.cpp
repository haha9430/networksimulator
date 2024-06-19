#include "bulk_send_service.h"

void BulkSendService::send(std::string message) {
    for(double i = startTime_; i < stopTime_; i += delay_) {
        // 패킷 생성
        std::string m = "a";
        std::string message_;
        for (int i = 0; i < 512; i++) {
            message += m;
        }
        Packet* p = new Packet(host_->address(), destAddress_, Service::port_, destPort_, message_);
        Service::host_->send(p); // (service -> host)
    } 
}

void BulkSendService::received(Packet* packet) {
    return;
}