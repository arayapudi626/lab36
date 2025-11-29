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
return 0;
}
