#include<iostream>
using namespace std;

#define V 9


int minDist(int dist[] , bool inSPT[])
{
    int mini =(2^32)-1;

    int miniInd=NULL;


    for( int i=0; i<V ; i++ )
    {

        if(inSPT[i]==false && dist[i]<mini)
        {
            mini = dist[i];
            miniInd = i;
        }

    }
    return miniInd;
}

void printSPT(int dist[])
{
    for(int i=0 ;i<V ; i++)
    {
        cout<<i<<"-->"<<dist[i]<<"\n";
    }
}

void dijkstra(int graph[V][V], int s)
{

    int dist[V];
    bool inSPT[V];


    for(int i=0; i<V ;i++)
    {
        dist[i]=(2^32)-1;
        inSPT[i]=false;
    }

    dist[s] =0;
    inSPT[s] =true;

    for(int i=0; i<V-1; i++)
    {
        int  u = minDist(dist, inSPT);
        inSPT[u] =true;


        for(int v=0 ; v<V ; v++)
        {
            if(graph[u][v]!=0 && inSPT[v]==false && dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printSPT( dist);

}



int main()
{

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}
