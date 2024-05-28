#ifndef ECHO_SERVICE_H
#define ECHO_SERVICE_H

#include "host.h"
#include "service.h"
#include <iostream>
#include <string>

// 수신한 패킷을 전송자에게 다시 전송하는 서비스
class EchoService : public Service {
  friend class EchoServiceInstaller;

private:
  EchoService(Host *host, short port) : Service(host, port) {}
public:
  // 메시지를 담은 패킷을 받고 반송한다.
  void received(Packet *packet) {
    // 전송자 주소 -> 수신자 주소
    Address destAddress = packet->srcAddress();
    // 전송자 포트 -> 수신자 포트
    short destPort = packet->srcPort();
    // 메시지
    std::string message = packet->dataString();
    Packet* p = new Packet(Service::host_->address(), destAddress, Service::port_, destPort, message);
    Service::host_->send(p); // (service -> host)
  }
};

#endif