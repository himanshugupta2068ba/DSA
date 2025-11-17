#include<iostream>
using namespace std;
int main(){
    int a[7]={1,2,3,7,4,1,3};
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(a[i]==a[j]){
                cout<<a[i]<<" ";
            }
        }
    }
}