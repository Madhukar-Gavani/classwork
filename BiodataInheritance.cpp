#include<iostream>
using namespace std;
class Personal
{
   int Mobile_number;
   string name,address,gender;
   public:
    Personal()
   {         
      Mobile_number=0;
    }
    void getData();
    void putData();  
};

void Personal :: getData()
{
   cout<<"Enter your name: "<<endl;
   cin>>name;
   cout<<"Enter gender : "<<endl;
   cin>>gender;
   cout<<"Enter address : "<<endl;
   cin>>address;
}
void Personal :: putData()
{
   cout<<"Name     : "<<name<<endl;
   cout<<"Gender  : "<<gender<<endl;
   cout<<"Address : "<<address<<endl;
   
}
class Professional
{
   string languageK,extKTech;
   int experience;
  public:
  Professional(){experience=0;}
  void getData();
  void putData();
  
};
void Professional :: getData()
{
   cout<<"Enter Known Programming language: "<<endl;
   getline(cin,languageK);
   cout<<"Enter how many experience with Programming language : "<<endl;
   cin>>experience;
   cout<<"Which extra activity other than PL you did : "<<endl;
   getline(cin,extKTech);
}
void Professional :: putData()
{
    cout<<"Known Programming language: "<<languageK<<endl;
   cout<<"Experience with Programming language : "<<experience<<endl;
   cout<<"Extra activity : "<<extKTech<<endl;
   
}
class Academic
{
    string Degree;
    float percentile,SSC,HSC;
    public:
    Academic(){
    percentile=0,SSC=0,HSC=0;}
    void getData();
    void putData();
    
};    
void Academic :: getData()
{
      cout<<"Enter your HSC/CBSC result : "<<endl;
      cin>>HSC;
      cout<<"Enter your SSC/CBSC result : "<<endl;
      cin>>SSC;
      cout<<"Which Degree you have : "<<endl;
      cin>>Degree;
      cout<<"Enter your Degree percentile : "<<endl;
      cin>>percentile;
}
void Academic :: putData()
{
      cout<<"HSC/CBSC result : "<<HSC<<endl;
      cout<<"SSC/CBSC result : "<<SSC<<endl;
      cout<<"Degree : "<<Degree<< "\n" <<"percentile : "<<percentile<<endl;
      
}
class CV : public Personal,public Professional,public Academic
{
string Title;
public:
 void getData();
  void putData();
};
void CV :: getData()
{
  cout<<"Enter Title of your CV : "<<endl;
  getline(cin,Title);
  cout<<"Enter you personal data: "<<endl;
    Personal::getData();
    cout<<"Enter your Professional data: "<<endl;
    Professional::getData();
    cout<<"Enter your Academic data: "<<endl;
    Academic::getData();
}
void CV :: putData()
{
  cout<<"Enter Title of your CV : "<<Title<<endl;
  cout<<"Personal data: "<<endl;
    Personal::putData();
    cout<<"Professional data: "<<endl;
    Professional::putData();
    cout<<"Academic data: "<<endl;
    Academic::putData();
}
int main()
{
  CV cv;
  cout<<"Enter your Information: "<<endl;
   cv.getData();
   cout<<"your entered Information is: "<<endl;
   cv.putData();
   cout<<"Size of CV is : "<<sizeof(cv)<<endl;
}
