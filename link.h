#ifndef LINK_H
#define LINK_H

#include "packet.h"
#include "object.h"
#include "node.h"
#include <cstdlib>
#include <iostream>

//class Node;

class Link : public Object {
  friend class LinkInstaller;

private:
  Link(Node *nodeA, Node *nodeB, double delay = 0.0) : nodeA_(nodeA), nodeB_(nodeB), delay_(delay) {}

  Node *nodeA_;
  Node *nodeB_;
  double delay_;

  Node *other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
  }
  virtual std::string name() override { return "Link"; }
public:
  double delay() { return delay_; }
  Node *returnNodeA() const;
  Node *returnNodeB() const;
  void send(Packet *packet, Node *node);
};

#endif