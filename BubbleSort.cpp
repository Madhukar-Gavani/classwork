#include<iostream>
using namespace std;
int main()
{
   int UserInput[50],n,i,j,temp;
   cout<<"Enter the number of elements: "<<endl;
   cin>>n;
   cout<<"enter the elements: "<<endl;
   for(i=0;i<n;++i)
    cin>>UserInput[i];
    
   for(j=0;j<n;++j)
   {
    for(i=0;i<n-1;++i)
      if(UserInput[i]>UserInput[i+1])
      {
        temp = UserInput[i];
        UserInput[i] = UserInput[i+1];
        UserInput[i+1] = temp;
       }
    }
    cout<<"Your sorted list is: "<<endl;
     for(i=0;i<n;++i)
    cout<<UserInput[i]<<" ";

}
