#include <iostream>
#include <unordered_set>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *prev;
    Node *next;

    Node(T val) : data(val), prev(nullptr), next(nullptr) {};
    /* data */
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {};

    void pushFront(T val)
    {
        Node<T> *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void pushBack(T val)
    {
        Node<T> *newNode = new Node(val);
        if (!tail)
        {
            head = tail = newNode;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void popFront()
    {
        if (!head)
            return;
        Node<T> *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void popBack()
    {
        if (!tail)
            return;
        Node<T> *temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }

    void printForward()
    {
        Node<T> *current = head;
        while (current)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void printBackward()
    {
        Node<T> *current = tail;
        while (current)
        {
            cout << current->data << "->";
            current = current->prev;
        }
        cout << "nullptr" << endl;
    }
    ~DoublyLinkedList()
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
    cout << "\nDoubly Linked List Demo:" << endl;
    DoublyLinkedList<int> dll;
    dll.pushFront(3);
    dll.pushFront(2);
    dll.pushFront(1);
    dll.pushBack(4);
    cout << "Forward: ";
    dll.printForward();
    cout << "Backward: ";
    dll.printBackward();
    return 0;
}
