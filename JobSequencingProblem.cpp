#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job
{
public:

    char ch;
    int deadline;
    int profit;
};

bool compareJob(Job J1, Job J2)
{
    return J1.profit > J2.profit ;
}

void printJobScheduling(Job arr[],int n)
{

    vector<Job> vect;

    for(int i=0 ;i<n ; i++)
    {
        vect.push_back(arr[i]);

    }


    sort(vect.begin() ,vect.end() , compareJob);

    bool isEmptySlot[n];
    vector<char> slots(n);     //remove size n at this line

    for(int i=0 ; i<n ; i++)
    {
        isEmptySlot[i] = true;
    }


    for(int i=0 ; i<n ; i++)
    {
        int d= vect[i].deadline;
        int k=-1;

        for(int j=0 ; j<d ; j++)
        {
            if (isEmptySlot[j]==true )
            {
                k=j;
            }

        }
        if(k!=-1)
        {
            slots[k] = vect[i].ch;
            isEmptySlot[k]= false;
        }
    }

    for(int i=0 ;i<slots.size() ; i++)
    {
        if(isEmptySlot[i]==false)
            cout<<slots[i]<<"\t";
    }

}

int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};

    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);
    return 0;
}
