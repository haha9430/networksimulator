#include "node.h"

int Node::nextId_ = 0;

void Node::send(Packet *packet) {
    std::cout << "node send" << std::endl;
}
void Node::received(Packet *packet) {
    std::cout << "node received" << std::endl;
}