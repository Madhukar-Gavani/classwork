#include<iostream>
using namespace std;
int main()
{
  long int  UserArray[100];
  int n,ctr,number,j,i;  
  bool d=0;
  cout<<"Linear search"<<endl;
    
    cout<<"enter the how students who attended for training program  "<<endl;
    cin>>n;
    cout<<"Enter the Roll number of students  "<<endl;
  
    for(i=0;i<n;++i)
    cin>>UserArray[i];
  
   cout<<"Enter Roll number of student you want search: "<<endl;
   cin>>number;
   
   for(j=0;j<n;++j)
   {
       ctr++; 
       if(UserArray[j] == number)
      { 
        d =1;
        cout<<number<<"This student is attened for training program:"<<endl;
        break;
      }
   
   }
   
   if(!d)
   cout<<"The Student is not attened for traning program "<<endl; 
 
}  
