#include<iostream>
using namespace std;
template<typename T>
void SelectionSort(T user[],int n)
{
    int i,j,min,temp;
     for(i=0;i<n;++i)
     {
         min = i;
         for(j=i+1;j<n;++j)
         {
             if(user[min]<user[j])
               min = j;
         }
         temp = user[min];
         user[min]=user[i];
         user[i]=temp;
     }
     
}
int main()
{
    int user[10],i,j,min,n,temp;
    cout<<"Enter how many elements you going to enter: "<<endl;
    cin>>n;
    cout<<"Enter elements :"<<endl;
    for(i=0;i<n;++i)
    cin>>user[i];
    SelectionSort(user,n);
     //Selection Sort
    cout<<"sorted elements are: "<<endl;
     for(i=0;i<n;++i)
     cout<<user[i]<<"    ";
     cout<<endl;
 }
