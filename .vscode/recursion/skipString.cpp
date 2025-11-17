#include<iostream>
#include<string>
using namespace  std;
// void skip(string str,string s){
//    if(str.length()==0) {
//     cout<<s;
//     return;
//    }
//    char ch=str[0];
//    if(ch=='a') skip(str.substr(1),s);
//    else skip(str.substr(1),s+ch);
// }
void  skip(string str, string s,int idx){
    if(str.length()==idx){
        cout<<s;
        return;
    }
    char ch=str[idx];
    if(ch=='a') skip(str,s,idx+1);
    else skip(str,s+ch,idx+1);
}
int main(){
    string str="himanshu gupta";
    skip(str,"",0);
}