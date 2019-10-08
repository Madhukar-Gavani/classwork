// Example program
#include <iostream>
#include<cstring>
using namespace std;
void check(char*,char[]);
//int n;
int main(){
    char user[50];
     char equation[50];
    cout<<"Enter your expression : "<<endl;
    cin.getline(equation,50);
    // cout<<"String is "<<equation<<endl;
    check(equation,user);
}
void check(char* equation ,char user[])
{
    int front,rear;
    front = rear=0;
    while(*equation !='\0'){
    if(*equation == '{' )
     { 
         user[front] = *equation;
         ++front;
     }
    ++equation;
    }
    while(*equation !='\0'){
    if(*equation == '}' )
     { 
         user[front + rear] = *equation;
         ++rear;
     }
    ++equation;
    }
    if(front == rear)
     cout<<"Equation is balanced "<<endl;
     else
     cout<<"Equation is unbalanced "<<endl;
     
     
}
