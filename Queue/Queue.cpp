#include <iostream>
#include <stdlib.h>
using namespace std;

class Queue
{

private:
    int _front; // used for return the first come element and deletion.
    int _rear; // used for isert in to the Queue.
    int _size; // used for the size of the Queue.
    int *Q; // Dynamically allocate the Queue object.

    void moderator() 
    {
        int *temp;
        temp = new int[_size];
        for (int i = _front + 1, j = 0; i < _size - 1; i++, j++)
        {
            temp[j] = Q[i];
        }
        delete Q;
        int *Q;
        Q = temp;
        //delete temp;
        for (int i = 0; i < _size - 1; i++)
        {
            cout << "temp[" << i << "] " <<temp[i] << endl;
        }
        
    }

public:
    Queue() // Queue Constructor. for each Queue object Creation it will be excuite the following code.
    {
        _front = _rear = -1; // initially front and rear are -1 means the Queue is empty
        _size = 10; // by default the Queue size holds 10.
        Q = new int[_size]; // create array with the default size of 10;
    }
    Queue(int s) // parameterized default constructor.
    {
        _front = _rear = -1;
        this->_size = s;
        Q = new int[this->_size];
    }
    void diplay();
    void enQueue(int x); // function prototype for insertion of the element.
    int deQueue(); // function prototype for return from the front element and delete it from Queue.
    bool isEmpty() // check the Queue is empty.
    {
        if(_front == _rear) return true;
        else return false;
    }
    bool isFull() // check the Queue is full.
    {
        if(_rear == _size - 1) return true;
        else return false;
    }

};

void Queue::enQueue(int x) // insert value to the Queue by passing parameter.
{
    if(isFull()) // check wehter the Queue is full.
        cout << "Que is Full" << endl;
    else
    {
        // increment the rear value and inset the element at the incremented rear value.
        _rear++;
        Q[_rear] = x;
    }
}

int Queue::deQueue() 
{
    int x = -1; // to store the return element.
    if(isEmpty()) 
        cout << "The Queue is Empty" << endl;
    else
    {
        _front ++;
        x = Q[_front];
    }
    moderator();
    return x;
}
void Queue::diplay() {
    for (int i = _front + 1; i < _size - 1; i++)
    {
        cout << Q[i] << endl;
    }
    
}

int main() 
{
    Queue* q = new Queue(5);
    q->enQueue(10);
    q->enQueue(20);
    q->enQueue(30);
    q->enQueue(40);

    q->diplay();

    cout << "First Inserted is " << q->deQueue() << endl;
    cout << "after calling deQueue " << endl;
    q->diplay();

    return 0;
}




