#include "packet_sink_service.h"

void PacketSinkService::send(std::string message) {
    return;
}

void PacketSinkService::received(Packet* packet) {
    std::vector<char> data = packet->data();
    bytes_ += (int)data.size();
    return;
}