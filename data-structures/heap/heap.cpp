#include <iostream>
#include <vector>
class Heap
{
protected:
    std::vector<int> arr;
    // helper functions for index calculations
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    // pure virtual function to be implented in derived classes
    virtual bool compare(int a, int b) const = 0;

    void heapifyUp(int i)
    {
        while (i > 0 && compare(arr[i], arr[parent(i)]))
        {
            std::swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int extremeIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < int(arr.size()) && compare(arr[left], arr[extremeIndex]))
        {
            extremeIndex = left;
        }

        if (right < int(arr.size()) && compare(arr[right], arr[extremeIndex]))
        {
            extremeIndex = right;
        }

        if (i != extremeIndex)
        {
            std::swap(arr[i], arr[extremeIndex]);
            heapifyDown(extremeIndex);
        }
    }

public:
    bool empty() const { return arr.empty(); }
    int size() const { return arr.size(); }
    int top() const
    {
        if (empty())
            throw std::runtime_error("Heap is empty!");

        return arr[0];
    }

    void push(int value)
    {
        arr.push_back(value);
        heapifyUp(arr.size() - 1);
    }

    void pop()
    {
        if (empty())
            throw std::runtime_error("Heap is empty!");
        arr[0] = arr.back();
        arr.pop_back();
        if (!empty())
            heapifyDown(0);
    }

    void print() const
    {
        for (int x : arr)
        {
            std::cout << x << " " << std::endl;
        }
    }
};

class MaxHeap : public Heap
{
protected:
    bool compare(int a, int b) const override
    {
        return a > b;
    }

public:
    MaxHeap() {};
};

class MinHeap : public Heap
{
protected:
    bool compare(int a, int b) const override
    {
        return a < b;
    }

public:
    MinHeap() {};
};

void testHeap()
{
    std::cout << "Testing Max Heap:\n";
    MaxHeap maxHeap;

    std::cout << "Inserting: 4, 10, 3, 5, 1\n";
    maxHeap.push(4);
    maxHeap.push(10);
    maxHeap.push(3);
    maxHeap.push(5);
    maxHeap.push(1);

    std::cout << "Max Heap array representation: ";
    maxHeap.print();

    std::cout << "Removing elements from Max Heap:\n";
    while (!maxHeap.empty())
    {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << "\n\n";

    std::cout << "Testing Min Heap:\n";
    MinHeap minHeap;

    std::cout << "Inserting: 4, 10, 3, 5, 1\n";
    minHeap.push(4);
    minHeap.push(10);
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(1);

    std::cout << "Min Heap array representation: ";
    minHeap.print();

    std::cout << "Removing elements from Min Heap:\n";
    while (!minHeap.empty())
    {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;
}

int main()
{
    testHeap();
    return 0;
}
