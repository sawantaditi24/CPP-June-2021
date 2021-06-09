#include<iostream>
using namespace std;

int const max_size = 30;

void Enter(int A[], int n)
{
    cout<<"enter elements one by one: ";
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
}

void Append(int A[], int *n, int k)
{
    if(*n < max_size)
    {
        A[*n]= k;
        *n+=1;
    }
}

void Insert(int A[], int *n, int ind, int k2)
{
    if(ind<=*n && ind>=0)
    {
        for(int i=*n; i>ind; i--)
            A[i]=A[i-1];

        A[ind]= k2;
        *n+=1;
    }
}

int Delete(int A[], int *n, int ind2)
{
   int show = 0;
   if(ind2<*n && ind2>=0)
   {
      show=A[ind2];
      for(int i=ind2; i<*n-1;i++)
      {
          A[i]=A[i+1];
      }
      *n-=1;
      return show;
   }
}

void Display(int A[], int n)
{
    cout<<"the elements are: ";
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    int A[max_size];
    int n, key1, key2, index, index2;
    cout<<"enter size of your array: ";
    cin>>n;

    Enter(A, n);
    Display(A,n);

    //append
    cout<<"enter the value to be appended: ";
    cin>>key1;
    Append(A, &n, key1);
    cout<<"new size after append: "<<n<<endl;
    Display(A, n);

    //Insert
    cout<<"enter the element to be inserted: ";
    cin>>key2;
    cout<<"enter the index to insert at: ";
    cin>>index;
    Insert(A, &n, index, key2);
    cout<<"new size after insertion: "<<n<<endl;
    Display(A, n);

    //Delete
    cout<<"enter index to be deleted from: ";
    cin>>index2;
    cout<<Delete(A, &n, index2)<<" has been deleted.\n";
    cout<<"new size after deletion: "<<n<<endl;
    Display(A, n);

}
