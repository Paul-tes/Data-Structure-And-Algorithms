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
DoubleLinkedList *Head = nullptr; // Global Variable for Head of A Linked List.
void insertBeforeFirst(int x)
{
    DoubleLinkedList *Node = new DoubleLinkedList(x);
    if(Head)
    {
        Node->next = Head;
        Head->prev = Head = Node;
    } 
    else Head = Node;
        // by default Node prev and next are null. no need to assign null to them.
        // Node->next = nullptr;
        // Node->prev = nullptr;
}

void addNode(int x)
{
    DoubleLinkedList *Node, *iNode;
    Node = new DoubleLinkedList(x);
    iNode = Head;
    int n = size();
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}
void insertAfterFirst(DoubleLinkedList *Node)
{
    if(Head)
    {
        DoubleLinkedList* SecNode = Head->next->next;
        Head->next = Node;
        Node->next = SecNode;
        if(!SecNode)
        {
            SecNode->prev = Node;
        }
    }
}
int size()
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

void diplayNode()
{
    DoubleLinkedList *iNode = Head;
    while (iNode)
    {
        int i = 1;
        cout << "Node" <<"[" << i << "] " <<  iNode->data() << " , ";
        iNode = iNode->next;
        i++;
    }
    cout << endl;
    
}

void insertAfterLast();
void insertAtGivenPosition(DoubleLinkedList *Node , int pos);

int main() 
{ 
    insertBeforeFirst(10);
    insertBeforeFirst(20);
    insertBeforeFirst(30);
    
    diplayNode();

    cout << " size " << size() << endl;

    return 0;
}
