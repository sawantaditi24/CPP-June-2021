#include<bits/stdc++.h>
using namespace std;


//inserting nodes in a sorted manner into LL. Takes O(n) time depending on position of key
struct Node{

    int data;
    Node* next;

}*head = NULL; //universal head


void Display(Node *head) //taking universal head and modifying it locally. DOES NOT CHANGE global head
{
    cout<<"Your Linked List is: ";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int Count(Node *head) //O(n) time only
{
    int c = 0;
    while(head != NULL)
    {
        c = c+1;
        head = head->next;
    }
    return c;
}

void Insert(int idata, int pos)
{
    if(pos<0 || pos>Count(head))
        return;

    Node *temp, *ptr;
    temp = new Node();
    temp->data = idata;

    if(pos==0) //means insert at begin
    {
        temp->next = head;
        head = temp;
    }

    else if(pos>0) //in between LL or at last
    {
       ptr = head;
       for(int i=0; i<pos-1 && ptr!=NULL; i++)
            ptr = ptr->next;

       temp->next = ptr->next;
       ptr->next = temp;
    }
}


void InsertSorted(Node *p, int val) //taking local head into p, using head in function, modifying it globally
{
    Node *q = NULL;
    Node *temp = new Node();
    temp->data = val;
    temp->next = NULL;

    if(head == NULL)
        head = temp;

    else
    {
        while(p!=NULL && p->data < val)
        {
            q = p;
            p = p->next;
        }
        if(p == head)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }
}

bool CheckSorted()
{
    Node *p = head;
    int x = INT_MIN;

    while(p!=NULL)
    {
        if(p->data < x)
            return false;
        else
            x = p->data;
            p = p->next;
    }
    return true;
}

void RemoveDuplicate()
{
    Node *p = head;
    Node *q = head->next;

    while(q != NULL)
    {
        if(q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete(q);
            q = p->next;
        }
    }
}


void ReverseLinks() //r follows q follows p, sliding pointers
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void ReverseData() //using array to map data into and copying back in reverse
{
    int *A = new int [Count(head)];
    Node *p = head;
    int i = 0;

    while(p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }

    i--;
    p = head;

    while(p != NULL)
    {
        p->data = A[i--];
        p = p->next;
    }
}


void RReverseLinks(Node *q, Node *p) //q follows p, performs which return call
{

    if(p != NULL)
    {
        RReverseLinks(p, p->next);
        p->next = q;
    }
    else
        head = q;
}

bool isLoop()
{
    Node *p = head;
    Node *q = head;
    do
    {
        p = p->next;
        q = q->next;
        q = (q!=NULL)? q->next : NULL;
    }while(p && q && p!=q);

    if(p==q)
        return true;
    else
        return false;
}


int main()
{
    InsertSorted(head,10);
    InsertSorted(head,5);
    InsertSorted(head,11);
    InsertSorted(head,-1);
    InsertSorted(head,21);
    InsertSorted(head,-99);
    Display(head); // -99 -1 5 10 11 21

    cout<<"Now inserted random values in middle:\n";
    Insert(39, 6);
    Insert(-399, 6);
    Insert(-3, 5);
    Insert(1, 9);
    Insert(-3, 1);
    Insert(1, 6);
    Insert(-1, 2);
    Display(head);

    if(CheckSorted())
        cout<<"Sorted."<<endl;
    else
        cout<<"Not sorted."<<endl;

    cout<<"After removing succeeding duplicates, ";
    RemoveDuplicate();
    Display(head);

    cout<<"After reversing links, ";
    ReverseLinks();
    Display(head);

    cout<<"After reversing data values, ";
    ReverseData();
    Display(head);

    cout<<"After reversing links via recursion, ";
    RReverseLinks(NULL, head);
    Display(head);

    Node *t1, *t2;
    t1 = head->next->next; //points to 3rd element 5 atm
    t2 = head->next->next->next->next->next; //points to last element 21 atm
    t2->next = t1; //a loop

    if(isLoop())
        cout<<"There's a loop in LL. "<<endl;
    else
        cout<<"No loop in LL. "<<endl;

}
