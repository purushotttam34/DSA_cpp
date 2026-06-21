#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        cout << top->data << " popped from stack." << endl;

        top = top->next;
        delete temp;
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        cout << "Stack elements are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
