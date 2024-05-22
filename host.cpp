#include "host.h"

Address Host::address() { return address_; }
Host::Host(Address address) : address_(address) {}

// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize() {

}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet) {
    
}