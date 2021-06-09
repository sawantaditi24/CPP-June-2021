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

void Append(int A[], int &n, int k)
{
    if(n < max_size)
    {
        A[n]= k;
        n++;
    }
}

void Insert(int A[], int &n, int ind, int k2)
{
    if(ind<=n && ind>=0)
    {
        for(int i=n; i>ind; i--)
            A[i]=A[i-1];

        A[ind]= k2;
        n++;
    }
}

int Delete(int A[], int &n, int ind2)
{
   int show = 0;
   if(ind2<n && ind2>=0)
   {
      show=A[ind2];
      for(int i=ind2; i<n-1;i++)
      {
          A[i]=A[i+1];
      }
      n-=1;
      return show;
   }
}

int Lsearch(int A[], int n, int ld)
{
    for(int i=0; i<n; i++)
        if(A[i]== ld)
            return i;
    return -1;
}

int Bsearch(int A[], int n, int bd)
{
    //sorting for Bsearch
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }

    int l=0, h=n-1;
    int mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(A[mid]==bd)
            return mid;
        else if(A[mid]>bd)
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
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
    int n, key1, key2, index, index2, ldata, lans, bdata, bans;
    cout<<"Enter size of your array: ";
    cin>>n;

    Enter(A, n);
    Display(A,n);

    //append
    cout<<"Enter the value to be appended: ";
    cin>>key1;
    Append(A, n, key1);
    cout<<"New size after append: "<<n<<endl;
    Display(A, n);

    //Insert
    cout<<"Enter the element to be inserted: ";
    cin>>key2;
    cout<<"Enter the index to insert at: ";
    cin>>index;
    Insert(A, n, index, key2);
    cout<<"New size after insertion: "<<n<<endl;
    Display(A, n);

    //Delete
    cout<<"Enter index to be deleted from: ";
    cin>>index2;
    cout<<Delete(A, n, index2)<<" has been deleted.\n";
    cout<<"New size after deletion: "<<n<<endl;
    Display(A, n);

    //Linear Search
    cout<<"Enter the value to search via Linear Search: ";
    cin>>ldata;
    lans= Lsearch(A, n, ldata);
    if(lans!=-1)
        cout<<"Found at "<<lans<<endl;
    else
        cout<<"Not found!"<<endl;

    //Binary Search
    cout<<"Enter the value to search via Binary Search: ";
    cin>>bdata;
    bans= Bsearch(A, n, bdata);
    if(bans!=-1)
        cout<<"Found at "<<bans<<" after sorting the array."<<endl;
    else
        cout<<"Not found!"<<endl;

}

