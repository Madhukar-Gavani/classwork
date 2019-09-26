#include<iostream>
using namespace std;

void multiplicaton(int ,int ,int AMatrix[][10], int BMatrix[][10]);
void addition(int ,int  ,int b[][10]  ,int c[][10]);
void subtraction(int b,int d,int h1[][10] ,int v1[][10]);
void transpose(int , int ,int a[][10]);
void diagonal(int , int ,int a[][10]);
int input(int i, int j);

int p,q ,i,j;
int AMatrix[10][10],BMatrix[10][10],ansMatrix[10][10];
bool tran= 0, switc=0,roco=0,diago=0;

int main()
{
    int a,j1,i1;
        
         cout<<"which operation you want to perform "
              <<"\naddition        type    :- 0 "
              <<"\nsubtraction     type    :- 1 "
              <<"\nTranspose       type    :- 2 "
              <<"\nMultiplication  type    :- 3 "
              <<"\nDiagonal element type   :- 4 "<<endl;
          cin>>a;
          
         switch(a)
         {
         
          case 0:
                 cout<<"Enter the row and column for matrix A:"<<endl;
                 cin>>i1>>j1;
                 AMatrix[i1][j1] = input(i1,j1);
                 cout<<" Enter the row and column for matrix B:"<<endl;
                 cin>>i>>j;
                 BMatrix[i][j] = input(i,j);
                 addition(i,j,AMatrix,BMatrix);
                   break;
         
          case 1:
                  cout<<"Enter the row and column for matrix A:"<<endl;
                  cin>>i1>>j1;
                  AMatrix[i1][j1] = input(i1,j1);
                  cout<<" Enter the row and column for matrix B:"<<endl;
                  cin>>i>>j;
                  BMatrix[i][j] = input(i,j);
                  
                  subtraction(i,j,AMatrix,BMatrix);
                  break;
         
          case 2: 
                  cout<<"which Matrix you want to transpose "
                      <<"\nAMatrix type :- 1"
                      <<"\nBMatrix type :- 2"<<endl;
                 
                  cin>>p;
                 
                 if(p==1)
                  {
                    cout<<"Enter the row and column for matrix A:"<<endl;
                    cin>>i1>>j1;
                    AMatrix[i1][j1] = input(i1,j1);
                   transpose(i1,j1,AMatrix);
                  }
                  else if(p==2)
                  {
                    cout<<"Enter the row and column for matrix B:"<<endl;
                    cin>>i>>j;
                    BMatrix[i][j] = input(i,j);
                    transpose(i,j,BMatrix);
                  }
                 else
                 { 
                 
                   cout<<"wrong input,Please try again"<<endl;
                   tran=1;
                 }
                 
                 break;
            
          case 3: 
                 cout<<"Enter the row and column for matrix A:"<<endl;
                 cin>>i1>>j1;
                AMatrix[i1][j1] = input(i1,j1);
                 cout<<" Enter the row and column for matrix B:"<<endl;
                 cin>>i>>j;
                BMatrix[i][j] = input(i,j);
                 
                 multiplicaton(j1,j,AMatrix,BMatrix);       
                  break;
               
          case 4:
                  cout<<"which Matrix diagonal you want "
                      <<"\nAMatrix type :- 1"
                      <<"\nBMatrix type :- 2"<<endl;
                 
                  cin>>p;
                 
                 if(p==1)
                  {
                    cout<<"Enter the row and column for matrix A:"<<endl;
                    cin>>i1>>j1;
                    AMatrix[i1][j1] = input(i1,j1);
                    diagonal(i1,j1,AMatrix);
                 
                  }else if(p==2)
                  {
                    cout<<"Enter the row and column for matrix B:"<<endl;
                    cin>>i>>j;
                    BMatrix[i][j] = input(i,j);
                  
                    diagonal(i,j,BMatrix);
                 }
                 else
                 { 
                   cout<<"wrong input,Please try again"<<endl;
                   diago=1;
                 }
                 
                 break;
          
          default:cout<<"Wrong input, Please try again "<<endl;
                   switc=1;
          
          }//switch
        
        
 
 
  
} //main

int input(int i, int j)
{ 
    int Matrix[10][10];
     
      for(p=0;p<i;++p)
        for(q=0;q<j;++q)
          cin>>Matrix[p][q];
     
                return Matrix[i][j];
}           
           
void addition(int i,int j,int AMatrix[][10], int BMatrix[][10])
{
 
  for(p=0;p<i;++p)
     for(q=0;q<j;++q)
     ansMatrix[p][q] = AMatrix[p][q] + BMatrix[p][q];
     
    
    for(p=0;p<i;++p)
    {
       for(q=0;q<j;++q)
       cout<<ansMatrix[p][q]<<" ";
    
      cout<<endl;
    }
    switc =0;

}//addition

void subtraction(int i,int j,int AMatrix[][10],int BMatrix[][10])
{

  for(p=0;p<i;++p)
     for(q=0;q<j;++q)
     ansMatrix[p][q] = AMatrix[p][q] - BMatrix[p][q];
     
    
    for(p=0;p<i;++p)
    {
        for(q=0;q<j;++q)
        cout<<ansMatrix[p][q]<<"  ";
     
     cout<<endl;
     }
     switc=0;
}//subtraction

void transpose(int i,int j,int Matrix[][10])
{
 
     for(p=0;p<i;++p)
       for(q=0;q<j;++q)
        ansMatrix[p][q] = Matrix[q][p];
        
     
    for(p=0;p<i;++p)
    {
        for(q=0;q<j;++q)
        cout<<ansMatrix[p][q]<<" ";
     
     cout<<endl;
     }
     tran=0;
     switc=0;
}//transpose   

void multiplicaton(int i,int j,int AMatrix[][10], int BMatrix[][10])
{
 
  for(p=0;p<i;++p)
     for(q=0;q<j;++q)
      for(int r=0;r<i;++r) 
        ansMatrix[p][q] += AMatrix[p][r]*BMatrix[r][q];
     
    
    for(p=0;p<i;++p)
    {
       for(q=0;q<j;++q)
       cout<<ansMatrix[p][q]<<" ";
    
      cout<<endl;
    }

}//multiplication  
void diagonal(int i,int j,int Matrix[][10])
{
     int ans[10];
     for(p=0;p<i;++p)
       for(q=0;q<j;++q)
          if(p==q)
            ans[p] = Matrix[p][q];
     
    for(p=0;p<i;++p)
        cout<<ans[p]<<endl;
     
     
     diago=0;
     //switc=0;
}//diagonal 
   
