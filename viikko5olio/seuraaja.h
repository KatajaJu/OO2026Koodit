#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>
using namespace std;

class Seuraaja
{
public:
    Seuraaja* next = nullptr;
    Seuraaja(string);
    string getNimi();
    void paivitys(string);

private:
    string nimi;
};

#endif // SEURAAJA_H
