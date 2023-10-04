#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteAtIndex(Node*& head, int index) {
    if (head == nullptr) {
        std::cerr << "Linked list is empty. Cannot delete from an empty list." << std::endl;
        return;
    }

    if (index < 0) {
        std::cerr << "Invalid index. Index should be non-negative." << std::endl;
        return;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    int currentIndex = 0;

    while (temp != nullptr && currentIndex < index - 1) {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        std::cerr << "Invalid index. Index exceeds the length of the list." << std::endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; ++i) {
        insertAtEnd(head, i);
    }

    std::cout << "Linked List before deletion: ";
    display(head);

    // Delete a node at index 2 (0-based index)
    deleteAtIndex(head, 2);

    std::cout << "Linked List after deletion at index 2: ";
    display(head);

    // Delete a node at index 7 (invalid index)
    deleteAtIndex(head, 7);

    return 0;
}

