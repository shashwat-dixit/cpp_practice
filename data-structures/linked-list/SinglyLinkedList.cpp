#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList
{
private:
    Node<T> *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void pushFront(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        cout << "Added " << val << " to front" << endl; // Debug print
    }

    void pushBack(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (!head)
        {
            head = newNode;
            cout << "Added " << val << " to empty list" << endl; // Debug print
            return;
        }
        Node<T> *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
        cout << "Added " << val << " to back" << endl; // Debug print
    }
    // Reverse the list - O(n)
    void reverse()
    {
        Node<T> *prev = nullptr;
        Node<T> *current = head;
        Node<T> *next = nullptr;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Detect cycle - Floyd's Algorithm - O(n)
    bool hasCycle()
    {
        if (!head)
            return false;

        Node<T> *slow = head;
        Node<T> *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    void print()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node<T> *current = head;
        cout << "List contents: ";
        while (current)
        {
            cout << current->data;
            if (current->next)
            {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " -> nullptr" << endl;
    }

    int size()
    { // Added size function
        int count = 0;
        Node<T> *current = head;
        while (current)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    ~SinglyLinkedList()
    {
        while (head)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    SinglyLinkedList<int> list;

    cout << "Initial list state:" << endl;
    list.print();
    cout << "Size: " << list.size() << endl;

    cout << "\nAdding elements..." << endl;
    list.pushFront(2);
    list.print();

    list.pushFront(1);
    list.print();

    list.pushBack(3);
    list.print();

    cout << "\nFinal list state:" << endl;
    cout << "Size: " << list.size() << endl;
    list.print();

    list.hasCycle();
    list.reverse();
    list.print();

    return 0;
}