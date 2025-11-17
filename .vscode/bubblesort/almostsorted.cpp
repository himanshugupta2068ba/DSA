#include <iostream>
using namespace std;
int main(){
 int v[]={23,4,35,42,323} ;
   
   int count=0;
    for(int i=0;i<4;i++){
        if(v[i]>v[i+1]){
            count++;
        }
      
    }
     if(count==1) cout<<"almost sorted";
     else if(count==0) cout<<"already sorted";
     else cout<<"not sorted";
} 