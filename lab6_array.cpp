#include <iostream>
#include <chrono>
#define MAX_SIZE 100
using namespace std::chrono;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() { // Constructor to initialize top as -1
        top = -1;
    }

    bool push(int x) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return false;
        }
        else {
            arr[++top] = x;
            std::cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return 0;
        }
        else {
            int x = arr[top--];
            return x;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    int stacktop() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else {
            int x = arr[top];
            return x;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
        }
        else {
            std::cout << "Stack Elements: ";
            for (int i = top; i >= 0; i--) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Stack s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.display();
    // std::cout << s.pop() << " popped from stack\n";
    // std::cout << "Top element is " << s.stacktop() << std::endl;
    // s.display();
    // return 0;



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
    std::cout << "Execution time :  "<< duration.count() << " microseconds" << std::endl;
}
