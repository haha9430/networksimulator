#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"

class Host;

class Service {
  friend class ServiceInstaller;

protected:
  // 서비스가 설치된 호스트
  Host *host_;

  // 서비스가 사용하는 포트
  short port_;
  // 
  //static short nextPort_;
  Service(Host *host, int port) : host_(host), port_(port) {}

public:
  short returnPort();
  // 호스트의 서비스 목록에서
  virtual void send(std::string message);
  virtual void received(Packet *packet);
  void nextPort();
};

#endif