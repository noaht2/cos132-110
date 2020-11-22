#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};
Node *top = NULL;

bool isEmpty() {
if(top == NULL)
  return true;
else
  return false;
}

void push(int value) {
  Node *ptr = new Node();
  ptr->data = value;
  ptr->next = top;
  top = ptr;
}

void pop() {
  if(isEmpty()) {
    cout << "Stack is Empty" << endl;
  } else {
    Node *ptr = top;
    top = top->next;
    cout << "Deleted: " << ptr->data << endl;
    delete(ptr);
  }
}

void showTop() {
  if(isEmpty()) {
    cout << "Stack is Empty" << endl;
  } else {
    cout << "Top Element" << top->data << endl;
  }
}

int main() {
  push(1);
  push(2);
  pop();

  return 0;
}
