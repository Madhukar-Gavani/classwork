#include<iostream>
using namespace std;
int setA[20],setB[20],setC[20],setU[20];
int main()
{
    int i=0,j=0,k=0,g=0,ctr=0;
    int no_A=0,no_B=0,no_U=0;
   
    cout<<"Enter the number of students of whole class:";
    cin>>no_U;
    cout<<"\nEnter the roll number of all students of the class :";
    for(i=0;i<no_U;++i)
    cin>>setU[i];
   
    cout<<"Enter the number of students who play cricket:";
    cin>>no_A;
    cout<<"\nEnter the roll number of students who play cricket:";
    for(i=0;i<no_A;++i)
    cin>>setA[i];
    
    cout<<"Enter the number of students who play badminton:";
    cin>>no_B;
    cout<<"\nEnter the roll number of students who play badminton:";
    for(i=0;i<no_B;++i)
    cin>>setB[i];
    
     //for  A  interSection B
    cout<<"\nNumber of students who play both cricket and badminton are: ";
     for(i=0;i<no_A;++i)
           for(j=0;j<no_B;++j)
               if(setA[i] ==setB[j])
                {
                   setC[k]=setB[j];
                   ++k;
                }
             
       for(i=0;i<k;++i)
       cout<<setC[i]<<"        ";
       
       //for   A union   B
         cout<<"\nNumber of students who play either cricket or badminton or both are: ";
         for(i=0;i<no_A;++i,++g)
             setC[g]=setA[i];
               
               for(j=0;j<no_B;++j)
             {
                      for(i=0;i<no_A;++i)
                          if(setB[j] == setC[i])
                            ctr = 1;
                     
                     if(ctr == 0)
                    {
                         setC[g] = setB[j];
                         ++g; 
                     }
                     ctr=0;
              }
       for(i=0;i<g;++i)
       cout<<setC[i]<<"        ";    
       
       //U - (A' intersection B')
        cout<<"\nNumber of students who play nither cricket nor badminton are: ";
        ctr = 0;g=0;
        int setD[20];
       for(i=0;i<no_U;++i)
          {
               for(j=0;j<no_C;++j)
                  if(setU[i] == setC[j])
                     ctr = 1;
                
                if(ctr == 0)
                {
                  setD[g] = setU[i];
                    ++g; 
                }
                ctr=0;
         }
        
       for(i=0;i<g;++i)
       cout<<setD[i]<<"        ";  
      
       // for   A  -   B
       cout<<"\nNumber of students who play only cricket are: ";
        ctr = 0;g=0;
       for(i=0;i<no_A;++i)
          {
               for(j=0;j<no_B;++j)
                  if(setA[i] == setB[j])
                     ctr = 1;
                
                if(ctr == 0)
                {
                  setC[g] = setA[i];
                    ++g; 
                }
                ctr=0;
         }
        
       for(i=0;i<g;++i)
       cout<<setC[i]<<"        ";    
       
       //for B - A
       cout<<"\nNumber of students who play only badminton are: ";
         ctr = 0;g=0;
       for(i=0;i<no_B;++i)
          {
               for(j=0;j<no_A;++j)
                  if(setB[i] == setA[j])
                     ctr = 1;
                
                if(ctr == 0)
                {
                  setC[g] = setB[i];
                    ++g; 
                }
                ctr=0;
         }
        
       for(i=0;i<g;++i)
       cout<<setC[i]<<"        ";      
         
}

