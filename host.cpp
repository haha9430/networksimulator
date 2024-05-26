#include "host.h"

Address Host::address() { return address_; }
Host::Host(Address address) : address_(address) {}

// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize() {
    // services를 초기화
    services_ = {};
}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet) {
    
}

// 패킷을 받는다
void Host::received(Packet *packet) {
    // 안내 문장 출력
    std::cout << "Host #" << address_.toString() <<  ": received packet, destination port: " << packet->destPort() << "\n";
    // 서비스에 send와 received를 virtual function으로 선언 필요
    // services_[0]->received(packet);
}