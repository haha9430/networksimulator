#include "link_installer.h"

Link* LinkInstaller::install(Node *a, Node *b) {
    Link* L = new Link(a, b);
    a->addLink(L);
    b->addLink(L);
    return L;
}