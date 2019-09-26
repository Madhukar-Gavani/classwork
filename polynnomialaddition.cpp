#include<iostream>
using namespace std;
struct  polynomial
      {
           int  coefficient;
           int  exponent;
      }poly1[10],poly2[10],poly3[10];
      
 int getvalues(struct polynomial poly[]);    
 int addition( polynomial poly1[],polynomial poly2[],int ,int ,polynomial poly3[])  ;
 void display(polynomial poly1[],int);
 int terms;

int main()
{
     int term1=0,term2=0,term3=0;
      cout<<"Enter first polynomial function poly1: "<<endl;
      term1 = getvalues(poly1);
      display(poly1,term1);
      terms =0;
      cout<<"Enter second polynomial function poly2: "<<endl;
      term2 = getvalues(poly2);

       display(poly2,term2);

      term3 = addition(poly1,poly2,term1,term2,poly3);
      display(poly3,term3);
      
}

int  getvalues(polynomial poly[])
{   
     int term;
    cout<<"Enter the terms of polynomial: "<<endl;
     cin>>term;
       cout<<"Enter the coefficient and exponent terms of the polynomial = "<<endl;
    for(int i=0;i<=term-1;++i)
     {
        cout<<"Enter coefficient " <<i<<": ";
       cin>>poly[i].coefficient;
        cout<<"Enter exponent"<<i<<": ";
        cin>>poly[i].exponent;
     
     }
       return term;
}          

int addition(polynomial poly1[] , polynomial poly2[], int term1,int term2,polynomial poly3[])
{
   int i=0,j=0,k=0;
   while(i<=term1 && j<=term2)
   {
         if(poly1[i].exponent == poly2[j].exponent)
         {
              poly3[k].coefficient = poly1[i].coefficient + poly2[j].coefficient; 
               poly3[k].exponent = poly1[i].exponent; 
              ++i,++j,++k;
          }
          else if(poly1[i].exponent > poly2[j].exponent)
          {
                poly3[k].coefficient = poly1[i].coefficient; 
                poly3[k].exponent = poly1[i].exponent; 
                ++i,++k;
          }
          else 
          {
                poly3[k].coefficient = poly2[j].coefficient; 
                poly3[k].exponent = poly2[j].exponent; 
                 ++j,++k;
          }
   }
   while(i < term1)
   {
          poly3[k].coefficient = poly1[i].coefficient;
         poly3[k].exponent = poly1[i].exponent; 
          ++i,++k;
   } 
   while(j < term2)
   {
          poly3[k].coefficient = poly2[j].coefficient;
          poly3[k].exponent = poly2[j].exponent; 
          ++j,++k;
   }
   return k-1;
   }
   
   
   void display(polynomial poly[],int term)
   {
   int i;
       cout<<"Your output is:"<<endl;
       for( i=0;i<=term-1;++i)
       {
             cout<<poly[i].coefficient<<"x^"<<poly[i].exponent;
             if(i!=term-1)
              cout<<" + ";
             else
             cout<<" "<<endl;
             }
   }
