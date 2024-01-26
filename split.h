#ifndef SPLIT_H
#define SPLIT_H

// Declaration of the Node structure
struct Node 
{
  int value;
  Node* next;

  // Initializing constructor
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

// Function prototype for the split function
void split(Node*& in, Node*& odds, Node*& evens);

#endif
