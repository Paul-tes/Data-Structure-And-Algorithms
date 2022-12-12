#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};

Node *head=NULL;
Node *sorted=NULL;

//creates a list of nodes from integer array
void create(int a[], int n){
Node *temp, *last;
int i;
head=new Node();
head->data=a[0];
head->next=NULL;
last=head;

for (i=0; i<n; i++){
    temp=new Node();
    temp->data=a[i];
    last->next=temp;
    temp->next=NULL;
    last=temp;
}
}

//bubble sort for linked list data structure
//works only for integer data (if the node contains integer data)
void sortLLBubbleSort(Node *p){
    Node *current,*index=NULL;
    current=p;
    int temp;
    if(p==NULL){
        return ;
    }
    else{
        while(current!=NULL){
        index=current->next;
        while(index!=NULL){
            if (current->data > index->data){
                temp=current->data;
                current->data=index->data;
                index->data=temp;
            }
            index=index->next;
        }
        current=current->next;
    }
}
    }

//Insertion sort for linked list data structure
//works only for integer data (if the node contains integer data)
 void sortedInsert(Node* newnode)
    {
        if (sorted == NULL ||
            sorted->data >= newnode->data)
        {
            newnode->next = sorted;
            sorted = newnode;
        }
        else
        {
            Node* curr = sorted;
            while (curr->next != NULL &&
                   curr->next->data < newnode->data)
            {
                curr = curr->next;
            }
            newnode->next = curr->next;
            curr->next = newnode;
        }
    }

void sortLLInsertionSort(Node *p){
Node *current = head;
while (current != NULL)
        {
            Node* next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
}
 
void display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

 int main(){
    int A[]={80, 30, 70, 50, 60, 40,10};
    
    int n=sizeof(A)/sizeof(A[0]);
    create(A, n);
    
    sortLLInsertionSort(head);
    sortLLBubbleSort(head);
    display(head);

    return 0;
}