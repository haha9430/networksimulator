#include "service.h"

//short Service::nextPort_ = 1000;

short Service::returnPort() {
    return port_;
}

void Service::send(std::string message) {
    std::cout << "Service send" << std::endl;
}
void Service::received(Packet *packet) {
    std::cout << "node received" << std::endl;
}
void Service::nextPort() {
    port_ += 1;
}