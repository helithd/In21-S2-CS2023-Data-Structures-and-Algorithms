#include <iostream>
#include <chrono>
using namespace std;

class Stack {
    int capacity;
    int top;
    int* stack;

public:
    Stack(int max_size) {
        capacity = max_size;
        top = -1;
        stack = new int[capacity];
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            stack[top] = data;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            int data = stack[top];
            top--;
            return data;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }
    int stackTop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            return stack[top];
        }
    }


    void display() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << endl;
            }
        }
    }
    ~Stack() {
        delete[] stack; // Deallocate the memory allocated for the stack
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
