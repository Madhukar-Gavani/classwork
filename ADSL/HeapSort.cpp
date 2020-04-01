#include <iostream>
#include<cstring>
using namespace std;

struct Names
{
    string Name;//contains name of the person
    Names *Next;//if same names in slightly different manner
    int count;//counts of the nodes;
    int link;//link between names and numbers it contains index of numbers
    int Numbercount;//contains the counts of the numbers from index
};
Names *NamesArray[26];

struct Numbers
{
    long int Number;//contains the number
    int link;//contains index of Name
    int Namescount;//contains the counts of the names from index
    int count;//counts of the numbers of same hash functions output;
    Numbers *Next;//next nodes 
};
Numbers *NumbersArray[100];

int main()
{
    long int Number;
    char Name[20];
    char *pointer,*pointer1;
    Names *NewName;
    string name;
    int Nameindex=0,n;
    int position4th,position2nd,Numberindex;
    Numbers *NewNumbers;
    
    cout<<"Ente how many numbers to be entered: "<<endl;
    cin>>n;
    
    for(int i=0;i<n;++i)
    {
        cout<<"Enter the name: "<<endl;
        cin>>Name;
        cout<<"Enter the phone number of "<<Name<<": "<<endl;
        cin>>Number;
        
        //Store the name in Names array
        pointer = Name;
        
        for(int i=0;i<sizeof(Name);++i)
        {
            if(*pointer>'a' && *pointer<'z')
              *pointer = *pointer - 32;
          
            ++pointer;  
        }
        
        pointer1 = Name;
        
        if(*pointer1>='A' && *pointer1 <= 'Z')
        Nameindex = int(*pointer1)-65;//Hash function for names
      
        cout<<Nameindex;
        if(NamesArray[Nameindex] == NULL)
          {
              NewName = new Names;
              NewName->Name = (string)Name;
              NewName->Next = NULL;
              NamesArray[Nameindex] = NewName;
              NamesArray[Nameindex]->count = 1;
          }
        else
        {
              NewName = NamesArray[Nameindex];
              while(NewName!= NULL)
              NewName = NewName->Next;
             
             Names *NextName = new Names;
             NextName->Name = (string)Name;
             NextName->Next = NULL;
             NewName = NextName;
             ++NamesArray[Nameindex]->count;
      }
            
            //Store the Number in Number array using Hashing
            
            //get last two numbers
            position4th = Number%10000;
            position2nd = Number%100;
            position4th = position4th/100;
            Numberindex = (position4th + position2nd)%100;//Hash function for numbers
            
            cout<<"number index is "<<Numberindex;

            if(NumbersArray[Numberindex] == NULL)
              {
                  NewNumbers = new Numbers;
                  NewNumbers->Number = Number;
                  NewNumbers->link = Nameindex;
                  NewNumbers->Namescount = NamesArray[Nameindex]->count;
                  NewNumbers->Next = NULL;
                  NumbersArray[Numberindex] = NewNumbers;
                  NumbersArray[Numberindex]->count = 1;
              }
            else
              {
                  NewNumbers = NumbersArray[Numberindex];
                
                while(NewNumbers!= NULL)
                    NewNumbers = NewNumbers->Next;
            
                    Numbers *NextNumbers = new Numbers;
                    NextNumbers->Number = Number;
                    NextNumbers->link = Nameindex;
                    NextNumbers->Namescount = NamesArray[Nameindex]->count;
                    NextNumbers->Next = NULL;
                    NewNumbers = NextNumbers;
                    NumbersArray[Numberindex]->count +=1;
                    
             }     
             
            if(NamesArray[Nameindex]->Next == NULL)
            {
                NamesArray[Nameindex]->link = Numberindex;
                NamesArray[Nameindex]->Numbercount = NumbersArray[Numberindex]->count;
            }
            
            else
            {
                Names *temp = new Names;
                temp = NamesArray[Nameindex];
                for(int i=0;i<NewNumbers->Namescount;++i)
                temp = temp->Next;
                
                temp->link = Numberindex;
                temp->Numbercount = NumbersArray[Numberindex]->count;
           }
           
    }
        int method;
        cout<<"Enter by which method you want to search the number:"
            <<"\n1 : By Name "
            <<"\n2 : By Number "<<endl;
        cin>>method;
        string testname;
          //Search by name
          if(method ==1){
            cout<<"Enter the Name "<<endl;
            cin>>Name;
            pointer = Name;
            
            testname = (string)Name;
            for(int i=0;i<sizeof(Name);++i)
            {
                if(*pointer>'a' && *pointer<'z')
                  *pointer = *pointer - 32;
          
                ++pointer;  
            }
        
            pointer1 = Name;
        
            if(*pointer1>='A' && *pointer1 <= 'Z')
                Nameindex = int(*pointer1)-65;
       
                Numbers *Numberspointer = new Numbers;
                Numberspointer = NumbersArray[NamesArray[Nameindex]->link];
                
                for(int i=1;i<=NamesArray[Nameindex]->Numbercount;++i)
                  Numberspointer = Numberspointer->Next;
                  
                cout<<"The number of "<<testname<<" is: "<</*Numberspointer->Number;//*/NumbersArray[NamesArray[Nameindex]->link]->Number;
          }
           else if(method == 2 )
           {     //search by number
                 cout<<"Enter the number:"<<endl;
                 cin>>Number;
            int position4th , position2nd ,Numberindex;
                position4th = Number%10000;
                position2nd = Number%100;
                position4th = position4th/100;
                Numberindex = (position4th + position2nd)%100;
            
                cout<<"Name is:"<<NamesArray[NumbersArray[Numberindex]->link]->Name;
           }
}