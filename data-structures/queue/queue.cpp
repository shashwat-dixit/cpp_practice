#include <iostream>

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    };

    void enqueue(int val)
    {
        if (isFull())
        {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }

        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[front];
    }

    bool isFull()
    {
        return size == capacity;
    }
    int getSize()
    {
        return size;
    }

    ~Queue()
    {
        delete[] arr;
    };
};
void printQueue(Queue &q)
{
    Queue temp(q.getSize()); // Temporary queue for demonstration
    std::cout << "Queue contents: ";

    while (!q.isEmpty())
    {
        int value = q.dequeue();
        std::cout << value << " ";
        temp.enqueue(value);
    }

    // Restore original queue
    while (!temp.isEmpty())
    {
        q.enqueue(temp.dequeue());
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "\nExample 1: Basic Queue Operations\n";
    Queue q1(5);

    std::cout << "Enqueuing elements: 1, 2, 3, 4, 5\n";
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);

    printQueue(q1);

    std::cout << "Front element: " << q1.peek() << std::endl;
    std::cout << "Dequeuing two elements\n";
    q1.dequeue();
    q1.dequeue();
    printQueue(q1);

    // Example 2: Process Simulation
    std::cout << "\nExample 2: Process Simulation\n";
    Queue processQueue(4);
    std::cout << "Adding processes with IDs: 101, 102, 103, 104\n";
    processQueue.enqueue(101);
    processQueue.enqueue(102);
    processQueue.enqueue(103);
    processQueue.enqueue(104);

    std::cout << "Processing tasks...\n";
    while (!processQueue.isEmpty())
    {
        int currentProcess = processQueue.dequeue();
        std::cout << "Processing task ID: " << currentProcess << std::endl;
    }

    // Example 3: Handling Queue Overflow and Underflow
    std::cout << "\nExample 3: Handling Queue Limits\n";
    Queue q3(3);

    std::cout << "Trying to enqueue 4 elements into queue of size 3:\n";
    q3.enqueue(1);
    q3.enqueue(2);
    q3.enqueue(3);
    q3.enqueue(4); // Should show queue is full

    printQueue(q3);

    std::cout << "Dequeuing all elements:\n";
    q3.dequeue();
    q3.dequeue();
    q3.dequeue();
    std::cout << "Trying to dequeue from empty queue:\n";
    q3.dequeue(); // Should show queue is empty

    // Example 4: Circular Queue Behavior
    std::cout << "\nExample 4: Circular Queue Behavior\n";
    Queue circularQ(3);

    std::cout << "First round:\n";
    circularQ.enqueue(1);
    circularQ.enqueue(2);
    circularQ.enqueue(3);
    printQueue(circularQ);

    std::cout << "Dequeue two elements:\n";
    circularQ.dequeue();
    circularQ.dequeue();

    std::cout << "Enqueue new elements:\n";
    circularQ.enqueue(4);
    circularQ.enqueue(5);
    printQueue(circularQ);

    return 0;
}
