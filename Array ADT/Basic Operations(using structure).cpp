#include <iostream>
using namespace std;


struct Array{
    int A[20];
    int length;
    int size;
};

void Enter(struct Array *arr)
{
    cout<<"Enter the length of array: ";
    cin>>arr->length;

    cout<<"Enter elements one by one: ";
    for(int i=0; i<arr->length; i++)
    {
        cin>>arr->A[i];
    }
}

void Append(struct Array *arr, int k)
{
    //checking for index in length
    if(arr->length < arr->size)
    {
        arr->A[arr->length] = k;
        arr->length++;
    }


}

void Insert(struct Array *arr, int k2, int ind)
{
     if(ind>=0 && ind<= arr->length)
    {
        for(int i=arr->length; i>ind; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[ind]= k2;
        arr->length++;
    }
}

void Delete(struct Array *arr, int ind2)
{
    int show = 0;
    if(ind2>=0 && ind2<arr->length)
    {
        show = arr->A[ind2];
        for(int i=ind2; i<arr->length-1; i++)
        {
            arr->A[i]= arr->A[i+1];
        }
        arr->length--;
        cout<<show<<" has been deleted.\n";
    }
}

int Lsearch(struct Array arr, int ld)
{
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]==ld)
            return i;
    }
    return -1;
}

int Bsearch(struct Array arr, int bd)
{

     //sorting for Bsearch
    for(int i=0; i<arr.length-1; i++)
        for(int j=0; j<arr.length-i-1; j++)
            if(arr.A[j]>arr.A[j+1])
            {
                int temp = arr.A[j];
                arr.A[j]=arr.A[j+1];
                arr.A[j+1]=temp;
            }

    int l=0;
    int h= arr.length-1;
    int mid;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(arr.A[mid]==bd)
        {
            return mid;
        }
        else if(bd > arr.A[mid])
        {
            l = mid+1;
        }
        else if(bd < arr.A[mid])
        {
            h = mid-1;
        }
    }
    return -1;
}

void Display(struct Array arr)
{
    cout<<"The elements are: ";
    for(int i=0; i<arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl<<endl;
}


int main()
{
    //struct Array arr = {{2,4,6,8,0}, 5, 20};
    struct Array arr;
    arr.size = 20;
    int key, key2, index, index2, ldata, lans, bdata, bans;

    Enter(&arr);
    Display(arr);


    //Append
    cout<<"Enter the value to be appended in array: ";
    cin>>key;
    Append(&arr, key);
    Display(arr);

    //Insert
    cout<<"Enter the value to be inserted in array: ";
    cin>>key2;
    cout<<"Enter the index at which it is to be inserted: ";
    cin>>index;
    Insert(&arr, key2, index);
    Display(arr);

    //Delete
    cout<<"Enter the index of the element to be deleted: ";
    cin>>index2;
    Delete(&arr, index2);
    Display(arr);


    //Linear Search
    cout<<"Enter the element to search via Linear Search: ";
    cin>> ldata;
    lans = Lsearch(arr, ldata);
    if(lans!=-1)
        cout<<"Found at index "<<lans<<endl;
    else
        cout<<"Not found!\n";


    //Binary Search
    cout<<"Enter the element to search via Binary Search: ";
    cin>> bdata;
    bans = Bsearch(arr, bdata);
    if(bans!=-1)
        cout<<"Found at index "<<bans<<" after sorting array."<<endl;
    else
        cout<<"Not found!\n";

    return 0;
}
