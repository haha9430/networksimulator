#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <iostream>

struct RoutingEntry {
public:
  Address destination;
  Link *nextLink;

  // 생성자 추가, 생성자가 없이 선언하려고 하니 안됨.
  RoutingEntry(Address d, Link* nl): destination(d), nextLink(nl) {}
};

class Router : public Node {
protected:
  std::vector<RoutingEntry> routingTable_;
public:
  void send(Packet *packet) {
    // 패킷의 목적지 주소
    Address packet_destAddress = packet->destAddress();
    for (int i = 0; i < (int)routingTable_.size(); i++) {
      if (packet_destAddress == routingTable_[i].destination) {
        Link* link = routingTable_[i].nextLink;
        Node* router = this;
        link->send(packet, router); // (router -> link)
        return;
      }
    }
  }
};

#endif