#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void sorting(int Arr[], int arr_size)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr_size; i++) {
        mp[Arr[i]]++;
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (mp.find(Arr[i]) != mp.end())
        {
            int k = mp[Arr[i]];
            while (k) {
                cout << Arr[i] << " ";
                k--;
            }

            mp.erase(Arr[i]);
        }
    }
}

int main()
{
    int numOfElements;
    int element;
    cout<<"please enter the number of elements"<<endl;
    cin>>numOfElements;
    int Arr[numOfElements];

    cout<<"please enter the elements"<<endl;
    for(int i = 0; i < numOfElements; i++){
        cin>> element;
        Arr[i] = element;
    }
    int frequency = sizeof(Arr)/sizeof(Arr[0]);

    sorting(Arr, frequency);

    return 0;
}
