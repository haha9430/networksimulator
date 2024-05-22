#include "node.h"

  Node::Node() : id_(nextId_++) {
    nextId_ = 0;
  }
  int Node::id() const { return id_; }