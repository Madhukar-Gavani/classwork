#include <iostream>
using namespace std;
void pushqueue(int[],int);
void popqueue(int[],int);
void top(int[],int);
void display(int[],int,int);
bool isfull(int);
bool isempty(int);
int n;
int main(){
    int front,rear,choise,user[20];
   front = rear = -1;
    cout<<"Enter how many number you going to enter: "<<endl;
    cin>>n;
    do{
        
    cout<<"\nWhich operartion you want to perform?"
        <<"\nEnter 1 : push elements"
        <<"\nEnter 2 : pop elements"
        <<"\nEnter 3 : top of element"
        <<"\nEnter 4 : display"
        <<"\nEnter 5 : Exit"<<endl;
        
    cin>>choise;
    switch(choise)
    {
        case 1 : if(front == -1)
                {
                    ++front;
                    ++rear;
                }
                pushqueue(user,front);
                ++front;
                break;
        case 2 :
                popqueue(user,rear);
                ++rear;
                break;
                 
        case 3 :
                 top(user,rear);
                 break;
        case 4 :display(user,front,rear);
        break;
       default:cout<<"Thank you"<<endl;
    }
    }while(choise!=5);
}
void top(int user[],int rear)
{
    cout<<"The next element is: "<<user[rear]<<endl;
}
bool isfull(int var)
{
    if(n== var)
        return 1;
        else
        return 0;
}
void pushqueue(int user[],int front)
{
    if(isfull(front))
    {
        cout<<"your queue is full: "<<endl;
        return;
    }
    int element;
    cout<<"Enter element: "<<endl;
    cin>>element;
    user[front] = element;
}
bool isempty(int var)
{
    if(n ==var||var == -1)
    return 1;
    else 
    return 0;
}
void popqueue(int user[],int rear)
{
    if(isempty(rear))
      {
          cout<<"your queue is empty:"<<endl;
          return;
      }
    cout<<"Poped element is: "<<user[rear]<<endl;
}
void display(int user[],int front,int rear)
{
    cout<<"The number of elements are "<<endl;
    for(int i=rear;i<front;++i)
        cout<<user[i]<<"  ";
    cout<<endl;
}
