#ifndef HOST_H
#define HOST_H

#include "address.h"
#include "packet.h"
#include "service.h"
#include "link.h"
#include <vector>
#include <iostream>

class Host : public Node {
  friend class ServiceInstaller;

private:
  // 호스트의 주소
  Address address_;

  // 설치된 서비스 목록
  std::vector<Service *> services_;

public:
  Address address() { return address_; }
  Host(Address address) : address_(address) {}

  // 호스트와 설치된 서비스를 전부 초기화한다.
  void initialize() {
    // services를 초기화
    // services_ = {};
  }

  // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
  void send(Packet *packet) {
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
      // 해당 호스트의 id
      int this_id = this->id();
      // nodeA_ 혹은 nodeB_가 해당 호스트일 경우
      if (nodeA_id == this_id || nodeB_id == this_id) {
        // links_[i]의 send 함수 동작 (host -> link)
        Node* host = this;
        links_[i]->send(packet, host);
        return;
      } 
    }
  }

  // 패킷을 받는다
  void received(Packet *packet) {
    for (int i = 0; i < (int)links_.size(); i++) {
      // services_[i]의 포트
      short port_ = services_[i]->returnPort();
      // 패킷과 호스트, 서비스의 주소 및 포트 확인
      if (address_ == packet->destAddress() && port_ == packet->destPort()) {
        // 패킷을 받았다는 문장 출력
        std::cout << "Host #" << address_.toString() <<  ": received packet, destination port: " << packet->destPort() << "\n";
        // services_[i]의 received 함수 동작 (host -> service)
        services_[i]->received(packet);
      }
    }
  }
};

#endif