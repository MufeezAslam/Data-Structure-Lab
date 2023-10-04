#include <iostream>

struct Node {
    int data;
    Node* next;
};
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    return newNode;
}


void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

}

int main() {
    Node* head = nullptr;

   
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 7);

  
    std::cout << "Linked list: ";
    display(head);

    return 0;
}

