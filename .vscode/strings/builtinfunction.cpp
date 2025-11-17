#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int  main(){
    string s="himanshu is the king";
//    cout<<s.length()<<" ";
//     s.push_back('a');
//     // s=s+'a';
//     s=s+"king";
//     s="king"+s;
//     cout<<s; 
    reverse(s.begin()+1,s.begin()+5);
    cout<<s<<endl;

 }

