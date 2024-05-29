#include "message_service.h"

// 메시지를 전송한다
void MessageService::send(std::string message) {
    Packet* p = new Packet(host_->address(), destAddress_, Service::port_, destPort_, message);
    Service::host_->send(p); // (service -> host)
}
// 메시지를 담은 패킷을 받는다
void MessageService::received(Packet *packet) {
    std::cout << "MessageService: receied";
    /*
    Host #1: received packet, destination port: 1000
    MessageService: received "Hello, world!" from 1:3000
    */
}