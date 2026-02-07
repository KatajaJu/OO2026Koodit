#include <iostream>
#include "notifikaattori.h"
#include "seuraaja.h"

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();

    n.postita("Message");
    n.poista(&b);
    n.postita("Message");

    n.poista(&a);
    n.postita("Message");

    return 0;
}
