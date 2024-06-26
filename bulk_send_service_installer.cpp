#include "bulk_send_service_installer.h"

BulkSendService* BulkSendServiceInstaller::install(Host *host, Address destination, short destPort,
                                                    double delay = 1, double startTime = 0,
                                                    double stopTime = 10.) {
    BulkSendService* bss = new BulkSendService(host, destination, destPort, delay, startTime, stopTime);
    ServiceInstaller::install(host, bss);

    return bss;
}