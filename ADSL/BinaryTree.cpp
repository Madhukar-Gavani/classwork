// Example program
#include <iostream>
#include <string>
using namespace std;

class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode *Left;
    BinaryTreeNode *Right;
};
class BinaryTree{
 public:
 BinaryTreeNode *insert(BinaryTreeNode *Root , int data);
 BinaryTreeNode *Search(BinaryTreeNode *Root , int data);
 BinaryTreeNode *SwapLR(BinaryTreeNode *Root);
 int min(BinaryTreeNode *Root);
 void Display(BinaryTreeNode *Root);
};

BinaryTreeNode *BinaryTree :: insert(BinaryTreeNode *Root , int data)
{
   if(Root == NULL)
   {
        Root = new BinaryTreeNode;
         Root->data = data;
        Root->Left = NULL;
        Root->Right = NULL;
     
     return Root;
 }
 if(data<Root->data)
 {
    Root->Left = insert(Root->Left , data);
    return Root;
 }
 if(data>Root->data)
 {
   Root->Right = insert(Root->Right , data);
   return Root;
 }
}
BinaryTreeNode *BinaryTree :: Search(BinaryTreeNode *Root , int data)
{
   if(Root == NULL)
     return Root;
   
    if(data<Root->data)
    {
        Root->Left = Search(Root->Left , data);
         return Root;
    }
    
    if(data>Root->data)
    {
     Root->Right = Search(Root->Right , data);
      return Root;
    }
    if(Root->data == data)
    return Root;
}
BinaryTreeNode *BinaryTree :: SwapLR(BinaryTreeNode *Root)
{
   BinaryTreeNode *swap;
   if(Root!=NULL)
   {
     swap = Root->Left;
     Root->Left = SwapLR(Root->Right);
     Root->Right = swap;
   }
   return Root;
}

int BinaryTree :: min(BinaryTreeNode *Root)
{
   while(Root->Left!= NULL)
    Root = Root->Left;   
   return Root->data;
}
void BinaryTree :: Display(BinaryTreeNode *Root)
{
    BinaryTreeNode *Root1;
    cout<<" Root Node: "<<Root->data<<endl;
    cout<<"Elements in the Left of Root Node: "<<endl;   
    Root1 = Root;
    while(Root1!=NULL)
    {
        cout<<Root1->data<<"-->";
        Root1 = Root1->Left;
    }
    cout<<"\nElements in the Right of Root Node: "<<endl;
    Root1 = Root;
    while(Root1!=NULL)
    {
        cout<<Root1->data<<"-->";
        Root1 = Root1->Right;
    }    
}
int main()
{
    BinaryTreeNode *Root,*Value,*Swap;
    BinaryTree BTree;
    int choise,data,nodes,search,min;
    do
    {
       cout<<"Enter your choise for operation on BinaryTree: "
       <<"\n1 : Insert elements "
       <<"\n2 : Search element "
       <<"\n3 : Search smallest element "
       <<"\n4 : Swap the left right tree "
       <<"\n5 : Display the content "
       <<"\n6 : Display Swap Content "
       <<"\n7 : Exit "<<endl;
    
    cin>>choise;
    
    switch(choise)
    {
     case 1:
       cout<<"Enter how many nodes in the Binary Tree: "<<endl;
       cin>>nodes;
       cout<<"Enter data to nodes: "<<endl;
        for(int i=0;i<nodes;++i)
        {
          cin>>data;
          Root = BTree.insert(Root , data);
        }
        Swap = Root;
        break;
     
     case 2:
      cout<<"Enter the element to be search: "<<endl;
      cin>>search;
      Value = BTree.Search(Root,search);
      if(Value == NULL)
       {
           cout<<"Element is not fount: "<<endl;
           return 0;
       }
       else
        cout<<"!!!!!!!!!!!Element is found!!!!!!!!!!"<<endl;
        break;
        
     case 3:
          min = BTree.min(Root);
          cout<<"Minimum Number is: "<<min<<endl;
          break;
          
     case 4:
         Value = BTree.SwapLR(Swap);
        break;
        
     case 5:
          BTree.Display(Root);
          break;
          
    case 6:
          BTree.Display(Swap);
          break;
    
     default:
         cout<<"Thank You "<<endl;
    }
    }while(choise!=7);
}
