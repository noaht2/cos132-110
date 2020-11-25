#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int top = -1;

bool isempty() { // checks wether is empty or not
  if(top==-1)
  return true;
  else
  return false;
}

void push(int value) { // adds to stack
  if(top==SIZE-1) {    
    cout<<"Stack is full!\n";
  } else {
    top++;
    A[top]=value;
  }
}

void pop() { // removes from stack
 if(isempty())
  cout<<"Stack is empty!\n";
 else
  top--;
}

void show_top() { // shows top most element in stack
 if(isempty())
  cout<<"Stack is empty!\n";
 else
  cout<<"Element at top is: "<<A[top]<<"\n";

}

void displayStack() {
  if(isempty()) {
    cout<<"Stack is empty!\n";
 } else {
  for(int i=0 ; i<=top; i++)
    cout<<A[i]<<" ";
   cout<<"\n";
  }
}

int main() {

}
