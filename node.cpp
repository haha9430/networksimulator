#include "node.h"

  Node::Node() : id_(nextId_++) {}
  int Node::id() const { return id_; }