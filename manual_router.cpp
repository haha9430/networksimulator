#include "manual_router.h"

void ManualRouter::addRoutingEntry(const Address &destination, Link *nextLink) {
    RoutingEntry re(destination, nextLink);
    routingTable_.push_back(re);
}