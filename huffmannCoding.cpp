#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Node
{
public:

    Node* left=NULL;
    Node* right=NULL;
    char ch;
    int freq;
};

bool compareNode(Node* N1,Node* N2)
{
    return N1->freq<N2->freq;
}

void traverse(Node* node , vector<int> code)
{

    if(node->left==NULL && node->right==NULL)
    {
        cout<<node->ch<<" : ";

        for(int i=0 ; i<code.size(); i++)
        {
            cout<<code[i];
        }
        cout<<"\n";
    }


    else
    {
        if(node->left!=NULL)
        {
            code.push_back(0);
            traverse(node->left,code);
            code.pop_back();
        }

        if(node->right!=NULL)
        {
            code.push_back(1);
            traverse(node->right,code);
            code.pop_back();
        }
    }

}

void huffmanCodes(char charray[] , int frqarray[] , int size)
{

    vector<Node*> vect;

    for(int i=0; i<size ;i++)
    {
        Node* newnode = new Node;
        newnode->ch = charray[i];
        newnode->freq = (-1)*frqarray[i];

        vect.push_back(newnode);
    }

    make_heap(vect.begin(), vect.end(),compareNode);


    Node* l,*r;
    int fsum;

    while(!(vect.size()==1))
    {
         l = vect.front();
         pop_heap(vect.begin() , vect.end(),compareNode);
         vect.pop_back();

         r = vect.front();
         pop_heap(vect.begin() , vect.end(),compareNode);
         vect.pop_back();

         fsum= l->freq + r->freq;

         Node* newnode =new Node;

         newnode->freq=fsum;

         newnode->left=l;
         newnode->right=r;

         vect.push_back(newnode);
         push_heap(vect.begin(),vect.end(),compareNode);
    }



    vector<int> code;
    cout<<"Huffmann Codes:\n";
    traverse(vect.front() ,code);
    cout<<"\n";

}


int main()
{

    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    huffmanCodes(arr, freq, size);

    return 0;
}
