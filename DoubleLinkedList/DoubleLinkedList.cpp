#include <iostream>
using namespace std;

class DoubleLinkedList
{
private:
    int _data;
public:
    DoubleLinkedList *next;
    DoubleLinkedList *prev;
    DoubleLinkedList(int x)
    {
        _data = x;
        next = nullptr;
        prev = nullptr;
    }
    int data() {
        return _data;
    }   
};
DoubleLinkedList *Head = nullptr; // Global Variable for Head of The Linked List.
DoubleLinkedList *Tail = nullptr; // Global Bariable for Tail of the Linked List.
void insertBeforeFirst(int x)
{
    DoubleLinkedList *Node = new DoubleLinkedList(x);
    if(Head)
    {
        Head->prev = Node;
        Node->next = Head;
        Head = Node;
        Head->prev = nullptr;
    } 
    else 
    {
        Head = Node;
        Tail = Node;
        // by default Node prev and next are null. no need to assign null to them.
        // Node->next = nullptr;
        // Node->prev = nullptr;
    }
}

void addNodeLast(int x)
{
    DoubleLinkedList *Node, *iNode, *prevNode;
    Node = new DoubleLinkedList(x);
    iNode = Head;

    if(Head)
    {
    while (iNode)
    {
        prevNode = iNode;
        iNode = iNode->next;
    }
    prevNode->next = Node;
    Node->prev = prevNode;
    Tail = Node;
    //Node->next = nullptr; by default for every node->next are null.
    } 
    else Head, Tail = Node;
    //by defualt Node(next & prev) are null no need to assign null on to them.
    //Node->next = nullptr;
    //Node->prev = nullptr;
}
void insertAfterFirst(int x)
{
    DoubleLinkedList *Node = new DoubleLinkedList(x);
    if(Head)
    {
        Node->prev = Head;
        Node->next = Head->next;
        Head->next->prev = Node;
        Head->next = Node;
    }
    else Head, Tail = Node;
        // No need to assign Node->next and Node->prev by default they are pointing to null.
}
int size() // finding the size of the Node
{
    int size = 0;
    DoubleLinkedList *iNode = Head;
    while (iNode)
    {
        size++;
        iNode = iNode->next;
    }
    
    return  size;
}

void diplayNode() // Displaying Node
{
    DoubleLinkedList *iNode = Head;
    int i = 0;
    while (iNode)
    {
        i++;
        cout << "Node" <<"[" << i << "] " <<  iNode->data() << ", ";
        iNode = iNode->next;
    }
    cout << endl;
    
}

void insertAtGivenPosition(int x, int pos) // assume node index starts from 1.
{
    DoubleLinkedList *iNode = Head; // used for traverse.
    DoubleLinkedList *Node = new DoubleLinkedList(x);
    int s = size(); // assign the size of the DLL to s.
    if(pos > s && !Head) return; // if the position is grater than the size and if the node are empty return None.
    else 
    {
        for (int i = 1; i < pos -1; i++) iNode = iNode -> next;
        Node->prev = iNode;
        Node->next = iNode->next;
        iNode->next->prev = Node;
        iNode->next = Node;
    }
}

void Erase()
{
    DoubleLinkedList *iNode = Head;
    while (iNode != nullptr)
    {
        DoubleLinkedList *p = iNode;
        iNode = iNode->next;
        delete p;
    }

    diplayNode();
    cout << "Delete successful...." << endl;
    
}

void reverseNode();

int main() 
{ 
    insertBeforeFirst(10);
    insertBeforeFirst(20);
    insertBeforeFirst(30);
    cout << "Insert Befor [10], [20], [30]" << endl;
    diplayNode();
    cout << " size " << size() << endl;
    
    addNodeLast(5);
    addNodeLast(1);
    cout << "Add Node to Last [5], [1]" << endl;
    diplayNode();
    cout << " size " << size() << endl;

    insertAfterFirst(80);
    cout << "Add Node to After first [80]" << endl;
    diplayNode();
    cout << " size " << size() << endl;

    insertAtGivenPosition(100, 3);
    cout << "insert node at given position position = 3, data = [100]" << endl;
    diplayNode();
    cout << " size " << size() << endl;

    Erase();

    return 0;
}
