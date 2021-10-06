#include <iostream>
using namespace std;

const int max_size = 20;
int C[max_size];

void Enter(int a[], int N)
{
    int sz = 0;
    if (N <= max_size)
    {
        cout << "Enter elements in sorted manner: ";
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
    }

    else
    {
        cout << "Enter size under 10: ";
        cin >> sz;
        Enter(a, sz);
    }
}

void Display(int a[], int N)
{
    cout << "Elements in array are: ";
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl
         << endl;
}

int Merge(int A[], int B[], int m, int n)
{
    //int C[m+n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    for (; i < m; i++)
    {
        C[k++] = A[i];
    }
    for (; j < n; j++)
    {
        C[k++] = B[j];
    }
    return k;
}

int Union(int A[], int B[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else if (B[j] < A[i])
            C[k++] = B[j++];
        else
        {
            C[k++] = B[j++];

            i++;
        }
    }
    for (; i < m; i++)
    {
        C[k++] = A[i];
    }
    for (; j < n; j++)
    {
        C[k++] = B[j];
    }
    return k;
}

int Intersection(int A[], int B[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
            i++;
        else if (B[j] < A[i])
            j++;
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }
    return k;
}

int Difference(int A[], int B[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else if (A[i] > B[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < m; i++)
    {
        C[k++] = A[i];
    }
    return k;
}

int main()
{

    int A[max_size], B[max_size], m, n;

    cout << "Enter size of array 1: ";
    cin >> m;
    Enter(A, m);
    Display(A, m);

    cout << "Enter size of array 2: ";
    cin >> n;
    Enter(B, n);
    Display(B, n);

    cout << "Merge: \n";
    int kmerge = Merge(A, B, m, n);
    cout << "Size is: " << kmerge << endl;
    Display(C, kmerge);

    cout << "Set Union: \n";
    int kunion = Union(A, B, m, n);
    cout << "Size is: " << kunion << endl;
    Display(C, kunion);

    cout << "Set Intersection: \n";
    int kintersect = Intersection(A, B, m, n);
    cout << "Size is: " << kintersect << endl;
    Display(C, kintersect);

    cout << "Set Difference: \n";
    int kdiff = Difference(A, B, m, n);
    cout << "Size is: " << kdiff << endl;
    Display(C, kdiff);
}
