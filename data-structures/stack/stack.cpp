#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack
{
private:
    T *arr;
    int capacity;
    int top;

public:
    ArrayStack(int size = 100)
    {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }
    ~ArrayStack()
    {
        delete[] arr;
    }

    void push(T value)
    {
        if (isFull())
        {
            throw std::overflow_error("Stack Overflow");
        }
        arr[++top] = value;
    }

    T pop()
    {
        if (isEmpty())
        {
            std::underflow_error("Stack Underflow");
        }

        return arr[top--];
    }
    T peek()
    {
        if (isEmpty())
        {
            std::underflow_error("Stack Underflow");
        }

        return arr[top];
    }

    // helper and utility functions
    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    int size()
    {
        return top + 1;
    }
};

template <typename T>
class DynamicStack
{
private:
    std::vector<T> stack;

public:
    void push(T value)
    {
        stack.push_back(value);
    }
    T pop()
    {
        if (isEmpty())
            throw std::overflow_error("Stack Underflow");
        T value = stack.back();
        stack.pop_back();
        return value;
    }

    // helper & utility functions
    T peek()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack Empty");
        }
        return stack.back();
    }

    bool isEmpty()
    {
        return stack.empty();
    }

    int size()
    {
        return stack.size();
    }
};

template <typename T>
class MinStack
{
private:
    std::vector<T> stack;
    std::vector<T> minStack;

public:
    void push(T value)
    {
        stack.push_back(value);
        if (minStack.empty() || value <= minStack.back())
        {
            minStack.push_back(value);
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack Underflow");
        }

        T value = stack.back();
        stack.pop_back();
        if (value == minStack.back())
        {
            minStack.pop_back();
        }
        return value;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack Underflow");
        }
        T value = stack.back();
        return value;
    }

    T getMin()
    {
        if (isEmpty())
            throw std::underflow_error("Stack Underflow!");
        return minStack.back();
    }

    bool isEmpty()
    {
        return stack.empty();
    }

    int size()
    {
        return stack.size();
    }
};

int main()
{
    ArrayStack<int> arrStack(5);
    arrStack.push(1);
    arrStack.push(2);
    arrStack.push(3);
    std::cout << "Array Stack top: " << arrStack.peek() << std::endl;
    std::cout << "Popped: " << arrStack.pop() << std::endl;

    DynamicStack<int> dynStack;
    dynStack.push(10);
    dynStack.push(20);
    dynStack.push(30);
    std::cout << "Dynamic Stack top: " << dynStack.peek() << std::endl;
    std::cout << "Popped: " << dynStack.pop() << std::endl;

    MinStack<int> minStack;
    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);
    std::cout << "Min Stack minimum: " << minStack.getMin() << std::endl;
    minStack.pop();
    std::cout << "Min Stack minimum after pop: " << minStack.getMin() << std::endl;

    return 0;
}
