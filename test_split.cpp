/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

// Helper function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list
    Node* myList = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr)))));
    
    // Displaying the original list
    std::cout << "Original List: ";
    printList(myList);

    // Initializing separate linked lists for odds and evens
    Node* oddsList = nullptr;
    Node* evensList = nullptr;

    // Calling the split function
    split(myList, oddsList, evensList);

    // Displaying the odd numbers list
    std::cout << "Odd Numbers List: ";
    printList(oddsList);

    // Displaying the even numbers list
    std::cout << "Even Numbers List: ";
    printList(evensList);

    // Clean up allocated memory
    delete myList;
    delete oddsList;
    delete evensList;

    return 0;
}

