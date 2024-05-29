#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include "link.h"
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
  void send(Packet *packet);
  void received(Packet *Packet) override;
};

#endif