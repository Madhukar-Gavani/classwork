#include<iostream>
using namespace std;
struct node
{
    string bookname;
    node *left;
    node *right;
};
int main()
{
  string bookname;
  int sections,subsections,count=0;
  cout<<"Enter book name:"<<endl;
  cin>>bookname;
  cout<<"Enter how many section are there in the book: "<<endl;
  cin>>sections;
   node *child,*prevchild;
   node *parent = new node;
   parent->bookname = bookname;
   parent->left = NULL;
   parent->right = NULL;
  for(int i=0;i<sections;++i)
  {
    string section;
    cout<<"Enter name of section: "<<endl;
    cin>>section;
    cout<<"Enter where you want to enter section name left or right"
        <<"\n1: left"
        <<"\n2: right"<<endl;
     int choise;
     cin>>choise;
     if(choise == 1)
    {
      
      prevchild = child;
      child = new node;
      child->bookname = section;
      child->left = NULL;
      child->right = NULL;

      if(parent->left == NULL)
      {
        prevchild = child;
        parent->left = prevchild;
        count++;
       }
      else
      prevchild->left = child;
      

    }
    else if(choise == 2)
    {
       prevchild = child;
       child = new node;
      child->bookname = section;
      child->left = NULL;
      child->right = NULL;
      
      if(parent->right == NULL)
      {
        parent->right = child;
        count++;
      }
      else{
      prevchild->right  = child;
      }
    }
   else
      cout<<"You are enter wrong input from required data:"<<endl;
    
    cout<<"Enter sub section of book: "<<endl;
    cout<<"How many times you want to enter: "<<endl;
    int numbers;
    cin>>numbers;
   
    for(int i=0;i<numbers;++i)
   {
      
    cout<<"Where you want to enter sub-section of book:"
        <<"\n1:left  "
        <<"\n2:right "<<endl;
      int choise1;
      cin>>choise1;
      
     cout<<"Enter sub-section of book:"<<endl;
     string subsection;
      cin>>subsection;

      if(choise1 == 1)
       {
          node *subchild = new node;
          subchild->bookname = subsection;
          subchild->left = NULL;
          subchild->right = NULL; 
     
       }   
   
  }  
 }
   cout<<"The entered child data is:"<<parent->left->bookname<<endl;
   cout<<"The entered child data is:"<<parent->right->bookname<<endl;
}
