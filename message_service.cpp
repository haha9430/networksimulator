#include "message_service.h"

// 메시지를 전송한다
void MessageService::send(std::string message) {
    //std::cout << "message service sending port : " << Service::port_ << std::endl;
    Packet* p = new Packet(host_->address(), destAddress_, Service::port_, destPort_, message);
    Service::host_->send(p); // (service -> host)
}
// 메시지를 담은 패킷을 받는다
void MessageService::received(Packet *packet) {
    // 전송자 주소 -> 수신자 주소
    Address destAddress = packet->srcAddress();
    // 전송자 포트 -> 수신자 포트
    short destPort = packet->srcPort();
    // 메시지
    //std::cout << "message service sending port : " << Service::port_ << std::endl;
    
    //Service::nextPort();
    std::string message = packet->dataString();
    std::cout << "MessageService: received \"" << message << "\" from " << destAddress.toString() << ":" << destPort << std::endl;
}