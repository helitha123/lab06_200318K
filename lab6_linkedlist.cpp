#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Define a node for the linked list
struct Node {
    int data;
    Node* next;
};

// Define a Stack class that uses a linked list
class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }
    ~Stack() {
        Node* p = top;
        while (top) {
            top = top->next;
            delete p;
            p = top;
        }
    }
    void push(int x);
    int pop();
    int stacktop();
    bool isEmpty();
    bool isFull();
    void display();
};

// Check if the stack is empty
bool Stack::isEmpty() {
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// Check if the stack is full (linked list implementation can't be full)
bool Stack::isFull() {
    return false;
}

// Add an element to the top of the stack
void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Stack Overflow!" << endl;
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Remove an element from the top of the stack
int Stack::pop() {
    int x = -1;
    if (top == nullptr) {
        cout << "Stack Underflow!" << endl;
    }
    else {
        x = top->data;
        Node* t = top;
        top = top->next;
        delete t;
    }
    return x;
}

// Get the element at the top of the stack
int Stack::stacktop() {
    if (top == nullptr) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    else {
        return top->data;
    }
}

// Display the contents of the stack
void Stack::display() {
    Node* p = top;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Stack s;

    // Push elements onto the stack
    auto start = high_resolution_clock::now();
    for (int i = 0 ; i <=10 ; i++)
    {
      s.push(rand());
    }
  
    s.display();
     for (int i = 0 ; i <=5 ; i++)
    {
      s.pop();
    }
  
    s.display();
   
    for (int i = 0 ; i <=4; i++)
    {
      s.push(rand());
    }
    s.display();





    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time :  " << duration.count() << " microseconds" << endl;

    // Pop elements from the stack
   
    // Check if stack is empty
    cout << "Stack is empty? " << boolalpha << s.isEmpty() << endl;

    // Display the contents of the stack
  

    return 0;
}
