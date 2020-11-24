#include <iostream>
using namespace std;
struct Node {
   int data;
   Node *next;
};

Node* head = nullptr;

int list_size() {
  Node *current = nullptr;
   int size = 0;
   
   if(head==NULL) {
      printf("List size : %d ", size);
      return 0;
   } 

   current = head;
   size = 1;

   while(current->next != head) {
      current = current->next;
      size++;
   }

   return size;  
}

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

void getHead() {
  cout << head->data << endl;
}

void getFirstNode() {
  Node *nodePtr;
  nodePtr = head;
  
  int size = list_size();
  for(int i = 0; i < size-1; i++) {
    nodePtr = nodePtr->next;
  }
  cout << nodePtr->data << endl;
}

int main() {
  insert(3);
  insert(1);
  insert(7);
  insert(2);
  insert(9);
  getFirstNode();
   return 0;
}
