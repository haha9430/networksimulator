#include "echo_service.h"

// 메시지를 담은 패킷을 받고 반송한다.
void EchoService::received(Packet *packet) {
    // 전송자 주소 -> 수신자 주소
    Address destAddress = packet->srcAddress();
    // 전송자 포트 -> 수신자 포트
    short destPort = packet->srcPort();
    // 메시지
    std::string message = packet->dataString();
    Packet* p = new Packet(Service::host_->address(), destAddress, Service::port_, destPort, message);
    std::cout << "EchoService: received " << packet->dataString() << std::endl;
    Service::host_->send(p); // (service -> host)
}