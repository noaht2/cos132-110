#include <iostream>

using namespace std;


class LinkedList {
    struct Node {
        int data;
        Node *next;
    };
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }
    //~LinkedList();
    void appendNode(int); // adds to the end of the linked list
    void insertNode(int, int); // adds anywhere in the list
    void push(int); // adds it to the beginning of the list
    void addBack(int);
    void deleteNode(int);
    void deleteLastNode();
    void displayList() const;
    int getSize() const;
};

void LinkedList::appendNode(int element) {
    Node *newNode; // points to the new node
    Node *nodePtr; // to move through the list

    newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    // if there are no nodes in the list, it makes the newNode the first node
    if(!head) {
        head = newNode;
    } else { // else, adding it at the end of the list
        nodePtr = head;
        while(nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void LinkedList::deleteNode(int element) {
    Node *nodePtr;
    Node *prevNode;

    if(!head) {
        return;
    } else if(head->data == element) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        nodePtr = head;
        while((nodePtr != nullptr) && (nodePtr->data != element)) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr) {
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

int LinkedList::getSize() const {
    int tempCount = 0;
    Node *nodePtr = head;

    while(nodePtr) {
        nodePtr = nodePtr->next;
        tempCount++;
    }

    return tempCount;
}

void LinkedList::insertNode(int element, int index) {
    Node *prev = new Node;
    Node *curr = new Node;
    Node *newNode = new Node;
    newNode->data = element;

    int tempPos = 0;

    curr = head;

    if(head != nullptr) {
        while(curr->next != nullptr && tempPos != index) {
            prev = curr;
            curr = curr->next;
            tempPos++;
        }
        if(index == 0) {
            cout << "Adding at the head Function" << endl;
            push(element);
            return;
        } else if(curr->next == nullptr && index == tempPos) {
            cout << "Adding at End Function" << endl;
            addBack(element);
            return;
        } else if(index > tempPos+1) {
            cout << "Position is out of Bounds" << endl;
            //addBack(element);
            return;
        } else {
            prev->next = newNode;
            newNode->next = curr;
            cout << "Added node at position: " << index << endl;
        }
    } else {
        head = newNode;
        newNode->next = nullptr;
        cout << "Added at head as list is empty!" << endl;
    }
}

void LinkedList::deleteLastNode() {
    if(!head) {
        return;
    } else if(head->next == nullptr) {
        delete head;
    }

    Node *nodePtr;
    nodePtr = head;

    while(nodePtr->next->next != nullptr) {
        nodePtr = nodePtr->next;
    }
    delete(nodePtr->next);
    nodePtr->next = nullptr;
}

void LinkedList::push(int element) {
    Node *newNode = new Node;

    newNode->next = head;
    newNode->data = element;
    head = newNode;
}

void LinkedList::addBack(int element) {
    Node *newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    Node *nodePtr = head;

    if(head == nullptr) {
        head = newNode;
        return;
    }

    while(nodePtr->next != nullptr) {
        nodePtr = nodePtr->next;
    }

    nodePtr->next = newNode;
}

void LinkedList::displayList() const {
    Node *nodePtr;
    nodePtr = head;

    while(nodePtr) {
        cout << nodePtr->data << "\t";
        nodePtr = nodePtr->next;
    }

    cout << endl;
}


int main() {
    cout << "----- Linked List -----" << endl;
    LinkedList list;

    list.push(5);
    list.push(10);

    list.displayList();

    list.insertNode(20, 3);

    list.displayList();

    return 0;
}
