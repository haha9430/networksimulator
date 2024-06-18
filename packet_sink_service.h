#ifndef PACKET_SINK_SERVICE_H
#define PACKET_SINK_SERVICE_H

#include "service.h"
#include "packet.h"
#include <string>

class PacketSinkService : public Service {
  friend class PacketServiceInstaller;
  
private:
  int bytes_;
  PacketSinkService(Host *host, short port) : Service(host, port), bytes_(0) {}
public:
  void send(std::string message) override;
  void received(Packet* packet) override;
  int byte() { return bytes_; }
};

#endif

// 패킷을 받아 누적시켜 총 바이트 수를 출력하는 서비스
// 메시지 서비스 혹은 에코 서비스에서 패킷을 받고 서비스를 탐색하여 해당 서비스를 발견하면
// 해당 서비스의 함수 호출하여 바이트 수를 저장
// 해당 서비스의 함수는 패킷을 받아 바이트 수를 저장하고 출력하는 기능