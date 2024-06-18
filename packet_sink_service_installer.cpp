#include "packet_sink_service_installer.h"

PacketSinkService* PacketSinkServiceInstaller::install(Host *host, short port) {
    PacketSinkService* pss = new PacketSinkService(host, port);
    ServiceInstaller::install(host, pss);

    return pss;
}