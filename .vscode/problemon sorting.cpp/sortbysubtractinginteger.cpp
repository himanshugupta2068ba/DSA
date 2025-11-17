// find a number k that make a array sorted if |ai-k|.
#include <algorithm>  
#include <iostream>
#include<climits>
#include<cmath>
using namespace std;
int main(){
    int a[]={5,3,10};
    int n=3;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    float kmin=(float)(INT_MIN);
    float kmax=(float)(INT_MAX);
    bool flag =true;
    for(int i=0;i<n-1;i++){
        if(a[i]>=a[i+1]){
            kmin = fmax(kmin,(a[i]+a[i+1])/2.0);
        }
        else{
            kmax=fmin(kmax,(a[i]+a[i+1])/2.0);
        }
        if(kmin>kmax){
            flag=false;
            break;
        }
    }
    if(kmin-(int)kmin>0){
        kmin=(int)kmin+1;
    }
    if(flag==true){
        cout<<"range is  "<<kmin<<" "<<int(kmax);
    }
    
}