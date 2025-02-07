#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void ticTacToe();
void numberGuessingGame();
void clearScreen();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ticTacToe();
                break;
            case 2:
                numberGuessingGame();
                break;
            case 3:
                printf("Exiting the game. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    clearScreen();
    printf("====================================\n");
    printf("           GAME HUB                \n");
    printf("====================================\n");
    printf("1. Play Tic-Tac-Toe\n");
    printf("2. Play Number Guessing Game\n");
    printf("3. Exit\n");
    printf("====================================\n");
}

// Function to implement Tic-Tac-Toe
void ticTacToe() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col, move = 0, player = 1;
    char mark;

    while (1) {
        clearScreen();
        printf("TIC-TAC-TOE\n");
        printf("Player 1: X   Player 2: O\n\n");

        // Display the board
        for (int i = 0; i < 3; i++) {
            printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
            if (i < 2) printf("\n---|---|---\n");
        }
        printf("\n");

        // Get player input
        printf("Player %d, enter your move (row [1-3] and column [1-3]): ", player);
        scanf("%d %d", &row, &col);

        // Adjust for 0-based indexing
        row--;
        col--;

        // Check if the cell is valid and empty
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            mark = (player == 1) ? 'X' : 'O';
            board[row][col] = mark;
            move++;

            // Check for win condition
            if ((board[0][0] == mark && board[0][1] == mark && board[0][2] == mark) ||
                (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark) ||
                (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark) ||
                (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark) ||
                (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark) ||
                (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark) ||
                (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
                (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
                clearScreen();
                printf("TIC-TAC-TOE\n");
                for (int i = 0; i < 3; i++) {
                    printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
                    if (i < 2) printf("\n---|---|---\n");
                }
                printf("\nPlayer %d wins!\n", player);
                break;
            }

            // Check for draw
            if (move == 9) {
                clearScreen();
                printf("TIC-TAC-TOE\n");
                for (int i = 0; i < 3; i++) {
                    printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
                    if (i < 2) printf("\n---|---|---\n");
                }
                printf("\nThe game is a draw!\n");
                break;
            }

            // Switch players
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    printf("Press Enter to return to the main menu...");
    getchar();  // Clear the buffer
    getchar();  // Wait for user input
}

// Function to implement Number Guessing Game (Non-AI Version)
void numberGuessingGame() {
    int target, guess, attempts = 0;

    clearScreen();
    printf("NUMBER GUESSING GAME\n");
    printf("Let's play a guessing game! Ask a friend to set a number between 1 and 100.\n");
    printf("Enter the target number (secret): ");
    scanf("%d", &target);

    clearScreen();
    printf("NUMBER GUESSING GAME\n");
    printf("Now, guess the number!\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > target) {
            printf("Too high! Try again.\n");
        } else if (guess < target) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }
    }

    printf("Press Enter to return to the main menu...");
    getchar();  // Clear the buffer
    getchar();  // Wait for user input
}

// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Linux/Mac
    #endif
}
