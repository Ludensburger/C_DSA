// Author: Ryu R. Mendoza
// Date: April 6, 2024

// Description: Main Driver program that displays a menu of options for the user to choose from and use the Data Structures.
// The user can select from the following options:
// 1. Dynamic Array List
// 2. Singly Linked List
// 3. Doubly Linked List
// 4. Exit

#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        // Display the main menu
        cout << "Main Menu" << endl;
        cout << "1. Dynamic Array List" << endl;
        cout << "2. Singly Linked List" << endl;
        cout << "3. Doubly Linked List" << endl;
        cout << "4. Hash Table" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the screen
        system("cls");

        // Based on user's choice, execute the corresponding program
        switch (choice) {
        case 1:
            cout << "Running Dynamic Array List program..." << endl;
            // Code to run the Dynamic Array List program
            system("\"C:\\Users\\hp\\Desktop\\Ryu Files\\Codes\\C-Programming\\CPP\\C_DataStructures\\DynamicArray\\main.exe\"");
            break;
        case 2:
            cout << "Running Singly Linked List program..." << endl;
            // Code to run the Singly Linked List program
            system("\"C:\\Users\\hp\\Desktop\\Ryu Files\\Codes\\C-Programming\\CPP\\C_DataStructures\\SinglyLinkedList\\main.exe\"");
            break;
        case 3:
            cout << "Running Doubly Linked List program..." << endl;
            // Code to run the Doubly Linked List program
            system("\"C:\\Users\\hp\\Desktop\\Ryu Files\\Codes\\C-Programming\\CPP\\C_DataStructures\\DoublyLinkedList\\main.exe\"");
            break;

        case 4:
            cout << "Running Hash Table program..." << endl;
            // Code to run the Hash Table program
            system("\"C:\\Users\\hp\\Desktop\\Ryu Files\\Codes\\C-Programming\\CPP\\C_DataStructures\\HashTable\\main.exe\"");
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

        // Wait for user to press Enter before clearing the screen and displaying the menu again
        cout << "Press Enter to continue...";
        cin.ignore(); // Ignore any previous newline characters in the input buffer
        cin.get();    // Wait for user to press Enter

        // Clear the screen before displaying the menu again
        system("cls");

    } while (choice != 5);

    return 0;
}