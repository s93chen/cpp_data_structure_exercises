#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstddef>

using namespace std;

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void pushFront(const T &d);
    void pushBack(const T &d);
    void popFront();
    void popBack();

    T& front();
    T& back();

    size_t getSize();
    bool isEmpty();
    string toString();

private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node(const T &d) : data(d), next(nullptr), prev(nullptr) { }
    };
    
    size_t size;
    Node *head;
    Node *tail;

    /*
    template <typename T2>
    friend ostream &operator<<(ostream &out, DoublyLinkedList<T2> &dll);
    */
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList():
    head(nullptr),
    tail(nullptr),
    size(0)
{ }

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() 
{
    while (size)
        popFront();
}

template <typename T>
size_t DoublyLinkedList<T>::getSize()
{
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (size == 0);
}


template <typename T>
string DoublyLinkedList<T>::toString()
{
    stringstream ss;
    ss << "[ ";

    for (Node *cur = head; cur != nullptr; cur = cur->next) {
        ss << cur-> data << " ";
    }

    ss << "]\n";
    return ss.str();
}

template <typename T>
T& DoublyLinkedList<T>::front()
{
    if (!size)
        throw logic_error("List is empty.");

    return head->data;
}

template <typename T>
T& DoublyLinkedList<T>::back()
{
    if (!size)
        throw logic_error("List is empty.");

    return tail->data;
}

template <typename T>
void DoublyLinkedList<T>::pushFront(const T &d)
{
    Node *new_node = new Node(d);

    if (!size) {
        tail = new_node;
    } else {
        new_node->next = head;
    }
    
    head = new_node;
    size++;
}

template <typename T>
void DoublyLinkedList<T>::pushBack(const T &d)
{
    Node *new_node = new Node(d);
    
    if (!size) {
        head = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
    }

    tail = new_node;
    size++;
}

template <typename T>
void DoublyLinkedList<T>::popFront()
{
    Node *old_head;

    if (!size) {
        throw logic_error("List is empty.");
    
    } else if (size == 1) {
        old_head = head;
        head = nullptr;
        tail = nullptr;

    } else {
        old_head = head;
        head->next->prev = nullptr;
        head = head->next;
    }
    
    delete old_head;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::popBack()
{
    Node *old_tail;

    if (!size) {
        throw logic_error("List is empty.");  
    
    } else if (size == 1) {
        old_tail = tail;
        head = nullptr;
        tail = nullptr;
    
    } else {
        old_tail = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
    }

    delete old_tail;
    size--;
}

template <typename T>
ostream &operator<<(ostream& out, DoublyLinkedList<T> &dll)
{
    out << dll.toString();
    return out;
}

/**
int main ()
{
    DoublyLinkedList<int> d;

    d.pushFront(10);
    d.pushFront(5);
    d.pushBack(15);
    d.pushBack(20);

    d.popFront();
    d.popBack();
   
    cout << "size = " << d.getSize() << endl;
    cout << d << '\n';
}
*/
