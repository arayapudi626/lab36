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
        tree.insertNode(code);

        case 3:
        cout << ""
    }
return 0;
}
