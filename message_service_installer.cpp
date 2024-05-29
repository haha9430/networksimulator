#include "message_service_installer.h"

MessageService* MessageServiceInstaller::install(Host *host) {
    // 메시지 서비스 객체 선언
    MessageService* ms = new MessageService(host, 0, destAddress_, destPort_);
    // 메시지 서비스 설치
    ServiceInstaller::install(host, ms);

    return ms;
}