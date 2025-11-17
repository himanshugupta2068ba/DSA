#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count =0;
    int n=s.length();
    if(n==0) return 0;
   else if(s[0]!=s[1]&&s[n]!=s[n-1]) count++;
    for(int i=1;i<n-1;i++){
        if(s[i]!=s[i+1]&&s[i]!=s[i-1]) count++;
    }
    cout<<count;
}
//mistake  