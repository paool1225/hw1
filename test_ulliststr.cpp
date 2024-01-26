#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    // Create an instance of ULListStr
    ULListStr myList;

    // Push some elements to the back of the list
    myList.push_back("World");
    myList.push_back("!");

    // Push some elements to the front of the list
    myList.push_front("Hello");

    // Output the size of the list
    std::cout << "Size of the list: " << myList.size() << std::endl;

    // Output the elements of the list
    std::cout << "Front element: " << myList.front() << std::endl;
    std::cout << "Back element: " << myList.back() << std::endl;

    // Pop elements from the front and back of the list
    myList.pop_front();
    myList.pop_back();

    // Check if the list is empty
    if (myList.empty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }

    return 0;
}