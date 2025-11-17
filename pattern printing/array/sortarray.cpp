//three pointer algorith
//DUTCH FLAG ALGO
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
   int low=0, mid=0, high=vec.size()-1;
   while(mid<=high){
    if(vec[mid]==2){
        swap(vec[high],vec[mid]);
        high--;
    }
    else if(vec[mid]==0){
        swap(vec[low],vec[mid]);
        low++;
        mid++;
    }
    else{
        mid++;
    }
   }
   for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<endl;
   }
    
}