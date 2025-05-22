#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int gameDif; // Declare an integer variable to store the input
    
    printf("Please select a difficulty level:\n");
    printf("1: Easy (1-25)\n");
    printf("2: Medium (1-50)\n");
    printf("3: Hard (1-100)\n");
    printf("Enter your choice (1-3): ");

    // Validate difficulty input
    while (scanf("%d", &gameDif) != 1 || (gameDif < 1 || gameDif > 3)) {
        printf("Invalid input. Please enter a number between 1 and 3: ");
        while (getchar() != '\n'); // Clear the invalid input buffer
    }
    // Call the game function, passing the selected difficulty
    game(gameDif); 
    return 0; // Main function returns after game finishes
}

int game(int difficultyLevel) { // gameDif (now named difficultyLevel) is passed as a parameter
    // Seed the random number generator
    char playAgain; // Declare playAgain
    int maxNumber;  // To store the upper limit for the secret number

    do{
        switch (difficultyLevel) { // Switch on the actual difficultyLevel value
            case 1: // Easy
                printf("You have selected Easy mode. Guess a number between 1 and 25.\n");
                maxNumber = 25;
                break;
            case 2: // Medium
                printf("You have selected Medium mode. Guess a number between 1 and 50.\n");
                maxNumber = 50;
                break;
            case 3: // Hard
                printf("You have selected Hard mode. Guess a number between 1 and 100.\n");
                maxNumber = 100;
                break;
            default:
                // This case should ideally not be reached if main validates input
                printf("Invalid difficulty level received. Exiting game round.\n");
                return 1; // Indicate an error or unexpected state
        }
        
        int secretNumber = rand() % maxNumber + 1; // Generates a number between 1 and maxNumber
        int guess;
        int attempts = 0;

        printf("Welcome to the Guessing Game!\n");
        printf("I'm thinking of a number between 1 and %d. Try to guess it.\n", maxNumber);

        do {
            printf("Enter your guess: ");
            while (scanf("%d", &guess) != 1 || guess < 1 || guess > maxNumber) {
                printf("Invalid input. Please enter a number between 1 and %d: ", maxNumber);
                while (getchar() != '\n'); // Clear the invalid input
            }
            attempts++;

            if (guess > secretNumber) {
                printf("Too high! Try again.\n");
            } else if (guess < secretNumber) {
                printf("Too low! Try again.\n");
            } else {
                printf("Congratulations! You guessed the number %d in %d attempts!\n", secretNumber, attempts);
            }
        } while (guess != secretNumber);

        // Ask the user if they want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain != 'y' && playAgain != 'Y') {
            printf("Thanks for playing! Goodbye!\n");
            break;
        }
    }
    while(playAgain == 'y' || playAgain == 'Y');
    return 0;
}
