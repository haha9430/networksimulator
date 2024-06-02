#include "echo_service.h"

void EchoService::send(std::string message) {
    return;
}

// 메시지를 담은 패킷을 받고 반송한다.
void EchoService::received(Packet *packet) {
    // 전송자 주소 -> 수신자 주소
    Address destAddress = packet->srcAddress();
    // 전송자 포트 -> 수신자 포트
    short destPort = packet->srcPort();
    // 메시지
    std::string message = packet->dataString();
    //std::cout << packet->destAddress().toString() << ", " << host_->address().toString() << ", " << packet->destPort() << ", " << Service::port_ << std::endl;
    if (packet->destAddress() == host_->address() && packet->destPort() == Service::port_) {
        Packet* p = new Packet(Service::host_->address(), destAddress, Service::port_, destPort, message);
        std::cout << "EchoService: received \"" << message << "\" from " << destAddress.toString() << ":" << destPort << ", send reply with same data" << std::endl;
        Service::host_->send(p); // (service -> host)
    }
}