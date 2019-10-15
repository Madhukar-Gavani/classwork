#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream file("sample.txt");
    if(file.is_open())
    {
        cout<<"File is not created"<<endl;
        return 0;
    }
    cout<<"Write in the file"<<endl;
    file<<"!!!!!!Hello world!!!!!! from file"<<endl;
    file<<" Good day  "<<endl;
    file.close();
    ifstream myfile;
    string ch;
    myfile.open("sample.txt",ios::in);
if(myfile)
    {
        cout<<"File is not created"<<endl;
        return 0;
    }
    while(getline(myfile,ch))
    {
        cout<<ch<<endl;
    }
    myfile.close();
}
