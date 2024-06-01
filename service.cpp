#include "service.h"

short Service::returnPort() {
    return port_;
}

void Service::send(std::string message) {
    std::cout << "Service send" << std::endl;
}
void Service::received(Packet *packet) {
    std::cout << "node received" << std::endl;
}