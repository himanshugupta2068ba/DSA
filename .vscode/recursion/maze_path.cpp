//move to start to end point in 2-d matrix only by moving right-down and down-right(rightand down)
#include<iostream>
using namespace std;
int maze(int str_r,int str_c,int end_r,int end_c){
    if(str_r>end_r || str_c>end_c) return 0;
    if(str_r==end_r && str_c==end_c) return 1;
    int rightways=maze(str_r,str_c+1,end_r,end_c);
    int downways=maze(str_r+1,str_c,end_r,end_c);
    int totalways=rightways+downways;
    return  totalways;
}
int maze2(int row,int col){
    if(row<1 || col<1) return 0;
    if(row==1 && col==1) return 1;
    int rightways=maze2(row,col-1);
    int downways=maze2(row-1,col);
    int totalways =rightways+downways;
    return totalways;
}
void printpath(int sr,int sc,int er,int ec,string s){
   if(sr>er || sc>ec) return;
   if(sr==er && sc==ec) {
    cout<<s<<endl;
   }
   printpath(sr,sc+1,er,ec,s+'r');
   printpath(sr+1,sc,er,ec,s+'d');
}
int main(){
    cout<<maze(0,0,2,2)<<endl;
    printpath(0,0,2,2,"");
}
