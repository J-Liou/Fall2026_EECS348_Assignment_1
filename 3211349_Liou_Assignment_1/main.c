#include <stdio.h> //include standard i/o lib
#include <stdlib.h> //include standard lib for valid input check

int main() { //start of main program
    int secretNumber = 7;      // Number the player must guess
    int attempts;              // Tracks attempt count

    printf("Guess a number between 1 and 10.\n"); //prints to instruct user for input of 1>=int<=10

    for (attempts = 1; attempts <= 3; attempts++) { //start of for loop post incrementing from 1 to <=3

        int guess;  // Declared input inside loop to reduce scope

        printf("Attempt %d/3. Enter your guess: ", attempts); //prints current attempt and prompts user for input

        // Check if input is a valid integer
        char buffer[100]; //init buffer for input
        char dummy; //dummy char for trailing chars

        // Read full line and verify sscanf finds exactly one integer and zero trailing characters
        while (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d %c", &guess, &dummy) != 1) { //if dummy stores char, valid input check fails, or if fgets returns nothing
            printf("Invalid input! Please enter a number.\n"); //print invalid input msg
            printf("Attempt %d/3. Enter your guess: ", attempts); //print attempt line again
        } //end of input read

        // check input within range
        if (guess < 1 || guess > 10) { //guess between 1 and 10
            printf("Out of range! Enter a number between 1 and 10.\n"); //if not, prints error msg
            continue; //skips attempt
        } //end of range check if statement

        // Compare guess
        if (guess == secretNumber) { //if guess matches number
            printf("Correct! You win!\n"); //print win msg
            break;  // Loop exits early → player won
        } else if (guess < secretNumber) { //if guess<number 
            printf("Too low! Try again.\n"); //print too low msg
        } else { //if guess>number
            printf("Too high! Try again.\n"); //print too high msg
        } //end of else statement
    } //end of guess compare if statement

    // If loop finished all 3 attempts without breaking → player lost
    if (attempts > 3) { //if more than 3 attempts
        printf("You lose! The secret number was %d.\n", secretNumber); //print lose msg
    } //end of attempt check if statement

    return 0; //if program runs return 0
} //end of main program
