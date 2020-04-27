#include<iostream>
#include<exception>
using namespace std;
class age_exception:public exception
{
  public:
  const char *what() const throw()
{
return"age is not betn 18 and 55/n";
}
};
class income_exception:public exception
{
 public:
 const char *what() const throw()
 {
  return"income is not betn 50000 and 100000";
 } 
};
 class city_exception:public exception
 {
 public:
 const char *what() const throw()
 {
 return"city is not pune, chennai, banglore, mumbai";
 } 
 };
 class vehicle_exception:public exception
 {
 public:
 const char *what() const throw()
 {
return"vehicle is not 4 wheler";
 
 }
 };
  
int main()
{
int age,income,wheel;
string city;
try
{
cout<<"enter person age";
cin>>age;
if(age<18||age>55)
{
age_exception ae;
throw ae;
}
else
{cout<<"age="<<age<<endl;
} 
cout<<"enter person income";
cin>>income;
if(income<50000||income>100000)
{ 
income_exception ae;
throw ae;
}
else
{cout<<"income="<<income<<endl;
}
cout<<"enter how many wheel"<<endl;
cin>>wheel;
if(wheel!=4)
{
vehicle_exception ae;
throw ae;
}
else
{cout<<"vehicle="<<wheel;
}
cout<<"enter city";
cin>>city;
if(city!="pune"&& city!="mumbai"&&city!="chennai"&&city!="banglore")
{
city_exception ae;
throw ae;
}
else
{
cout<<"city="<<city<<endl;
}}
catch(exception &e)
{
cout<<e.what()<<endl;
}}
/*
**************Output*************
enter person age25
age=25
enter person income65000
income=65000
enter how many wheel
4
vehicle=4enter citypune
city=pune
************************************
enter person age25
age=25
enter person income65222
income=65222
enter how many wheel
4
vehicle=4enter citynagpur
city is not pune, chennai, banglore, mumbai
jemifi3678@tgres24.com
free code camp gmail
*/
