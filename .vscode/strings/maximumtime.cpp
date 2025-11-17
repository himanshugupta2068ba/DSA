#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    // string s="himanshu is the king";
    // int max=0;
    // for(int i=0;i<s.length();i++){
    //     int count=0;
    //     for(int j=i+1;j<s.length();j++){
    //         if(s[j]==s[i]) count++;
    //     }
    //     if(count>max) max=count;
    // }

    //   for(int i=0;i<s.length();i++){
    //     int count=0;
    //     for(int j=i+1;j<s.length();j++){
    //         if(s[j]==s[i]) count++;
    //     }
    //     if(count==max) {
    //         cout<<s[i]<<" "<<max<<endl;
    //     }
    // }
//optimize way
vector<int> arr(26,0);
string s="himanshu";
for(int i=0;i<s.length();i++){
    char ch=s[i];
    int ascii=(int)ch;
    arr[ascii-97]++;
}
int max=0;
for(int i=0;i<26;i++){
    if(arr[i]>max) max=arr[i];
}
for(int i=0;i<26;i++){
    if(arr[i]==max){
        int ascii=i+97;
        char ch=(char)ascii;
        cout<<ch<<" "<<max<<endl;
    }
}
}
        