#include "router.h"

void Router::send(Packet *packet) {
    // 패킷의 목적지 주소
    Address packet_destAddress = packet->destAddress();
    for (int i = 0; i < (int)routingTable_.size(); i++) {
        if (packet_destAddress == routingTable_[i].destination) {
            Link* link = routingTable_[i].nextLink;
            Node* router = this;
            Address a = packet->srcAddress();
            Address b = packet->destAddress();
            std::vector<char> c = packet->data();
            std::cout << "Router #" << router->id() << ": forwarding packet (from: " << a.toString() << ", to: " << b.toString() << ", " << (int)c.size() << " bytes)" << std::endl;
            link->send(packet, router); // (router -> link)
            return;
        }
    }
}

void Router::received(Packet *packet){
    send(packet);
}