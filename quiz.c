
#include <stdio.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 10

int main(void) {

    int score;
    int correct;
    int wrong;
    char answer;
    char playAgain;

    char questions[TOTAL_QUESTIONS][150] = {
        "1. Which keyword is used to declare an integer variable?",
        "2. Which format specifier is used for an integer in printf()?",
        "3. Which operator is used to get the address of a variable?",
        "4. Which statement is used to make a decision?",
        "5. Which symbol is used to access a value through a pointer?",
        "6. Which loop is commonly used when the number of iterations is known?",
        "7. What is the correct way to declare an array of 5 integers?",
        "8. Which keyword is used to return a value from a function?",
        "9. Which operator is used for logical AND?",
        "10. What is the index of the last element in an array of 5 elements?"
    };

    char options[TOTAL_QUESTIONS][4][80] = {
        {"A. int", "B. float", "C. char", "D. string"},
        {"A. %c", "B. %f", "C. %d", "D. %s"},
        {"A. *", "B. &", "C. %", "D. #"},
        {"A. for", "B. break", "C. continue", "D. if"},
        {"A. &", "B. %", "C. *", "D. #"},
        {"A. for loop", "B. if statement", "C. switch", "D. goto"},
        {"A. int arr;", "B. array int[5];", "C. int arr(5);", "D. int arr[5];"},
        {"A. void", "B. return", "C. break", "D. goto"},
        {"A. ||", "B. !", "C. &&", "D. =="},
        {"A. 5", "B. 4", "C. 0", "D. 1"}
    };

    char answers[TOTAL_QUESTIONS] = {
        'A', 'C', 'B', 'D', 'C',
        'A', 'D', 'B', 'C', 'B'
    };

    do {
        score = 0;
        correct = 0;
        wrong = 0;

        printf("\n====================================\n");
        printf("           C QUIZ GAME\n");
        printf("====================================\n");
        printf("Rules:\n");
        printf("1. There are %d questions.\n", TOTAL_QUESTIONS);
        printf("2. Each correct answer earns 1 point.\n");
        printf("3. There is no negative marking.\n");
        printf("====================================\n");

        for (int i = 0; i < TOTAL_QUESTIONS; i++) {

            printf("\n%s\n", questions[i]);

            for (int j = 0; j < 4; j++) {
                printf("%s\n", options[i][j]);
            }

            char input[100];

            while (1) {
                printf("Enter your answer (A/B/C/D): ");

                if (fgets(input, sizeof(input), stdin) == NULL) {
                    printf("\nInput error. Exiting game.\n");
                    return 1;
                }

                if (input[0] != '\n' &&
                    (input[1] == '\n' || input[1] == '\0')) {

                    answer = (char)toupper((unsigned char)input[0]);

                    if (answer >= 'A' && answer <= 'D') {
                        break;
                    }
                }

                printf("Invalid input! Enter only one letter: A, B, C or D.\n");
            }

            if (answer == answers[i]) {
                printf("Correct answer!\n");
                score++;
                correct++;
            } else {
                printf("Wrong answer! Correct option: %c\n", answers[i]);
                wrong++;
            }

            printf("Current score: %d/%d\n", score, i + 1);
        }

        printf("\n====================================\n");
        printf("             QUIZ RESULT\n");
        printf("====================================\n");
        printf("Total Questions : %d\n", TOTAL_QUESTIONS);
        printf("Correct Answers : %d\n", correct);
        printf("Wrong Answers   : %d\n", wrong);
        printf("Final Score     : %d/%d\n", score, TOTAL_QUESTIONS);
        printf("Percentage      : %.2f%%\n",
               (score * 100.0) / TOTAL_QUESTIONS);

        if (score <= 3) {
            printf("Performance: Keep practising!\n");
        } else if (score <= 6) {
            printf("Performance: Good effort!\n");
        } else if (score <= 8) {
            printf("Performance: Great job!\n");
        } else {
            printf("Performance: Excellent!\n");
        }

        printf("====================================\n");

        while (1) {
            printf("Would you like to play again? (Y/N): ");

            if (scanf(" %c", &playAgain) != 1) {
                printf("\nInput error. Exiting quiz.\n");
                return 1;
            }

            playAgain = (char)toupper((unsigned char)playAgain);

            if (playAgain == 'Y' || playAgain == 'N') {
                break;
            }

            printf("Please enter Y or N.\n");
        }

        
        if (playAgain == 'Y') {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                ;
            }
        }

    } while (playAgain == 'Y');

    printf("\nThank you for playing C Quiz Game!\n");

    return 0;
}
