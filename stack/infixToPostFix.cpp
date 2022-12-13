#include <iostream>
//#include <stack>
#include <string.h>
#include <stdlib.h>
using namespace std;
int insidePriority(char c);
int outsidePriority(char c);
char *infixToPostFix(char *exp);


// ############################# STACK IMPLEMENTATION ############################
class Node
{
private:
public:
    char data;
    Node* next;
};

class Stack
{
private:
    Node* _top;
public:
    Stack();
    ~Stack();
    void push(char c);
    char pop();
    bool isEmpty();
    bool isFull();
    char top();
};

Stack::Stack() // constructor do the top to point nothing(null) when creating the object of Stack.
{
    _top = nullptr;
}
Stack::~Stack() // destructor dellete all datas
{
    Node *p = _top;
    while (_top)
    {
        _top = _top->next;
        delete p;
        p = _top;
    }
    
}

void Stack::push(char c)
{
    Node *t = new Node();
    if(t) 
    {
        t->data = c;
        t->next = _top;
        _top = t;
    }
    else
    {
        cout << "stack Overflow!" << endl;
        return;
    }
}

char Stack::pop()
{
    Node *p; 
    char c = ' ';
    if(_top) // if the top is not null
    {
        c = _top->data;
        p = _top;
        _top = _top->next; // update top of the stak
        delete p; // delete the top element. pop removes the top of the stack.
    }
    else cout << "Stack UnderFlow!" << endl;

    return c;
}

char Stack::top()
{
    char c;
    isEmpty() ? c = ' ': c = _top->data; 
    return c;
}

bool Stack::isFull()
{
    Node *p = new Node();
    return p; // if p is null it returns false if p is pointing to some memory location it is not full and it returns false.
}
bool Stack::isEmpty()
{
    return _top ? false: true;
}


//######################     MAIN    ###############################
int main()
{   
    char infix [] = "a+b*c-d/e"; 

    char *postfix = infixToPostFix(infix);
    printf("%s", postfix);
    return 0;
}

// -----------------------------------------------------------------


// ##################### INFIX TO POSTFIX ALGO  #########################

char *infixToPostFix(char *exp)
{
    Stack *st = new Stack();
    int len = strlen(exp);
    char *postFix;
    postFix = (char*)malloc((len + 1) * sizeof(char)); // 

    int i = 0, j = 0;
    while (exp[i] != '\0')
    {
        if (insidePriority(exp[i]) == -2) // if it is operand
            postFix[j++] = exp[i++]; //
        else
        {
            if (outsidePriority(exp[i]) > insidePriority(st->top()))
                st->push(exp[i++]);
            else postFix[j++] = st->pop();
        }
    }
    

    return postFix;
}

int insidePriority(char c)
{
    if( c == '*' || c == '/' || c == '%') return 4;
    else if (c == '+' || c == '-') return 2;
    else if (c == '^') return 5;
    else if (c == '(') return 0;
    else if (c == ')') return -1; // ) value given to -1 randomly it is less than all value
    else return -2; // none of operation are represented by -2.
}
int outsidePriority(char c)
{
    if( c == '*' || c == '/' || c == '%') return 3;
    else if (c == '+' || c == '-') return 1;
    else if (c == '^') return 6;
    else if (c == '(') return 7;
    else if (c == ')') return 0;
    else return -2; // none of this character is represented by -2 
}




// by using bultin stack. 

/*
string inToPost(string s)
{
    stack<char> st;

    int len = s.length();
    char *postFix;
    postFix = (char*)malloc((len + 1) * sizeof(char));

    for (int i,j = 0; s[i] != '\0'; i++)
    {
        if(st.top())
        {
            int in = insidePriority(s[i]);
            if(in == -2) // it is not oprator. send to the postFix.
            {
                postFix[j] = s[i]; // insert in to the postFix character array. 
                j++; // increment the index of the postFix char array for the next element.
            }
            else st.push(s[i]); // push it to in the stack with out condition b/c it is the first element on the stack.
        }
        else
        {
            int in = insidePriority(st.top());
            int out = outsidePriority(s[i]);
            if( in > out) // if the element IN STACK priority number is GREATER than the OUT STACK piority of the operator sign pop the stack in to prefix.
            {
                postFix[j] = st.pop();
                j++;
            }
            else st.push(s[i]); // if it is LESS than push the element on the stack
        }
    }


    string p  = postFix;
    return p; 
}
*/
