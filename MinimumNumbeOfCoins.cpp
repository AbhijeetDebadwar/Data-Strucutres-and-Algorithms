#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void findMin(int n)
{
    vector<int> change = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};

    vector<int> result;

    int count=0;


    while(n)
    {
        int p=0;

        for(int i=0 ; i< change.size() ; i++)
        {
            if(change[i]<=n)
            {
                p=change[i];
            }
            else
            {
                break;
            }
        }

        n-=p;
        result.push_back(p);
        count++;
    }


    cout<<count;
    cout<<"\n";

    for(int i=0; i<result.size() ;i++)
    {
        cout<<result[i]<<"\t";
    }
}


int main()
{
    int n = 93;
    cout << "Following is minimal"
         << " number of change for " << n
         << ": ";
    findMin(121);
    return 0;
}

