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
  // 받은 메시지를 반송한다
  void send(std::string message) {};
  // 메시지를 담은 패킷을 받는다
  void received(Packet *packet) {};
};

#endif