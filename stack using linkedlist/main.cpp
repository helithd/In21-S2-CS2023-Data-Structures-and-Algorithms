#include <iostream>
using namespace std;

class Node {
public:
    int data; // Data to be stored in the node
    Node* next; // Pointer to the next node in the linked list

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
    Node* top; // Pointer to the top node of the stack

public:
    Stack(int i) {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Return -1 to indicate an error
        }
        else {
            int data = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return data;
        }
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Return -1 to indicate an error
        }
        else {
            return top->data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
    ~Stack() {
        while (!isEmpty()) {
            pop(); // Deallocate the memory for all the nodes in the stack
        }
    }

};

int main() {
    int max_size;
    cout << "Enter the maximum size of the stack: ";
    cin >> max_size;

    Stack s(max_size);

    auto start = chrono::high_resolution_clock::now();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display(); // Stack Overflow
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto end = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Time taken is: " << time_taken << " nanoseconds" << endl;


    return 0;
}