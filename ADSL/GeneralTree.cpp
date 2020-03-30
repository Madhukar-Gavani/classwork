// Example program
#include <iostream>
#include <string>
using namespace std;

struct GeneralTree{
    string name;
    GeneralTree *FirstChild;
    GeneralTree *RightSibling;
};

int main()
{
   struct GeneralTree *Root , *Chapter,*Section,*SubSection;
   struct GeneralTree *preChapter,*preSection,*preSubSection;
   string name;
   int chapter,section,subsection;
   bool flag = 1;
   
   cout<<"Enter Book Name: "<<endl;
   cin>>name;
   Root = new GeneralTree;
   Root->name = name;
   Root->FirstChild = NULL;
   Root->RightSibling = NULL;
   
   cout<<"Enter how many chapters in the Book: "<<endl;
   cin>>chapter;
    
    for(int i=0;i<chapter;++i)
    {
         cout<<"Enter Chpater name: "<<endl;
         cin>>name;
         
         if(flag)
         {
            Chapter = new GeneralTree;
            Chapter->name = name;
            Chapter->FirstChild = NULL;
            Chapter->RightSibling = NULL;
            Root->FirstChild = Chapter;
            preChapter = Chapter;
         }
         else
         {
             Chapter = new GeneralTree;
            Chapter->name = name;
            Chapter->FirstChild = NULL;
            Chapter->RightSibling = NULL;
            preChapter->RightSibling = Chapter;
            preChapter = Chapter;
         }
         flag = 0;
   
         cout<<"Enter how many numbers of section are in chapter: "<<endl;
         cin>>section;
        
          bool flag = 1; 
          for(int i=0;i<section;++i)
          {
                
                cout<<"Enter Section name: "<<endl;
                cin>>name;
         
                if(flag)
                {
                    Section = new GeneralTree;
                    Section->name = name;
                    Section->FirstChild = NULL;
                    Section->RightSibling = NULL;
                    Chapter->FirstChild = Section;
                    preSection = Section;
                }
                 else
                 {
                    Section = new GeneralTree;
                    Section->name = name;
                    Section->FirstChild = NULL;
                    Section->RightSibling = NULL;
                    preSection->RightSibling = Section;
                    preSection = Section;
                 }   
                 flag = 0;
                 
                 cout<<"Enter how many numbers of sub-section are in chapter: "<<endl;
                  cin>>subsection;
        
                 bool flag = 1; 
                   for(int i=0;i<subsection;++i)
                    {
                
                         cout<<"Enter Sub-Section name: "<<endl;
                        cin>>name;
         
                        if(flag)
                        {
                            SubSection = new GeneralTree;
                            SubSection->name = name;
                            SubSection->FirstChild = NULL;
                            SubSection->RightSibling = NULL;
                            Section->FirstChild = SubSection;
                            preSubSection = SubSection;
                        }
                         else
                         {
                            SubSection = new GeneralTree;
                            SubSection->name = name;
                            SubSection->FirstChild = NULL;
                            SubSection->RightSibling = NULL;
                            preSubSection->RightSibling = SubSection;
                            preSubSection = SubSection;
                         }   
                         flag = 0;
                    }
          }
    }       
    cout<<"Name of sub section is: "<<endl;
    /*while(Root!=NULL){
        Root = Root->FirstChild;
        cout<<Root->name<<endl;
    }*/
    cout<<"Example: "<<Root->FirstChild->RightSibling->FirstChild->name<<endl;
}

