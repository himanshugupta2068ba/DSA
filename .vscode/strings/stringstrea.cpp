#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main(){
  string str="himanshu is a king";
  stringstream ss(str);
  string temp;

  while(ss>>temp){
    cout<<temp<<endl;
  }
}