#ifndef LINK_H
#define LINK_H

#include "packet.h"
#include "node.h"
#include <cstdlib>

//class Node;

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
    // 링크를 호출한 노드가 nodeB_라면 nodeA_에게 패킷을 전달
    if (link_node == nodeB_) {
      nodeA_->received(packet);
    }
    // 링크를 호출한 노드가 nodeA_라면 nodeB_에게 패킷을 전달
    else {
      nodeB_->received(packet);
    }
    return;
  }
};

#endif