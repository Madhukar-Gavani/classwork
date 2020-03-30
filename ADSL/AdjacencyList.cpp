#include<iostream>
using namespace std;
struct LinkedList
{
	int data;
	LinkedList *Next;
};
LinkedList *Array[10];

int main()
{
	int nodes,edges;
	int Vi,Vj;
	LinkedList *NextNode,*NextSearch,*Node;
	cout<<"Enter how many nodes in the graph;"<<endl;
	cin>>nodes;
	cout<<"Enter number of edges in the Graph:"<<endl;
	cin>>edges;
	for(int i=0;i<edges;++i)
	{
		cout<<"Enter the edges connections between the nodes:"<<endl;
		cin>>Vi>>Vj;
		for(int j=0;j<nodes;++j)
		{
			if(Array[j] == NULL)
			{
				Node = new LinkedList;
			     Node->data = Vi;
			     Node->Next = NULL;
				Array[j] = Node;
				NextNode = new LinkedList;
				NextNode->data = Vj;
				NextNode->Next = NULL;
				Array[j]->Next = NextNode;
				break;
			}
			else if(Array[j]->data == Vi)
			{
				NextNode = new LinkedList;
				NextNode->data = Vj;
				NextNode->Next = NULL;
				NextSearch = Array[j]->Next;
				while(NextSearch->Next != NULL)
				 NextSearch = NextSearch->Next;
				 
				NextSearch->Next = NextNode;
				break;
			}
		}
	}
	cout<<"output"<<Array[0]->Next->Next->data;
}