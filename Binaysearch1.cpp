#include<iostream>
using namespace std;
int main()
{
   int temp, n,mid,first,search,last,i,j;
   long int UserArray[100];
   cout<<"enter the how students who attended for training program "<<endl;
   cin>>n;
   
   cout<<"Enter the Roll number of students "<<endl;
   for(i=0;i<n;++i)
   cin>>UserArray[i];
   
   for(i=0;i<n;++i)
   {
          for(j=0;j<n;++j)
          {
              if(UserArray[j]>UserArray[j+1])
              {
                 temp = UserArray[j];
                 UserArray[j]=UserArray[j+1];
                 UserArray[j+1]=temp;
              }
          }
    }
    
    cout<<"your shorted list of students is: "<<endl;
    
    for(i=0;i<n;++i)
    cout<<UserArray[i]<<" "<<endl;
    
    cout<<"Enter Roll number of student you want search: "<<endl;
    cin>>search;
    
    first = 0;last = n-1;mid = (first + last)/2;
    
    while(first<=last)
    {
       if(UserArray[mid] == search){
       cout<<search<<"This student is attened for training program: "<<endl;break;}
       else if(UserArray[mid] < search)
       first = mid + 1;
       else if(UserArray[mid] > search)
       last = mid-1;
       
       mid = (first + last)/2;
    }
     
     if(first > last)
     cout<<" The Student is not attened for traning program "<<endl;
}

student@admin1-W52K55:~$ cd Documents
student@admin1-W52K55:~/Documents$ cd all1836
student@admin1-W52K55:~/Documents/all1836$ la
allmatrix.cpp             BubbleSort.cpp            SelectionSort.cpp
allmatrix.cpp~            diagonal.cpp              SelectionSort.cpp~
a.out                     functionBandL1.cpp        settheory.cpp
BandL.cpp                 functionBandL.cpp         settheory.cpp~
BandL.cpp~                LinearSearch1.cpp         settheoryUniversal.cpp
BinarySearch.cpp          LinearSearch1.cpp~        settheoryUniversal.cpp~
Binaysearch1.cpp          LinearSearch.cpp          stack.cpp
Binaysearch1.cpp~         matrix.cpp                stack.cpp~
bothBandL.cpp             matrixmul.cpp             stringOpreation.cpp
BubbleSelectionSort.cpp   polynnomialaddition.cpp   stringOpreation.cpp~
BubbleSelectionSort.cpp~  polynnomialaddition.cpp~
student@admin1-W52K55:~/Documents/all1836$ g++ Binaysearch1.cpp
student@admin1-W52K55:~/Documents/all1836$ ./a.out
enter the how students who attended for training program 
2
Enter the Roll number of students 
23
25
your shorted list of students is: 
1 
23 
Enter Roll number of student you want search: 
23
23This student is attened for training program: 
student@admin1-W52K55:~/Documents/all1836$ 

