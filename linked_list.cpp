/*
struct Node
{
    int data = 0;
    Node *next;
}*head;
*/
#include <iostream>
using namespace std;
void *head = nullptr;

class Node
{
private:
    // int data = 0;
    
public:
    int data = 0;
    Node *next;
};



int main() {
    Node *p;
    Node *p = new Node();
    p->data = 10;
    p->next = nullptr;

    cout << "Node p are created." << endl;
    head = p;

    // cheack 
    cout << head->data << endl;
return 0;
}


/*
void delSpecificNode(Node *node, Node *head) {
    Node *curNode;
    curNode = head;

    while (curNode->next && curNode->next !=node)
    {
        curNode = curNode->next;
    }
    curNode = node->next;
    delete node;
}
void movLastNodeToFirst(Node *head, Node *LastNode) {
    Node *curNode, *prevNode;
    curNode = head;
    while (!curNode)
    {   
        prevNode = curNode;
        curNode = curNode->next;
    }
    delete prevNode;
    curNode->next = head;
    head = curNode;
    
}

void reverseLinqList(Node *head) {
    Node *tour, *curNode, *prevNode;
    tour = head; 
    while (!tour)
    {
        prevNode = tour;
        curNode = tour->next;
        curNode->next = prevNode;
        tour = curNode;
    }
    head = curNode;
    
}
*/

