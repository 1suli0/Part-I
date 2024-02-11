#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int num1 = 0, num2 = 0, num3 = 0;
    int tries = 0;

    while (true) {
        num3 = num2;
        num2 = num1;
        num1 = rand() % 14 + 1; // Generate a random number between 1 and 14
        tries++;

        if (num1 - num2 == 5 && num2 - num3 == 5) {
            std::cout << "It took " << tries << " tries to get three numbers with a difference of 5.\n";
            std::cout << "The numbers are " << num3 << ", " << num2 << ", and " << num1 << ".\n";
            break;
        }
    }
    return 0;
}