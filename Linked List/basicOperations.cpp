#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

/*void Create(Node *head, int a[], int n)
{

    Node *last; // a POINTER to last node
    head = new Node(); //first node to rep head
    //first node addition
    head->data = a[0];
    head->next = NULL;
    last = head;

    //for the rest of the following nodes
    for(int i=1; i<n; i++)
    {
        Node *temp = new Node(); //a new temp node
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp; //last ko next node se link kardia
        last = temp; //moving last ahead
    }
}*/


void CreateLL(Node **root, int val)
{
    Node *temp = new Node();
    Node *ptr;
    temp->data = val; //entering value into node of LL
    temp->next = NULL;

    if(*root == NULL)
        *root = temp; //for first node making it root
    else
    {
        ptr = *root; //ptr ko root pe point kara dia
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = temp; //linking happens here
    }
}


Node *ArrayToList(int a[], int n)
{
    Node *root = NULL;
    for(int i=0; i<n; i++)
        CreateLL(&root, a[i]); //call to CreateLL function which adds value to nodes

    return root;
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


int RCount(Node *head) //uses stack so O(n) aux space in addition to O(n) time
{
    if(head == NULL)
        return 0;
    else
        return RCount(head->next)+1;
}


int Sum(Node *head)
{
    int sum = 0;
    while(head != NULL)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}


int RSum(Node *head)
{
    if(head == NULL)
        return 0;
    else
        return RSum(head->next)+ head->data;
}


bool LSearch(Node *head, int key) //takes n space and time
{
    while(head != NULL)
    {
        if(head->data == key)
            return true;
        head = head->next;
    }
    return false;
}


int RLSearch(Node *head, int rkey) //not optimal
{
    if(head == NULL)
        return 0;
    if(rkey == head->data)
        return rkey;
    return RLSearch(head->next, rkey);
}


int Max(Node *head)
{
    int maxx = INT_MIN;
    while(head != NULL)
    {
        if(head->data > maxx)
            maxx = head->data;
        head = head->next;
    }
    return maxx;
}


int RMin(Node *head)
{
    int x = 0;
    if(head == NULL)
        return INT_MAX;

    x = RMin(head->next); //first value to go in x is INT_MAX

    if(x < head->data) //no value will be more than INT_MAX so else
        return x;
    else
        return head->data;
}


Node *Insert(Node *head, int idata, int pos)
{
    if(pos<0 || pos>Count(head))
        return head;

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
    return head;
}


void Display(Node *head)
{
    cout<<"Your Linked List is: ";
    Node *temp = head; //temporary node to traverse LL starting from head until NULL
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



int main()
{
    Node *head = NULL;
    int key, rkey, idata, pos;
    int a[] = {3, 0, 1, 7, 8,0, -11, 2, 99, -33};
    int n = sizeof(a)/sizeof(a[0]);

    //creating LL through array of ints
    head = ArrayToList(a, n);

    //creating LL through Insertion of nodes
    /*head = Insert(head, 10, 0);
    head = Insert(head, 20, 1);
    head = Insert(head, 30, 2);
    head = Insert(head, -10, 5);
    head = Insert(head, 100, 0);*/
    Display(head);



    cout<<"The number of nodes in LL are: "<<Count(head)<<endl;
    cout<<"The number of nodes in LL through recursion are: "<<RCount(head)<<endl;

    cout<<"The sum of all nodes in LL is: "<<Sum(head)<<endl;
    cout<<"The sum of all nodes in LL through recursion is: "<<RSum(head)<<endl;

    cout<<"Enter key to be searched in LL via Linear Search: "; //Binary search not recommended in LL
    cin>>key;
    if(LSearch(head, key))
        cout<<"Found node with key "<<key<<endl;
    else
        cout<<"Not found!"<<endl;

    cout<<"Enter key to be searched in LL via recursive Linear Search: "; //Binary search not recommended in LL
    cin>>rkey;
    if(RLSearch(head, rkey))
        cout<<"Found node with key "<<rkey<<endl;
    else
        cout<<"Not found!"<<endl;

    cout<<"Maximum element in LL is: "<<Max(head)<<endl;
    cout<<"Minimum element in LL through recursion is: "<<RMin(head)<<endl<<endl;

    char ch, ch2;
    cout<<"The number of nodes in LL are: "<<Count(head)<<endl;
    cout<<"Want to insert (y/n)?: ";
            cin>>ch;
    if(ch=='y')
    {
        do
        {
            cout<<"Enter the data to insert: ";
            cin>>idata;
            cout<<"Enter the position after which to insert at: \n 0 to insert before first node, \n"<<Count(head)<<" to insert at the last, \nAny other value to insert in the middle.\nPosition: ";
            cin>>pos;
            head = Insert(head, idata, pos);
            cout<<endl<<idata<<" inserted at position "<<pos+1<<endl;
            cout<<endl<<"Want to insert (y/n)?: ";
            cin>>ch2;
        } while(ch2!='n');
    }

    Display(head);
}
