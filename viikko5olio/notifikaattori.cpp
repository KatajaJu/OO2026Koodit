#include "notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori() {
    cout << "Notificator crated" << endl;
}

void Notifikaattori::lisaa(Seuraaja *a)
{
    cout << "Notificator added follower " << a->getNimi() << endl;
    a->next = seuraajat;
    seuraajat = a;
}

void Notifikaattori::poista(Seuraaja *a)
{
    if (seuraajat == a){
        seuraajat = seuraajat->next;
        a->next = nullptr;
        cout << "Notificator removed follower " << a->getNimi() << endl;
        return;
    }
    Seuraaja* edellinen = seuraajat;
    Seuraaja* nykyinen = seuraajat->next;

    while (nykyinen != nullptr){
        if (nykyinen == a){
            edellinen->next = nykyinen->next;
            a->next = nullptr;
            cout << "Notificator removed follower " << a->getNimi() << endl;
            return;
        }
        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::tulosta()
{
    cout << "Notificator followers:" << endl;
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr){
        cout << "Follower " << nykyinen->getNimi() << endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(string viesti)
{
    cout << "Notificator send message: " << viesti << endl;
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr){
        nykyinen->getNimi();
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
