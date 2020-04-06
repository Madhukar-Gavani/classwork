#include<iostream>
using namespace std;

struct AVLTree
{
    int data;
    AVLTree *Left;
    AVLTree *Right;
    int height;
};

int BalanceFactor(AVLTree *node)
{
    int RH ,LH;
    if(node->Right == NULL)
      RH = 0;
    else
     RH = 1 + node->Right->height;
    
    if(node->Left == NULL)
      LH = 0;
    else
     LH = 1 + node->Left->height; 
    
  return (LH - RH);
}
int height(AVLTree *node)
{
    int RH , LH;
    if(node->Right == NULL)
      RH = 0;
    else
     RH = 1 + node->Right->height;
     
     if(node->Left == NULL)
      LH = 0;
    else
     LH = 1 + node->Left->height; 
    
    if(LH > RH)
       return LH;
   return RH;       
}
AVLTree *RotateRight(AVLTree *node)
{
    AVLTree *temp;
    temp = node->Left;
    node->Left = temp->Right;
    temp->Right = node;
    temp->height = height(temp);
    node->height = height(node);
    
    return temp;
}
AVLTree *RotateLeft(AVLTree *node)
{
    AVLTree *temp;
    temp = node->Right;
    node->Right = temp->Left;
    temp->Left = node;
    temp->height = height(temp);
    node->height = height(node);
    
    return temp;
}

AVLTree *insert(AVLTree *node , int data)
{
    if(node == NULL)
    {
        node = new AVLTree;
        node->data = data;
        node->Left = NULL;
        node->Right = NULL;
        node->height = 0;
    }
    else if(data<node->data)
     {
         node->Left = insert(node->Left , data);
          if(BalanceFactor(node) == -2)
             node = RotateLeft(node);
     }
    else if(data > node->data)
     {
         node->Right = insert(node->Right , data);
           if(BalanceFactor(node) == 2)
             node = RotateRight(node);
     }

        return node;     
}
void Display(AVLTree *node)
{
    if(node != NULL)
    {
        Display(node->Left); 
        cout<<"\tElements: "<<node->data;
        Display(node->Right);
     }
     cout<<endl;
}
int Search(AVLTree *node , int data)
{
    if(node == NULL)
      return 0;
    if(node->data == data)
      return 1;
    else if(data<node->data)
       return(Search(node->Left),data);
    else 
      return(Search(node->Right),data);
}
int main()
{
    int data,n;
    AVLTree *Root;
    do
    {
        cout<<"Enter your choise: "
            <<"\n1 : Insert element "
            <<"\n2 : Display contents "
            <<"\n3 : Search "
            <<"\n4 : Exit "<<endl;
            cin>>n;
            
        switch(n)
        {
            case 1 :
                   cout<<"Enter data to node: "<<endl;
                   cin>>data;
                   Root = insert(Root , data);
                   
                break;
            
            case 2 :
                    Display(Root);
                break;
            case 3:
                  cout<<"Enter Search element "<<endl;
                  cin>>data;
                 if(Search(Root,data))
                   cout<<"Element is found: "<<endl;
                 else
                   cout<<"Element is not found: "<<endl;
                break;
       
            case 4:
                cout<<"Thank you "<<endl;
             
        }
    }while(n!=4);
}