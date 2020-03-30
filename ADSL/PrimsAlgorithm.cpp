#include<iostream>
using namespace std;
#define infinity 1000000
class Prims
{
    int Graphs[40][40],n,SpanningTree[20][20];
    public:
      void CreateGraph();
      void Display();
      void DisplaySpanning();
      int PrimsAlgorithm();
};
void Prims :: CreateGraph()
{
    cout<<"Enter number of nodes: "<<endl;
    cin>>n;
    cout<<"Enter weight of edges: "<<endl;
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
     {
       cin>>Graphs[i][j];   
     }
}
void Prims :: Display()
{
 cout<<"The matrix values are: "<<endl;
   for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
           cout<<Graphs[i][j]<<"  ";   
 
            cout<<endl;
    }
}
void Prims :: DisplaySpanning()
{
 cout<<"The matrix values are: "<<endl;
   for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
           cout<<SpanningTree[i][j]<<"  ";   
 
            cout<<endl;
    }
}
int Prims :: PrimsAlgorithm()
{
    int Visited[10],Distance[10],From[10];
    int GraphCopy[40][40];
    int edges=0,mindistance=0,u=0,v=0,mincost=0;
    //change the Graph into weighted Graph w.r.t algorithm
   for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
           {
            if(!Graphs[i][j])
               GraphCopy[i][j] = infinity;
            else
                GraphCopy[i][j] = Graphs[i][j];
                
            SpanningTree[i][j] = 0;
           }
   Visited[0] = 1;
   Distance[0] = 0;
   edges = n-1;
   for(int i=1;i<n;++i)
   {
       Distance[i] = GraphCopy[0][i];
       From[i] = 0;
       Visited[i] = 0;
   }
   while(edges>0)
   {
       mindistance = infinity;
       for(int i=1;i<n;++i)
        if(!Visited[i] && Distance[i]<mindistance)
        {
            v = i; 
            mindistance = Distance[i];
        }
       u = From[v];
       
       //adding to the spanning tree of the prims
       SpanningTree[u][v] = SpanningTree[v][u] = Distance[v];
       Visited[v] = 1;
       //Updating distance
       for(int i = 1;i<n;++i)
       {
        if(!Visited[i] && GraphCopy[i][v]<Distance[i])
        {
          Distance[i] = GraphCopy[i][v];
          From[i] = v;
        }
       }
          mincost += GraphCopy[u][v];
           --edges;
    }
   
   return mincost;
}
int main()
{
 Prims prim;
 int cost;
 cout<<"The Graph is used Adjcent Matrix "<<endl;
 cout<<"Create the Graph "<<endl;
 prim.CreateGraph();
 cost = prim.PrimsAlgorithm();
 cout<<"Spanning Tree "<<endl;
 prim.DisplaySpanning();
 cout<<"The cost of the spanning tree is:"<<cost<<endl;
 /*0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 2
0 0 4 2 6 0*/
}