#ifndef NODE_H
#define NODE_H

#include "packet.h"
#include <vector>

class Link;

class Node {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;

protected: // 상속을 받아도 접근 가능해야함
  // 연결된 링크 목록
  std::vector<Link *> links_;

public:
  Node() : id_(nextId_++) {}
  int id() const { return id_; }

  bool operator ==(Node* node) {
    bool b = false;
    if (id_ == node->id()) {
      b = true;
    }
    return b;
  }
  void addLink(Link *link) {
    links_.push_back(link);
  }

  Address address();
  // Node를 부모 클래스로 하는 자식 클래스들이 Node 타입에서도 send 함수를 쓸 수 있음.
  void send(Packet *packet) {
    return;
  }
  virtual void received(Packet *packet) = 0;
};

#endif