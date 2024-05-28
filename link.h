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
  Node *returnNodeB() {
    return nodeB_;
  }
  void send(Packet *packet, Node *node) {
    // 링크를 호출한 노드
    Node* link_node = other(node);
    // 패킷의 목적지 주소
    Address packet_destAddress = packet->destAddress();
    // nodeA_의 주소
    Address nodeA_Address = nodeA_->address();
    // nodeB_의 주소
    Address nodeB_Address = nodeB_->address();
    // 패킷의 목적지는 nodeA_이므로 nodeA_는 패킷을 수령
    if (packet_destAddress == nodeA_Address) {
      nodeA_->received(packet);
    }
    // 패킷의 목적지는 nodeB_이므로 nodeB_는 패킷을 수령
    else if (packet_destAddress == nodeA_Address) {
      nodeB_->received(packet);
    }
    // 링크를 호출한 노드가 nodeB_라면 nodeA_에게 패킷을 전달
    else if (link_node == nodeB_) {
      nodeA_->send(packet);
    }
    // 링크를 호출한 노드가 nodeA_라면 nodeB_에게 패킷을 전달
    else if (link_node == nodeA_) {
      nodeB_->send(packet);
    }
    return;
  }
};

#endif