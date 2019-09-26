#include<iostream>
using namespace std;
void push(int [],int,int );
void pop(int [],int,int );
void display(int [],int);
int n,stack[50];
int main()
{
     int counter=0,n1,i,choise=0,increment=0;
     cout<<"Enter the size of stack:"<<endl;
     cin>>n;
     stack[0]=0;
 do{    
     cout<<"Which operation you want to perform"
             <<" 1  : push "
             <<" 2  : pop   "
             <<" 3  : exit    "<<endl;
     cin>>choise;
     switch(choise)
     {
          case 1 :push(stack,n,increment);
                         ++increment;
                         break;
                         
           case 2:  
                         for(int i=0;i<increment;++i)
                         {
                              if(stack[i] == 0)
                               counter =0;
                               else
                               counter =1;
                         }
                         pop(stack,counter,increment);
                        --increment;
                         break;
                         
             case 3: choise =3;
             break;
           default : cout<<"Enter the  correct choise:"<<endl;
             
       }
    }while(choise!=3);
    cout<<"OUT"<<endl;
}
void push(int stack[],int n,int increment)
{
      cout<<"Enter the value of stack"<<endl;
      cin>>stack[increment];
     if(increment == n)
       cout<<"Stack is overflow "<<endl;

}

void pop(int stack[],int increment)
{
     int i;
    
     cout<<"stack is underflow "<<endl;
     cout<<"The stack after one pop is:"<<endl;
     for(i=increment-1;  i!=0;  --i)
       {
             if(i==0)
               cout<<"stack is underflow "<<endl;
             else
            cout<<stack[i]<<"     ";
      }
}
 /*void display(int stack[],int n1)
 {
      int i=1;
      bool choise=0;
         if(n1==0)
        cout<<"Stack is underflow"<<endl;
      else
      {
         for(i=1;i<=n1;++i)
         cout<<stack[i]<<"    ";
      }
      cout<<"If you want to print hole number then enter 1:"<<endl;
      cin>>choise;
      if(choise)
        {
         for(i=1;i<=n;++i)
         cout<<stack[i]<<"    ";
      }
      else 
      0;
 }*/
