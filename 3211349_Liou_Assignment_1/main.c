#include <stdio.h> //include standard i/o lib

int main() { //start of main program
    int secretNumber = 7;      // Number the player must guess
    int attempts;              // Tracks attempt count

    printf("Guess a number between 1 and 10.\n"); //prints to prompt user for input of 1>=int<=10

    for (attempts = 1; attempts <= 3; attempts++) { //

        int guess;  // Declared inside loop to reduce scope

        printf("Attempt %d/3. Enter your guess: ", attempts);

        // Check if input is a valid integer
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");

            // Clear invalid characters from input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;  // Skip this attempt
        }

        // Check range
        if (guess < 1 || guess > 10) {
            printf("Out of range! Enter a number between 1 and 10.\n");
            continue;
        }

        // Compare guess
        if (guess == secretNumber) {
            printf("Correct! You win!\n");
            break;  // Loop exits early → player won
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    // If loop finished all 3 attempts without breaking → player lost
    if (attempts > 3) {
        printf("You lose! The secret number was %d.\n", secretNumber);
    }

    return 0;
}
