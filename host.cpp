#include "host.h"
  
// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize() {
    // services를 초기화
    // services_ = {};
}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet) {
    for (int i = 0; i < (int)links_.size(); i++) {
        //
        Link* link = links_[i];
        // nodeA_
        Node* nodeA_ = link->returnNodeA();
        // nodeB_
        Node* nodeB_ = link->returnNodeB();
        // nodeA_의 id
        int nodeA_id = nodeA_->id();
        // nodeB_의 id
        int nodeB_id = nodeB_->id();
        // 해당 호스트의 idW
        int this_id = this->id();
        std::vector<char> data = packet->data();

        Address srcAddress = packet->srcAddress();
        Address destAddress = packet->destAddress();
        //std::cout << "nodeA id: " << nodeA_id << ", nodeB id: " << nodeB_id << ", this id: " << this_id << std::endl;
        // nodeA_ 혹은 nodeB_가 해당 호스트일 경우
        if (nodeA_id == this_id || nodeB_id == this_id) {
            // links_[i]의 send 함수 동작 (host -> link)
            Node* host = this;
            std::cout << "Host #" << host->id() <<  ": sending packet (from: " << srcAddress.toString() << ", to: " << destAddress.toString() << ", " << (int)data.size() << " bytes)" << std::endl;
            links_[i]->send(packet, host);
            return;
        } 
    }
}

// 패킷을 받는다
void Host::received(Packet *packet) {
    for (int i = 0; i < (int)links_.size(); i++) {
        // services_[i]의 포트
        short port_ = services_[i]->returnPort();
        // 패킷의 주소
        //Address destAddress = packet->destAddress();
        //std::cout << "packet destAddress : " << destAddress.toString() << ", host address : " << address_.toString() << std::endl;
        // 패킷과 호스트, 서비스의 주소 및 포트 확인
        if (address_ == packet->destAddress() && port_ == packet->destPort()) {
            // 패킷을 받았다는 문장 출력
            std::cout << "Host #" << id() <<  ": received packet, destination port: " << packet->destPort() << "\n";
            services_[i]->received(packet);
            // services_[i]의 received 함수 동작 (host -> service)
            //services_[i]->received(packet);
        }
    }
}