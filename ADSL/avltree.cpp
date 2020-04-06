#include <iostream>
using namespace std;

class Heap
{
    int HeapArray[20],CHeapArray[20];
    void MaxHeap();
    void MinHeap();
     public:
           Heap()
             {
                for(int i=0;i<20;++i)
                   CHeapArray[i] = HeapArray[i] = 0;
             }
            
            void insert();
            void Display();
};

void Heap :: insert()
{
    int element,n;
    n = HeapArray[0];
    n = CHeapArray[0];
    
    cout<<"Enter the element: "<<endl;
    cin>>element;
    
    CHeapArray[n+1] = element;
    CHeapArray[0] = n+1;

    HeapArray[n+1] = element;
    HeapArray[0] = n+1;

    MaxHeap();
    MinHeap();
}

void Heap :: MaxHeap()
{
    int i;
    i = HeapArray[0];

    while(i>1 && HeapArray[i] > HeapArray[i/2])
    {
        int temp;
        temp = HeapArray[i];
        HeapArray[i] = HeapArray[i/2];
        HeapArray[i/2] = temp;
        i = i/2;
    }
}

void Heap :: MinHeap()
{
    int i;
    i = CHeapArray[0];

    while(i>1 && CHeapArray[i] < CHeapArray[i/2])
    {
        int temp;
        temp = CHeapArray[i];
        CHeapArray[i] = CHeapArray[i/2];
        CHeapArray[i/2] = temp;
        i = i/2;
    }
}

void Heap :: Display()
{
    cout<<"Maximum and Minimum Marks obtained in the subject is:  "<<endl;
     cout<<"Maximum: "<<HeapArray[1]<<"\tMinumum: "<<CHeapArray[1]<<endl; 
}

int main()
{
    int n,choise;
    Heap heap;

    do
    {
       cout<<"Enter your choise "
           <<"\n1 : insert marks "
           <<"\n2 : Display Maximum and Minimum marks "
           <<"\n3 : Exit "<<endl;
            
       cin>>choise;

        switch(choise)
        {
            case 1: 
                    cout<<"Enter how many students present in exam: "<<endl;
                    cin>>n;
                    cout<<"Enter students Marks: "<<endl;
                
                    for(int i=0;i<n;++i)
                      heap.insert();  
            
            break;
        
            case 2:
                    heap.Display();
        
            break;
    
            default:
                    heap.Display();
                    cout<<"Thank You "<<endl;
    }
  }while(choise!=3);
  
}