#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



class Edge
{
public:
    int s,d,w;
};

class Graph
{
public:

    int V,E;
    int p=0;
    Edge* edge;
};

void addEdge(Graph* graph, int s , int d, int w)
{
    if(graph->p < graph->E)
    {

        graph->edge[graph->p].s = s;
        graph->edge[graph->p].d=d;
        graph->edge[graph->p].w =w;
        graph->p++;
    }
    else
    {
        cout<<"No space"<<"\n";
    }
}

void removeEdge(Graph* graph)
{
    graph->p--;
}

Graph* createGraph(int V, int E)
{
    Graph* graph =new Graph();
    graph->V=V;
    graph->E=E;

    graph->edge = new Edge[graph->E];

    return graph;
}

void traverseGraph(Graph* graph)
{
    for(int i=0 ;i <graph->p ;i++)
    {
        cout<<"("<<(graph->edge[i].s)<<","<<(graph->edge[i].d)<<")"<<"\t"<<"weight: "<<(graph->edge[i].w)<<"\n";
    }
}

int findParent(int x, int* parent , int v)
{
    int pos;

    pos=x;


    while(!(parent[pos]==-1 or parent[pos]==pos))
    {
        pos = parent[pos];
    }

    return pos;

}

bool detectCycleUnionFind(Graph* graph)
{
    int* parent = new int[graph->V];

    for(int i=0; i<graph->V ; i++)
    {
        parent[i]=-1;
    }

    int p1,p2;
    int s,d;

    for(int i=0 ; i<graph->p ; i++)
    {

        s = graph->edge[i].s;
        d = graph->edge[i].d;

        p1 = findParent(s,parent,graph->V);
        p2 = findParent(d,parent,graph->V);

//        cout<<"s: "<<s<<"\t"<<"d: "<<d<<"\t"<<"p1: "<<p1<<"\t"<<"p2: "<<p2<<"\n";

        if(p1==p2)
        {

            return true;
        }

        else
        {
            parent[p1] = p2;

        }

    }

    return false;

}

bool compareEdge(Edge E1, Edge E2)
{
    return (E1.w < E2.w);
}

void findMST(Graph* graph)
{
    vector<Edge> edges(graph->p);


    for(int i=0 ; i< graph->p ; i++)
    {
        edges[i] = graph->edge[i];
    }


    sort(edges.begin() ,edges.end(),compareEdge);

    Graph* g = createGraph(graph->V,graph->E-1);

    for(int i=0 ; i<edges.size() ; i++)

    {
        addEdge(g, edges[i].s ,edges[i].d , edges[i].w);

        if(detectCycleUnionFind(g))
        {
            removeEdge(g);
        }
    }

    cout<<"Spanning Tree: "<<"\n";
    traverseGraph(g);

}



int main()
{
    Graph* graph = createGraph(9,14);

    addEdge(graph,0,1,4);
    addEdge(graph,1,2,8);
    addEdge(graph,2,3,7);
    addEdge(graph,3,4,9);
    addEdge(graph,4,5,10);
    addEdge(graph,5,6,2);
    addEdge(graph,6,7,1);
    addEdge(graph,7,0,8);
    addEdge(graph,7,1,11);
    addEdge(graph,7,8,7);
    addEdge(graph,2,8,2);
    addEdge(graph,8,6,6);
    addEdge(graph,2,5,4);
    addEdge(graph,3,5,14);

//    traverseGraph(graph);

    findMST(graph);

    return 0;
}
