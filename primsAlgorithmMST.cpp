#include<iostream>
using namespace std;

#define V 5

void printMST(int parent[], int graph[V][V])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}



int minKey(int key[],bool inMST[])
{
    int mini =(2^32)-1;
    int min_ind;

    for(int i=0 ; i<V ; i++)
    {
        if(inMST[i]==false && key[i]<mini)
        {
            mini=key[i];
            min_ind=i;
        }
    }

    return min_ind;

}

void primMST(int graph[V][V])
{

    int parent[V];
    bool inMST[V];
    int key[V];


    for(int i=0; i<V ;i++)
    {
        key[i]=(2^32)-1;
        inMST[i]=false;
    }

    key[0]=0;
    parent[0]=-1;
    int u;


    for(int i =0; i<V-1 ;i++)
    {
        u = minKey(key,inMST);

        inMST[u] =true;

        for( int v=0 ; v<V ; v++)
        {

            if(graph[u][v]!=0 && inMST[v]==false && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v]=u;
            }
        }
    }

    printMST(parent,graph);

}

int main()
{

    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };


    primMST(graph);

    return 0;
}
