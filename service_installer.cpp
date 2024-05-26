#include "service_installer.h"

void ServiceInstaller::install(Host *host, Service *service) {
    // host의 services_에 service를 추가
    host->services_.push_back(service);
}