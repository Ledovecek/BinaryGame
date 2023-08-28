#include <iostream>
#include <bitset>
#include <random>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

using namespace std;

void clearConsole();

static bool INGAME = true;

int main() {
    int streak = 0;

    while (INGAME) {
        clearConsole();
        cout << BLUE << "[PLAY UNTIL YOU HAVE CORRECT ANSWERS]" << RESET << endl;
        cout << "Streak: " << GREEN << streak << RESET << "\n\n" << endl;

        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dis(0, 255);

        int randomNumber = dis(gen);

        string userAnswer;
        cout << YELLOW << "[CONVERT THIS NUMBER TO BINARY] " << RESET << endl;
        cout << BLUE << "[" + to_string(randomNumber) + "]" << RESET << endl;

        cout << GREEN << "Answer: " << RESET << endl;
        cin >> userAnswer;

        string correctAnswer = bitset<8>(randomNumber).to_string();

        if (correctAnswer == userAnswer) {
            cout << "CORRECT" << endl;
            streak++;
            clearConsole();
        } else {
            clearConsole();
            cout << RED << "No. Answer is " << correctAnswer << RESET << endl;
            cout << YELLOW <<  "[STREAK] " << streak << RESET << endl;
            INGAME = false;
        }
    }
    return 0;
}

void clearConsole() {
    for (int i = 0; i < 100; ++i) {
        std::cout << std::endl;
    }
}
