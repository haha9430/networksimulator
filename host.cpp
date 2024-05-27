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
    for (int i = 0; i < links_.size(); i++) {
        // links_[i]의 nodeA_
        Node* nodeA = links_[i]->returnNodeA();
        // nodeA의 id
        int nodeA_id = nodeA->id();
        // 해당 호스트의 id
        int this_id = this->id();
        if (nodeA_id == this_id) {
            // links_[i]의 send 함수 동작 (host -> link)
            links_[i]->send(packet);
            return;
        } 
    }
}

// 패킷을 받는다
void Host::received(Packet *packet) {
    // 안내 문장 출력
    std::cout << "Host #" << address_.toString() <<  ": received packet, destination port: " << packet->destPort() << "\n";
    // 서비스에 send와 received를 virtual function으로 선언 필요
    // services_[0]->received(packet);
}