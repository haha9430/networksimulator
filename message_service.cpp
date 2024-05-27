#include "message_service.h"

void MessageService::send(std::string message) {
    Packet* p = new Packet(Service::host_->address(), destAddress_, destPort_, Service::port_, message);
    Service::host_->send(p); // (service -> host)
}

void MessageService::received(Packet *packet) {
    
    
    std::cout << "MessageService: receied";
    /*
    Host #1: received packet, destination port: 1000
    MessageService: received "Hello, world!" from 1:3000
    */
}