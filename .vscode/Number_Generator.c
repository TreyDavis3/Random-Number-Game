#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    char playAgain; // Declare playAgain

    do{
        srand(time(NULL));
        int secretNumber = rand() % 100 + 1; // Generates a number between 1 and 100
        int guess;
        int attempts = 0;

        printf("Welcome to the Guessing Game!\n");
        printf("I'm thinking of a number between 1 and 100. Try to guess it.\n");

        do {
            printf("Enter your guess: ");
            while (scanf("%d", &guess) != 1 || guess < 1 || guess > 100) {
                printf("Invalid input. Please enter a number between 1 and 100: ");
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
    }while(playAgain == 'y' || playAgain == 'Y');
    return 0;
}