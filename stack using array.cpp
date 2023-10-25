#include <iostream>
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << value << " pushed onto the stack." << std::endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        } else {
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            std::cout << value << " popped from the stack." << std::endl;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display the elements in the stack
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
        } else {
            Node* current = top;
            std::cout << "Stack elements: ";
            while (current != NULL) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Stack stack;

    int choice, value;
    
    while (true) {
        std::cout << "Stack Operations:" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.display();
                break;

            case 4:
                exit(0);

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

