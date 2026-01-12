#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum){

    int randonNum = rand() % maxnum + 1;
    int guessCount;
    int guess;

    while(1){
        cout << "Guess a number" << endl;
        cin >> guess;
        if (guess < randonNum){
            cout << "Too low" << endl;
            guessCount++;
        }
        else if (guess > randonNum ){
            cout << "Too high" << endl;
            guessCount++;
        }
        else{
            cout << "Correct" << endl;
            guessCount++;
            return guessCount;
        }
    }
}

int main()
{
    int max;
    cout << "Give maximum number:" << endl;
    cin >> max;
    int guessCount = game(max);
    cout << "Number of guesses " << guessCount << endl;
    return 0;
}
