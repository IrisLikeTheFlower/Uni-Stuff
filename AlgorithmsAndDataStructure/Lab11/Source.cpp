#include <iostream>
#include <string>
#include <sstream>

#include "AVLTree.h"

int main() {
    AVLTree tree;

    std::cout << "Enter numbers (press Enter twice to finish):" << std::endl;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty())
            break;

        std::istringstream iss(line);
        std::string number;
        while (iss >> number) {
            int input = std::stoi(number);
            tree.insert(input);
        }
    }

    tree.printTree();

    system("pause");

    while (true) {
        system("cls");
        std::cout << "Next Step?\n\n1. Add element;\n2. Remove element\n3. Print elements\n4. Print tree\n5. Search element\n6. Clear tree\n7. End\n\n";

        int input;
        std::cin >> input;
        int data;

        switch (input) {
        case 1:
            std::cout << "Enter data: ";
            std::cin >> data;
            tree.insert(data);
            break;
        case 2:
            std::cout << "Enter data to be removed: ";
            std::cin >> data;
            tree.remove(data);
            break;
        case 3:
            tree.inorderTraversal();
            system("pause");
            break;
        case 4:
            tree.printTree();
            system("pause");
            break;
        case 6:
            tree.clear();
            break;
        case 5:
            std::cout << "Enter data: ";
            std::cin >> data;
            if (tree.search(data)) {
                std::cout << "\nElement is in the tree";
            }
            else {
                std::cout << "\nElement is not in the tree";
            }
            system("pause");
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid input. Please enter a number between 1 and 7\n";
            system("pause");
        }
    }

    return 0;
}
