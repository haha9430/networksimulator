#include "echo_service_installer.h"

EchoService* EchoServiceInstaller::install(Host *host) {
    // 에코 서비스 객체 선언
    EchoService* es = new EchoService(host, listenPort_);
    // 에코 서비스 설치
    ServiceInstaller::install(host, es);

    return es;
}