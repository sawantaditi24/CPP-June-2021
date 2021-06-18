#include<iostream>
#include<vector>
using namespace std;

template <class T>
void Display(vector<T> &vec)
{
   cout<<"Displaying elements of vector: ";
   for(int i=0; i<vec.size(); i++)
   {
       cout<<vec[i]<<" ";
   }
   cout<<endl;
}

int main()
{
    //size zero vector, size by user
    vector<int>vec1;
    int size, element;
    cout<<"Enter size of vector: ";
    cin>>size;

    //entering elements in vector one by one
    for(int i=0; i<size; i++)
    {
        cout<<"Enter vector element: ";
        cin>>element;
        vec1.push_back(element);
    }

    //pop back
    Display(vec1);
    vec1.pop_back();
    Display(vec1);

    //size 4 vector with given values
    vector<char>vec2(4, '0');
    Display(vec2); // displays 0 4 times

    //making vector from vec2
    vector<char>vec3(vec2);
    Display(vec3); //displays contents of vec2

    //insertion using iterator
    vector<char> :: iterator iter = vec2.begin();
    vec2.insert(iter, '7'); //inserts 77 at iter which is at beginning
    iter = vec2.begin();
    vec2.insert(iter+2, '8'); //displays 88 at iter which is at beginning+2 i.e. 3rd position
    cout<<"After insertion, ";
    Display(vec2);
    cout<<"Iter is at value "<<*iter;

    /*vector<int> :: iterator iter2 = vec1.begin();
    for(iter2 = vec1.begin(); iter2!=vec1.end(); ++iter2)
    {
        //iter2 = vec1.begin();
        vec1.insert(iter2, 2, 6);
    }
    Display(vec1);
    */

    //initialized vector
    vector<float> vec4 = {1.20f, 1.30f, 7.12f, 4.40f, 31.12f};
    //using .at()
    for(int i=0; i<vec4.size(); i++)
    {
        cout<<"\n\nElement "<<i+1<<" in vector is: "<<vec4.at(i)<<" ";
    }
}
