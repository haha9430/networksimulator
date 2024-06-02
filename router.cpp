#include "router.h"

void Router::send(Packet *packet) {
    // 패킷의 목적지 주소
    Address packet_destAddress = packet->destAddress();
    Node* router = this;
    Address a = packet->srcAddress();
    Address b = packet->destAddress();
    std::vector<char> c = packet->data();
    for (int i = 0; i < (int)routingTable_.size(); i++) {
        //std::cout << "packet destAddress : " << packet_destAddress.toString() << ", routingTable[" << i << "] destination : " << routingTable_[i].destination.toString() << std::endl;
        Link* link = routingTable_[i].nextLink;
        if (packet_destAddress == routingTable_[i].destination) {
            std::cout << "Router #" << router->id() << ": forwarding packet (from: " << a.toString() << ", to: " << b.toString() << ", " << (int)c.size() << " bytes)" << std::endl;
            link->send(packet, router); // (router -> link)
            return;
        }
    }
    std::cout << "Router #" << router->id() << ": no route for packet (from: " << a.toString() << ", to: " << b.toString() << ", " << (int)c.size() << " bytes)" << std::endl;
}

void Router::received(Packet* packet) {
    send(packet);
}