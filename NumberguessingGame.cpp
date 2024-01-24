#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    std::time_t currentTime = std::time(0);
    
    std::srand(static_cast<unsigned int>(currentTime));
    
    int secretNumber = std::rand() % 100 + 1;     

    std::cout << "Welcome to the Guess the Number game!" << std::endl;
    
    std::cout << "I have chosen a number between 1 and 100. Try to guess it." << std::endl;
    
    std::cout << "You have to guess the correct number and you have umlimited chances." << std::endl;
    
    int userGuess;
    
    int attempts = 0;

    while (true) {
       
        std::cout << "Enter your guess: ";
        
        std::cin >> userGuess;
        
        attempts++;

        
        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << std::endl;
            break;
            
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try guessing a bigger number." << std::endl;
            
        } else {
            std::cout << "Too high! Try guessing a smaller number." << std::endl;
            
        }
    }

    return 0;
}








