#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};

Node* head = nullptr;
void insert(int newdata) {
   Node *newnode = new Node;
   Node *ptr = head;
   newnode->data = newdata;
   newnode->next = head;
   if (head!= nullptr) {
      while (ptr->next != head)
      ptr = ptr->next;
      ptr->next = newnode;
   } else
   newnode->next = newnode;
   head = newnode;
}
void display() {
   Node* ptr;
   ptr = head;
   do {
      cout<<ptr->data <<" ";
      ptr = ptr->next;
   } while(ptr != head);
}
int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The circular linked list is: ";
   display();
   return 0;
}
