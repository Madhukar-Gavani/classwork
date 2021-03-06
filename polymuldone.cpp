#include<iostream>
using namespace std;
struct polynomial
{
    int coefficient;
    int exponent;
}poly1[10],poly2[10],poly3[10];

int getvalues(polynomial poly[]);
int multiplication(polynomial poly1[],polynomial poly2[],int ,int, polynomial poly3[]);
void display(polynomial poly[],int);

int main()
{
    int term1=0,term2=0,term3=0;
    cout<<"Enter your first polynomial term "<<endl;
    term1 = getvalues(poly1);
    cout<<"your First polynomial is:"<<endl;
    display(poly1,term1);

    cout<<"\nEnter your second polynomial term "<<endl;
    term2 = getvalues(poly2);
    cout<<"your Second polynomial is:"<<endl;
    display(poly2,term2);

    term3 = multiplication(poly1,poly2,term1,term2,poly3);
     cout<<"\nyour Multiplication of two polynomial terms is:"<<endl;
    display(poly3,term3);

}

int getvalues(polynomial poly[])
{

    int i=0,terms=0;
    cout<<"Enter number of terms in your polynomial term:"<<endl;
    cin>>terms;
    cout<<"Enter coefficient and exponent of polynomial: "<<endl;

    for(i=0;i<=terms-1;++i)
    {
        cout<<"Enter coefficient "<<i+1<<":";
        cin>>poly[i].coefficient;
        cout<<"Enter exponent "<<i+1<<":";
        cin>>poly[i].exponent;
    }
    return terms;
}

int multiplication(polynomial poly1[],polynomial poly2[],int term1 ,int term2, polynomial poly3[])
{
    int i=0,j=0,k=0,l=0,t=0,ctr=0,t1=0;
    for(i=0;i<=term1-1;++i)
       for(j=0;j<=term2-1;++j)
        {        
                 poly3[l].exponent = poly1[i].exponent + poly2[j].exponent;
                poly3[l].coefficient = poly1[i].coefficient * poly2[j].coefficient;
                 ++l;
        }
  i=j=0;
   while(i<l-1)
  {
      ctr=0;
      t1=0;
      j=i+1;
    while(j<l)
    { 
         
         if(poly3[i].exponent == poly3[j].exponent)
         {
              poly3[k].coefficient = poly3[i].coefficient + poly3[j].coefficient; 
               poly3[k].exponent = poly3[i].exponent; 
               if(ctr==0){
               ++k;}
               ctr++;
               
          }
          else 
          {
              ++t;
          }
          if(t == l-(i+1))
            {
                for(int n=1;n<i;++n){
               if(poly3[i].exponent == poly3[n].exponent)
                  t1=1;}
                if(t1==1)break;
                poly3[k].coefficient = poly3[i].coefficient; 
                poly3[k].exponent = poly3[i].exponent; 
                ++k;
            }
            
            if(k==term1+term2+1)
               break;
    ++j;        
   }
   if(k==term1+term2+1)
               break;
   t=0;
   ++i;
  }
  
  poly3[k].coefficient = poly3[i].coefficient; 
  poly3[k].exponent = poly3[i].exponent;
   return k+1;
   
}
void display(polynomial poly[],int terms)
{
    int i=0;
    for(i=0;i<terms;++i)
    {
        for(int j=0;j<terms-1;++j)
        {
            if(poly[j].exponent<poly[j+1].exponent)
            {
                polynomial temp;
                temp = poly[j];
                poly[j] =poly[j+1];
                poly[j+1] = temp;
            
            }
        }
    }
    for(int i=0;i<=terms-1;++i)
          {
             if(poly[i].coefficient<0)
             cout<<poly[i].coefficient<<"x^"<<poly[i].exponent<<"";
             else if(poly[i].coefficient>0 && i>0)      //if(poly[i].coefficient<0)
            cout<<"+"<<poly[i].coefficient<<"x^"<<poly[i].exponent;
            else
            cout<<poly[i].coefficient<<"x^"<<poly[i].exponent<<"";
         }
}
