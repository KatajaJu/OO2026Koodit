#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Game::Game(int maxNumber)
{
    numOfGuesses = 0;
    srand(time(NULL));
    randomNumber = (rand() % maxNumber) + 1;
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;

}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{

    while(true){
        cout << "Guess a number:" << endl;
        cin >> playerGuess;
        if (playerGuess < randomNumber){
            cout << "Guess is too low" << endl;
            numOfGuesses++;
        }
        else if (playerGuess > randomNumber ){
            cout << "Guess is too high" << endl;
            numOfGuesses++;
        }
        else{
            cout << "Correct" << endl;
            numOfGuesses++;
            printGameResult();
            break;
        }
    }
}

void Game::printGameResult()
{
    cout << "Number of guesses: " << numOfGuesses << endl;
}
