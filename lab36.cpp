#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "IntBinaryTree.h"
using namespace std;

void populate(IntBinaryTree &tree){
    ifstream fin("codes.txt");
    if (!fin){
        cout << "No text found" << endl;
    }
    string code;
    while (fin >> code){
        tree.insertNode(code);
    }
    cout << "Code loaded" << endl;
}

int main() {
    IntBinaryTree tree;
    populate(tree);
    string code;
    string newCode;
    int choice = 0;

    do {
        //menu
        cout << "=====MENU=====" << endl;
        cout << "1. Display codes" << endl;
        cout << "2. Insert a code" << endl;
        cout << "3. Delete a code" << endl;
        cout << "4. Search for a code" << endl;
        cout << "5. Modify code" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "\nCodes displayed in order" << endl;
                tree.displayInOrder();
                break;
            case 2:
                cout << "Enter a code to insert" << endl;
                cin >> code;
                tree.insertNode(code);
                cout << code << " entered!" << endl;
                break;
            case 3:
                cout << "Enter a code to delete" << endl;
                cin >> code;
                tree.remove(code);
                cout << code << " deleted!" << endl;
                break;
            case 4:
                cout << "Enter code to search" << endl;
                cin >> code;
                if (tree.searchNode(code)){
                    cout << "Found " << code << endl;
                }
                else {
                    cout << "Not found" << endl;
                }
                break;
            case 5:
                cout << "Enter a code to modify (will delete the old one)" << endl;
                cin >> code;
                tree.remove(code);

                cout << "Enter a new code" << endl;
                cin >> newCode;
                tree.insertNode(newCode);
                cout << "Modified!" << endl;
                break;
            case 6:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice, please select 1-6." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
