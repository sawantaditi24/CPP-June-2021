#include<iostream>
using namespace std;

int const max_size = 30;
void Display(int x[], int);


void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Enter(int a[], int N)
{
    cout<<"Enter elements one by one: ";
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
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
    //making a copy for sorting
    int Atemp[max_size];
    for(int i=0; i<n; i++)
    {
        Atemp[i]=A[i];
    }

    //sorting for Binary search
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(Atemp[j]>Atemp[j+1])
            {
               Swap(&Atemp[j], &Atemp[j+1]);
            }

    int l=0, h=n-1;
    int mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(Atemp[mid]==bd)
            return mid;
        else if(Atemp[mid]>bd)
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int Sum(int A[], int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum+=A[i];
    }
    return sum;
}

int Average(int A[], int n)
{
    int avg = Sum(A,n)/n;
    return avg;
}

int Maximum(int A[], int n)
{
    int max = A[0];
    for(int i=0; i<n; i++)
        if(A[i]>max)
            max=A[i];
    return max;
}

int Minimum(int A[], int n)
{
    int min = A[0];
    for(int i=0; i<n; i++)
        if(A[i]<min)
            min=A[i];
    return min;
}

void Reverse(int A[], int n)
{
    //making a copy for reversing
    int Atemp[max_size];
    for(int i=0; i<n; i++)
    {
        Atemp[i]=A[i];
    }
    for(int i=0, j=n-1; i<j; i++, j--)
    {
        Swap(&Atemp[i], &Atemp[j]);
    }
    Display(Atemp, n);
}

int checkSort(int a[], int N)
{
    for(int i=0; i<N; i++)
    {
        if(a[i]>a[i+1])
            return 0;
    }
    return 1;
}

void insertSort(int A2[], int &n2, int k3)
{
    cout<<"size in fn"<<n2<<endl;

   if(checkSort(A2, n2))
   {
       cout<<"The array was sorted. Inserted "<<k3<<endl;
       int i = n2-1;
       while(A2[i]>k3)
       {
            A2[i+1]=A2[i];
            i--;
       }
       A2[i+1]=k3;
       n2+=1;
   }
   else
   {
        cout<<"Please enter a sorted array.\n";
        Enter(A2, n2);
        insertSort(A2, n2, k3);
   }

}

void Display(int a[], int N)
{
    cout<<"The elements are: ";
    for(int i=0; i<N; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}



int main()
{
    int A[max_size], Asort[max_size];
    int n, key1, key2, index, index2, ldata, lans, bdata, bans, key3, n2;
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
        cout<<"Found at index "<<bans<<" after sorting the array."<<endl;
    else
        cout<<"Not found!"<<endl;


    cout<<"\nSome mathematical analysis on array -->\n";

    //Sum
    cout<<"The sum of elements is: "<<Sum(A, n)<<endl;

    //Average
    cout<<"The average of elements is: "<<Average(A, n)<<endl;

    //Max element
    cout<<"The element of max value is: "<<Maximum(A, n)<<endl;

    //Min element
    cout<<"The element of min value is: "<<Minimum(A, n)<<endl<<endl;

    //Reversing array
    cout<<"Reversed Array: ";
    Reverse(A, n);


    //Checking if array sorted
    cout<<"Sort status: ";
    if(checkSort(A, n))
        cout<<"Your original array is sorted."<<endl;
    else
        cout<<"Your original array is not sorted."<<endl;


    //Insert in sorted array
    cout<<"Enter size of sorted array: ";
    cin>>n2;
    cout<<"old size: "<< n2<<endl;
    Enter(Asort, n2);
    Display(Asort, n2);
    cout<<"Enter the element to be inserted in sorted array: ";
    cin>>key3;
    cout<<"key: "<<key3<<endl;
    insertSort(Asort, n2, key3);
    cout<<"New size after insertion: "<<n2<<endl;
    Display(Asort, n2);

}

