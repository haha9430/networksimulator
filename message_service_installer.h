#ifndef PING_SERVICE_INSTALLER_H
#define PING_SERVICE_INSTALLER_H

#include "address.h"
#include "message_service.h"
#include "service_installer.h"

class MessageServiceInstaller : public ServiceInstaller {
private:
  // 목적지 주소
  Address destAddress_;
  // 목적지 포트
  short destPort_;
  // 메시지 서비스 포트
  short port_;
  // 다음 메시지 서비스 포트
  static short nextPort_; 
public:
  MessageServiceInstaller(const Address &destAddress, short destPort)
      : destAddress_(destAddress), destPort_(destPort), port_(nextPort_++) {}
//
  // 호스트에 MessageService를 설치한다
  MessageService *install(Host *host);
};

#endif