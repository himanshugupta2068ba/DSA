//1234321
#include<iostream>
using namespace std;
void incre_dercre(int n,int i){
    // if(n==0) return;
    if(i>n) return;
    cout<<i;
    incre_dercre(n,i+1);
    if(i>1)
    cout<<i-1; 
   
}
int main(){
    int i=1;
    incre_dercre(4,i);
}
