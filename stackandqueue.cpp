#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void display(stack<int>);
void showqueue(queue<int>);
int main()
{
    stack<int>s1;
    s1.push(100);
    s1.push(20);
    s1.push(30);
    s1.push(1);
    
    display(s1);
   cout<<"Size of stack container is: "<<s1.size()<<endl;
   
   cout<<"Queue is started "<<endl;
    queue<int>que;
    que.push(100);
    que.push(12);
    que.push(11);
    que.push(10);
    
    cout<<"The queue of que is: ";
    showqueue(que);
    cout<<"Front of queue is: "<<que.front()<<endl;
    cout<<"Back of queue is: "<<que.back()<<endl;
    cout<<"End of program: "<<endl;
}
void display(stack<int>s1)
{
    while(!s1.empty())
    {
        cout<<"   "<<s1.top();
        s1.pop();
    }
    cout<<endl;
}
void showqueue(queue<int>que)
{
    queue<int>qu = que;
    while(!qu.empty())
    {
        cout<<"\t "<<qu.front();
        qu.pop();
    }
    cout<<endl;
}
