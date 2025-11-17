#include<iostream>
using namespace std;
long long power(long long a, long long b){
    if(b==1) return a;
    if(b==0) return 1;
    // return power(a,b/2)*power(a,b/2);
    long long ans=power(a,b/2);
    if(b%2==0){
        // long long ans=power(a,b/2);
        return ans*ans;
    }
    else{
        // long long ans=power(a,b/2);
        return ans*ans*a;
    }

}
int main(){
    cout<<power(10,10);
}
