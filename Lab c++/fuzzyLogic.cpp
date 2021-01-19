#include<iostream>
using namespace std;
struct Input {
    int left,mid,right;
    float value;
};
struct Output {
    int left,mid,right;
    float value;
};
struct FuzzyRules {
    struct Output Kp;
    struct Output Kd;
};
float calMembershipVal(struct Input,float); 
float min(float, float); 
float defuzzyfication(struct Output WA[4]);
float weight(struct Output Value);
int main(){ 
    Output KZO,KPS,KPB;
    Output KdZO,KdPS,KdPB; 
    KZO.left = -10; KZO.mid = 0; KZO.right = 10;
    KPS.left = 0; KPS.mid = 10; KPS.right = 20;
    KPB.left = 10; KPB.mid = 20; KPB.right = 30;

    KdZO.left = -4; KdZO.mid = 0; KdZO.right = 4;
    KdPS.left = 0; KdPS.mid = 4; KdPS.right = 8;
    KdPB.left = 4; KdPB.mid = 8; KdPB.right = 12;

    FuzzyRules Rules[25] = {
       {KPS,KdZO}, {KZO,KdPS}, {KPS,KdPB}, {KPS,KdPS}, {KZO,KdZO},
       {KPB,KdZO}, {KPS,KdPS}, {KPS,KdPB}, {KPB,KdPS}, {KPB,KdZO},
       {KPS,KdPS}, {KPS,KdPB}, {KPB,KdPB}, {KPS,KdPB}, {KZO,KdPS},
       {KPB,KdPS}, {KPB,KdPS}, {KPB,KdZO}, {KPS,KdPS}, {KPB,KdZO},
       {KPS,KdPB}, {KZO,KdPS}, {KZO,KdZO}, {KZO,KdPS}, {KZO,KdZO}
       
    };
     Input NB,NS,ZO,PS,PB;
     Input error[5],derror[5];
     
     NB.left = -12; NB.mid = -8; NB.right = -4;
     NS.left = -8; NS.mid = -4; NS.right = 0;
     ZO.left = -4; ZO.mid = 0; ZO.right = 4;
     PS.left = 0; PS.mid = 4; PS.right = 8;
     PB.left = 4; PB.mid = 8; PB.right = 12;
     
     error[0] = derror[0] = NB;
     error[1] = derror[1] = NS;
     error[2] = derror[2] = ZO;
     error[3] = derror[3] = PS;
     error[4] = derror[4] = PB;
    
     int input = 0,index = 0;
     float ierror,iderror;
     Input errorest;
     Input derrorest; 
     Output kp1, kp[4]; 
     Output kd1, kd[4];
      do{
           cout<<"Enter error and derror: "<<endl;
           cin>>ierror>>iderror; 
           
           //Fuzzyfication
           for(int i=0;i<5;++i){
               if(ierror >= error[i].left && ierror <= error[i].right){
                   for(int j=0;j<5;++j){
                       if(iderror >= derror[j].left && iderror <= derror[j].right){
                           errorest = error[i];
                           errorest.value = calMembershipVal(error[i],ierror);
                           derrorest = derror[j];
                           derrorest.value = calMembershipVal(derror[j],iderror);
                           kp1 = Rules[i*5 + j].Kp; 
                           kd1 = Rules[i*5 + j].Kd; 
                           kp1.value = min(errorest.value, derrorest.value);
                           kd1.value = min(errorest.value, derrorest.value); 
                           kp[index] = kp1; 
                           kd[index++] = kd1;

                        }
                   }
               }
           }
         float resultKp = defuzzyfication(kp);   
         float resultKd = defuzzyfication(kd);
         cout<<"result of kp after defuzzyfication is: "<<resultKp<<endl;
         cout<<"result of kd after defuzzyfication is: "<<resultKd<<endl;
         cout<<"you want to enter once again data if yes press 1 else 0: "<<endl;
         cin>>input;
      }while (input != 0);
      cout<<"Thank you!!! you made it!!!!!!!!!!!! "<<endl; 
     return 0;
} 
float calMembershipVal(struct Input error,float ierror) {
    if(ierror < error.mid){
        return((ierror - error.left)/(error.mid - error.left));
    }else {
        return((error.right - ierror)/(error.right - error.mid));
    }
}
float min(float x, float y){
    return(x<y?x:y);
} 
float defuzzyfication(struct Output WA[4]){
    float sum = 0.0,summem = 0.0;
    for(int i=0;i<4;++i){
        sum += weight(WA[i])*WA[i].value;
        cout<<"Sum is: "<<weight(WA[i])*WA[i].value;
        cout<<"\tMemV values of kp: "<<WA[i].value<<endl;
        summem += WA[i].value; 
     }
    return(sum/summem);  
} 
float weight(Output Value){
    float x,y;
    x = Value.right - Value.value*(Value.right - Value.mid);
    y= Value.left + Value.value*(Value.mid - Value.left); 
    return ((x+y)/2);
}
