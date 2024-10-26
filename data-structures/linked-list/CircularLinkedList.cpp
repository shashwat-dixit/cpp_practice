#include <iostream>
#include <unordered_set>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {};
};

template <typename T>
class CircularLinkedList
{
private:
    Node<T> *tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(T val)
    {
        Node<T> *newNode = new Node(val);
        if (!tail)
        {
            tail = newNode;
            tail->next = tail;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void remove(T val)
    {
        if (!tail)
            return;

        Node<T> *current = tail->next;
        Node<T> *prev = tail;
        do
        {
            if (current->data == val)
            {
                if (current == tail)
                {
                    tail = prev;
                }
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);
    }
    void print()
    {
        if (!tail)
            return;
        Node<T> *current = tail->next;
        do
        {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != tail->next);
        cout << "(back to start)" << endl;
    }
    ~CircularLinkedList()
    {
        if (!tail)
            return;
        Node<T> *current = tail->next;
        while (current != tail)
        {
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        }
        delete tail;
    }
};

int main()
{
    cout << "\nCircular Linked List Demo:" << endl;
    CircularLinkedList<int> cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);
    cout << "Original: ";
    cll.print();
    cll.remove(2);
    cout << "After removing 2: ";
    cll.print();
    return 0;
}
