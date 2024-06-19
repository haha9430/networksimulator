#include "link_installer.h"

Link* LinkInstaller::install(Node *a, Node *b, double delay) {
    Link* L = new Link(a, b, delay);
    a->addLink(L);
    b->addLink(L);
    return L;
}