#include "message_service_installer.h"

short MessageServiceInstaller::port_ = 1000;

MessageService* MessageServiceInstaller::install(Host *host) {
    // 메시지 서비스 객체 선언
    MessageService* ms = new MessageService(host, port_, destAddress_, destPort_);
    // 메시지 서비스 설치
    ServiceInstaller::install(host, ms);

    return ms;
}