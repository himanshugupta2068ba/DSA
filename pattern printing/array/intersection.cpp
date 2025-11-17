#include<iostream>
using namespace std;
int main(){
    int a[4]={2,5,7,3};
    int b[5]={2,4,77,22,6};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i]==b[j]){
                cout<<a[i]<<" "<<i,j;
             cout<<endl;
            }
        }
    }
}