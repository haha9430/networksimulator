#ifndef LINK_H
#define LINK_H

#include "packet.h"
#include <cstdlib>

class Node;

class Link {
  friend class LinkInstaller;

private:
  Link(Node *nodeA, Node *nodeB) : nodeA_(nodeA), nodeB_(nodeB) {}

  Node *nodeA_;
  Node *nodeB_;

  Node *other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
  }
public:
  Node *returnNodeA() {
    return nodeA_;
  }
  void send(Packet *packet) {
    // 패킷의 목적지 주소
    Address packet_destAddress = packet->destAddress();
    // nodeB_의 주소
    Address nodeB_Address = nodeB_->address();
    // 같으면 패킷의 목적지는 nodeB_이므로 nodeB_는 패킷을 수령
    if (packet_destAddress == nodeB_Address) {
      nodeB_->received(packet);
    }else { // 같지 않다면 nodeB_를 전달
      nodeB_->send(packet);
    }
    return;
  }
};

#endif