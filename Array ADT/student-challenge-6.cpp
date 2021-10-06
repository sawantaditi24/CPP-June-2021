#include <iostream>
using namespace std;

//program to find multiple duplicate elements in an unsorted array O(n sq.)
//can also simply be done by binary hash array or bitset
int main()
{

    int n;

    cout << "Enter size of array: ";
    cin >> n;
    int A[n];
    cout << "Enter elements in array in unsorted format, duplicating 1 or more element(s): ";

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n - 1; i++)
    {

        if (A[i] != -1)
        {
            int j = i + 1, count = 1;
            while (j < n)
            {
                if (A[j] == A[i])
                {
                    count++;
                    A[j] = -1;
                }
                j++;
            }
            if (count > 1)
                cout << A[i] << " was duplicated " << count << " times. \n";
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
