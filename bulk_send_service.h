#ifndef BULK_SEND_SERVICE_H
#define BULK_SEND_SERVICE_H

#include "host.h"
#include "service.h"
#include "simulator.h"

#define PACKET_SIZE 512

class BulkSendService : Service {
  friend class BulkSendServiceInstaller;

private:
  Address destAddress_;
  short destPort_;
  double delay_;
  double startTime_;
  double stopTime_;
  BulkSendService(Host *host, Address destAddress, short destPort,
                  double delay = 1, double startTime = 0,
                  double stopTime = 10.0) : 
                  Service(host, destPort),  delay_(delay), startTime_(startTime), stopTime_(stopTime), destAddress_(destAddress), destPort_(destPort) {}
public:
  void send(std::string message) override;
  void received(Packet* packet) override;
};

#endif

// 시작시간 ~ 정지시간까지 딜레이마다 512바이트의 패킷을 전송하는 서비스
// 아무 대문자나 512개 char배열로 할 것