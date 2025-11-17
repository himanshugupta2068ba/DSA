#include<iostream>
using namespace std;
int main(){
    int a[4][4]={{0,0,1,1},{0,1,1,1},{0,0,0,1},{0,0,1,1}};
    int n=4;
    int m=4;
    int row=-1;
    int max=-1;
    for(int i=0;i<n;i++){
        int low=0;
        int high=m-1;
        int firstindex=-1;
        int count=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[i][mid]==1){
                high=mid-1;
                firstindex=mid;
                if(mid==0){
                    break;
                }
            }
            else{
                low=mid+1; 
            }
           
        }
         if(firstindex==-1){
                count=0;
            }
            else
           count=m-firstindex;
        if(count>max){
            max=count;
            row=i;
        }
    }
    cout<<"row with max 1 is "<<row;
}