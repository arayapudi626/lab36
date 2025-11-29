#include <iostream>
#include <string>
#include <fstream>
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
    int choice;

    //tree.displayInOrder();

    //menu
    cout << "=====MENU=====" << endl;
    cout << "1. Display codes" << endl;
    cout << "2. Insert a code" << endl;
    cout << "3. Delete a code" << endl;
    cout << "4. Search for a code" << endl;
    cout << "5. Modify code" << endl;

    switch(choice) {
        case 1:
        cout << "\nCodes displayed in order" << endl;
        tree.displayInOrder();

        case 2:
        cout << "Enter a code to insert" << endl;
        cin >> code;
        tree.insertNode(code);

        case 3:
        cout << "Enter a code to delete" << endl;
        cin >> code;
        tree.remove(code);

        case 4:
        cout << "Enter code to search" << endl;
        cin >> code;
        if (tree.searchNode(code)){
            cout << "Found!\n";
        }
        else {
            cout << "Not found" << endl;
        }

        case 5:
        cout << "Enter a code to delete" << endl;
        cin >> code;
        tree.remove(code);

        cout << "Enter a new code" << endl;
        cin >> newCode;
        tree.insertNode(newCode);
        cout << "Modifie"
    }
return 0;
}
