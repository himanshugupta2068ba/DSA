#include<iostream>
#include<string>
using namespace std;
int string_exist_at(string s,string a){
    int an=a.length();
    int sn=s.length();
    if(an>sn) return -1;
    int i=0;
    while(i<(sn-an+1)){
        int j=i;
        int n=i+an;
        int k=0;
       while(j<n){
        if(s[j]!=a[k]) {
            break;
        } 
        k++;
        j++;
       }
       if(j==n) return i;
       i++;
    }
    return -1;
}
int main(){
    string s="aabafsgsababab";
    string a="afsg";
    cout<<string_exist_at(s,a);
}