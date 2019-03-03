#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


/** class definition */

class CircularQueue
{

public:

    /** constructor */
    CircularQueue(int cap);

    /** destructor */
    ~CircularQueue();
    
    /** enqueue int */
    void add(int val);

    /** dequeue (do not return) */
    void remove();

    /** return copy of first item */
    int front();

    /** return copy of last item */
    int rear();

    /** queue size */
    int get_size();

    /** queue cap */
    int get_capacity();

    /** queue empty or not */
    bool is_empty();

    /** clear queue */
    void clear();

private:

    int *_A;
    int _size;
    int _cap;
    int _front;
    int _rear;
};

CircularQueue::CircularQueue(int cap)
{
    if (cap < 1)
        throw logic_error("Capacity must be positive.");

    _front = 0;
    _rear = -1;
    _size = 0;
    _cap = cap;
    
    _A = new int[_cap];    
}

CircularQueue::~CircularQueue()
{
    delete[] _A;    
}

int CircularQueue::get_size()
{
    return _size;    
}

int CircularQueue::get_capacity()
{
    return _cap;    
}

void CircularQueue::add(int val)
{
    if (_size == _cap)
        throw logic_error("Queue is full!");
    /**
    if (_size == 0) {
        _A[_front] = val;
    
    } else {
        _rear = (_rear + 1) % _cap;
        _A[_rear] = val;
    }
    */
    _rear = (_rear + 1) % _cap;
    _A[_rear] = val;
    _size++;

    cout << "enqueued " << val;
    cout << " at current rear " << _rear << endl;     
}

void CircularQueue::remove()
{
    if (_size == 0)
        throw logic_error("Queue is empty!");
    
    _front = (_front + 1) % _cap;
    _size--;

    cout << "front at " << _front;
    cout << " after remove" << endl; 
}

int CircularQueue::front()
{
    if (_size == 0)
        throw logic_error("Queue is empty!");

    int result = _A[_front];
    cout << "show front: " << result << endl;

    return result;    
}

int CircularQueue::rear()
{
    if (_size == 0)
        throw logic_error("Queue is empty!");

    int result;
    
    /**
    if (_size == 1) {
        cout << "only one item in queue";
        result =  _A[_front];
    }
    */
    
    result = _A[_rear];
    cout << "show rear: " << result << endl;
    
    return result;    
}

bool CircularQueue::is_empty()
{
    if (_size == 0)
        return true;

    return false;
}

void CircularQueue::clear()
{
    _front = 0;
    _rear = -1;
    _size = 0;
    
    cout << "cleared queue" << endl;
}

int main()
{
    CircularQueue c1(5);
    
    c1.add(1);
    c1.add(2);
    c1.add(3);
    c1.add(4);
    c1.add(5);
    cout << c1.get_size() << endl;

    cout << "queue empty: ";
    cout << c1.is_empty() << endl;

    c1.remove();
    c1.remove();
    c1.add(6);
    c1.front();
    c1.rear();

    cout << c1.get_capacity() << endl;
    cout << c1.get_size() << endl;

    c1.clear();
    c1.add(10);
    c1.add(20);
    c1.front();
    c1.rear();
    cout << c1.get_size() << endl;
}
