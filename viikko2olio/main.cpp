#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    int max;
    cout << "Give maximum number: " << endl;
    cin >> max;
    Game game(max);
    game.play();
    return 0;
}
