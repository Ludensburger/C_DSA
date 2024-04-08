/*
Programmer: Ryu R. Mendoza
Date: February 4, 2024
Description: A CLOSED Hashing Data Structure that supports Linear and Quadratic Probing
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100

struct node {
    int elem;
    struct node *next;
};

void initializeArray(int array[MAX_ROWS][MAX_COLS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = 0;
        }
    }
}

void initializeOpenHash(struct node *openHash[MAX_ROWS], int row) {
    for (int i = 0; i < row; i++) {
        openHash[i] = NULL;
    }
}

void printOpenHash(struct node *openHash[MAX_ROWS], int row, int openDataCounter) {
    printf("Data Counter: %d\n", openDataCounter);
    for (int i = 0; i < row; i++) {
        struct node *curr = openHash[i];
        // Check if there is at least one node in the linked list at the current index
        if (curr) {
            // Print the index followed by a colon
            printf("%d: ", i);
            // Iterate through the linked list at the current index
            while (curr != NULL) {
                // Print the element of the current node
                printf("%d ", curr->elem);
                // If there is a next node, print an arrow
                if (curr->next != NULL) {
                    printf(" -> ");
                }

                // Move to the next node in the linked list
                curr = curr->next;
            }
        }

            // If there are no nodes in the linked list at the current index, print a null symbol
        else {
            printf("0\\");
        }

        // Move to the next line for the next index
        printf("\n");
    }
}

void printArray(int array[MAX_ROWS][MAX_COLS], int inputCounter, int col) {
    printf("Counter: %d\n", inputCounter);

    //  while-flag loop (iterates once) used for printing nested loop version of the array. READABLE.
    //  can also use nested for loop. kinda eh.

    //  int flag = 0;
    //  while (flag <= 0) {
    for (int j = 0; j < col; j++) {
        // print only the starting row, then print each data in the columns
        printf("%d ", array[0][j]);
    }

    printf("\n");
    //    flag = 1;
    //  }
}

// Exit Function
void ExitProgram() {
    printf("Thank you for using Hashing System.\n");
    exit(0);
}

int main() {
    int row, col, data;
    char op;

    printf("Welcome to Hashing System\n");

    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter column: ");
    scanf("%d", &col);

    if (row > MAX_ROWS || col > MAX_COLS) {
        printf("Error: Exceeded maximum rows or columns.\n");
        return 1;
    }

    int array[MAX_ROWS][MAX_COLS];
    struct node *openHash[MAX_ROWS];
    int inputCounter = 0;
    int closedDataCounter = 0;
    int openDataCounter = 0;

    initializeArray(array, row, col);
    initializeOpenHash(openHash, row);

    printf("[ !CAUTION: Do not input data that will equal with row/column in Quadratic Probing! ]\n");
    printf("L: Linear\n");
    printf("Q: Quadratic\n");
    printf("O: Open Hashing\n");

    do {
        int flag = 0;
        if (closedDataCounter == col * row || closedDataCounter == row || closedDataCounter == col) {
            printf("Hash table is full.\n");
            break;
        }

        printf("Op: ");
        scanf(" %c", &op);

        int hash;

        // handles Upper and Lower case characters
        if (op == 'L' || op == 'Q') {
            op = tolower(op);
        }

        switch (op) {
            case 'l':
                scanf("%d", &data);
                if (data == -1) {
                    ExitProgram();
                }

                hash = data % col;
                for (int i = 0; i < row; i++) {
                    int j = hash;

                    do {
                        if (array[i][j] == 0) {
                            array[i][j] = data;
                            flag = 1;
                            break;
                        }

                        j = (j + 1) % col;
                    } while (j != hash);
                }

                inputCounter++;
                printArray(array, inputCounter, col);
                if (flag) {
                    closedDataCounter++;
                }

                break;

            case 'q':
                flag = 0;
                scanf("%d", &data);

                if (data == -1) {
                    ExitProgram();
                }

                hash = data % col;
                printf("start hash%d\n", hash);

                for (int i = 0; i < row; i++) {
                    int j = hash; // Start with the initial hash
                    for (int k = 0; k <= col; k++) { // Iterate up to col times for collision handling
                        if (array[i][j] == 0) { // Slot is empty, insert data
                            array[i][j] = data;
                            flag = 1; // Mark as inserted
                            break; // Exit the loop after insertion

                        } else { // Handle collision
                            j = (hash + k * k); // Recalculate j using quadratic probing

//                            printf("k%d\n", k);
//                            printf("j%d\n", j);
//                            printf("hash%d\n", hash);
                            if (j > col) { // Check if j exceeds column bounds
                                j = (j * 2) % col; // Adjust j to stay within bounds
//                                printf("last j%d\n", j);

                            }
                        }
//                        printf("last k%d\n", k);
                    }
                    if (flag) {
                        break; // Exit the loop if data has been inserted
                    }
                }

                inputCounter++;
                printArray(array, inputCounter, col);
                if (flag) {
                    closedDataCounter++;
                }

                break;

            case 'o':

                scanf("%d", &data);

                if (data == -1) {
                    ExitProgram();
                }

                hash = data % col;

                struct node *newNode = (struct node *)malloc(sizeof(struct node));

                if (newNode == NULL) {
                    printf("Memory allocation failed.");
                    exit(1);
                }

                newNode->elem = data;
                newNode->next = NULL;

                // if that location has no value, or it is null, then create a new node there.
                if (openHash[hash] == 0 || openHash[hash] == NULL) {
                    openHash[hash] = newNode;
                } else {
                    struct node *curr = openHash[hash];
                    while (curr->next != NULL) {
                        curr = curr->next;
                    }

                    curr->next = newNode;
                }

                openDataCounter++;
                printOpenHash(openHash, row, openDataCounter);
                break;

            case 'x':

                printf("Exiting...\n");
                ExitProgram();
                break;

            default:
                printf("Invalid input.\n");
        }
    } while (op != 'x');

    return 0;
}
