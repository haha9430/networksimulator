#ifndef BULK_SEND_SERVICE_H
#define BULK_SEND_SERVICE_H

#include "host.h"
#include "service.h"
#include "simulator.h"

#define PACKET_SIZE 512

class BulkSendService : Service {
  friend class BulkSendServiceInstaller;

private:
  BulkSendService(Host *host, Address destAddress, short destPort,
                  double delay = 1, double startTime = 0,
                  double stopTime = 10.0);
};

#endif

// 시작시간 ~ 정지시간까지 딜레이마다 512바이트의 패킷을 전송하는 서비스
// 해당 시간마다 어떻게 전송을...?