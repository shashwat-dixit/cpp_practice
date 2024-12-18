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

class PriorityQueue : public Heap
{
protected:
    bool compare(int a, int b) const override
    {
        return a > b;
    }

public:
    PriorityQueue() {};
};

int main()
{
    PriorityQueue pq;

    std::cout << "Inserting elements: 5, 2, 7, 1, 9\n";
    pq.push(5);
    pq.push(2);
    pq.push(7);
    pq.push(1);
    pq.push(9);
    // pq.pop();

    // Test removal and display
    std::cout << "\nRemoving elements in priority order:\n";
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";

    return 0;
}
