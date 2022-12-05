#include <iostream>

struct Node
{
    int data = 0;
    Node *next;
    /* data */
};

Node *Head;


//creates a list of nodes from integer array
void create(int a[], int n){
Node *temp, *last;
int i;
Head=new Node();
Head->data=a[0];
Head->next=NULL;
last=Head;

for (i=0; i<n; i++){
    temp=new Node();
    temp->data=a[i];
    last->next=temp;
    temp->next=NULL;
    last=temp;
}
}

void revereseList(Node *_head) {
    Node *p = _head, * q = nullptr, *r = nullptr;
    
    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    _head = q;
    

}

bool isCircular(Node *_head) {
    Node *slow, *fast = _head;
    if(Head) {
        while (!fast->next && !slow)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
        
        
    }else return false;
} 

bool isSorted(Node *_head) {
    Node *inode = _head; // inode for travling throgh all nodes.
    if(!_head) return false;
    {
        while (inode->next)
        {
            if((inode->data > inode->next->data)) return false;
            inode = inode->next;
        }
        
    }
    return true;
} 


void delFirstAddLast(Node* _head) {
    Node *inode = _head;
    if(_head) {
    while (inode->next) inode = inode->next;
    inode->next = _head;
    Head = _head->next;
    }
}

void rightRotateFirst(Node *_head ){
    Node *p = _head, *temp = nullptr;
    while (p->next)
    {
        temp = p;
        p = p->next;
    }
    p->next = _head;
    temp->next = nullptr;
    Head = p;   
}

void print(Node *_head) {
    if(_head == nullptr) return;
    print(_head->next);
    std::cout << _head->data << " ";
}

int main() { // os
    int arr[8] = {1,2,3,4,5,6,7,8};
    create(arr, 8);
    if(isSorted(Head)) {
        std::cout << "is sorted" << std::endl;
    }else std::cout << "it is not sorted" << std::endl;

    if(isCircular(Head)) {
        std::cout << "is Circular" << std::endl; 
    } else std:: cout << "it is not circular" << std::endl;
    std::cout << "Befor rotating " << std:: endl;

    std::cout << "After rotating " << std:: endl;
    rightRotateFirst(Head);
    print(Head);

    std::cout << " delete First Node and Add it to Last" << std:: endl;
    delFirstAddLast(Head);
    print(Head);

return 0;
}