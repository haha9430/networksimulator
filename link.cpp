  #include "link.h"
  
  Node* Link::returnNodeA() const {
    return nodeA_;
  }
  Node* Link::returnNodeB() const {
    return nodeB_;
  }
  void Link::send(Packet *packet, Node *node) {
    // 링크를 호출한 노드
    Node* link_node = node;
    //std::cout << "link node id: " << link_node->id() << ", nodeA id:" << nodeA_->id() << ", nodeB id:" << nodeB_->id() << std::endl;
    //Address destAddress = packet->destAddress();
    //std::cout << "packet destAddress: " << destAddress.toString() << std::endl;
    // 링크를 호출한 노드가 nodeB_라면 nodeA_에게 패킷을 전달
    if (link_node == nodeB_) {
      std::cout << "Link: forwarding packet from node #" << nodeB_->id() << ", to node #" << nodeA_->id() << std::endl;
      nodeA_->received(packet);
    }
    // 링크를 호출한 노드가 nodeA_라면 nodeB_에게 패킷을 전달
    else {
      std::cout << "Link: forwarding packet from node #" << nodeA_->id() << ", to node #" << nodeB_->id() << std::endl;
      nodeB_->received(packet);
    }
}