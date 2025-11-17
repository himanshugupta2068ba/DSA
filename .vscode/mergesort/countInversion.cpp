#include<iostream>
#include<vector>
using namespace std;
int count=0;
int inversion(vector<int>&a,vector<int>&b){
    int count=0;
    int i=0;
    int j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count+=(a.size()-i);
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}
void merge(vector<int>&a,vector<int>&b,vector<int>&res){
   int i=0;
   int j=0;
   int k=0;
   while(i<a.size() && j<b.size()){
    if(a[i]<b[j]){
        res[k++]=a[i++];
    }
    else{
        res[k++]=b[j++];
    }
   }
 while (i < a.size()) {
        res[k++] = a[i++];
    }

    while (j < b.size()) {
        res[k++] = b[j++];
    }
}
void mergeSort(vector<int>&v){
   int n=v.size();
   if(n==1) return;
   int n1=n/2;
   int n2=n-n/2;
   vector<int>a(n1),b(n2);
   for(int i=0;i<n1;i++){
    a[i]=v[i];
   }
   for(int i=0;i<n2;i++){
    b[i]=v[i+n1];
   }
   mergeSort(a);
   mergeSort(b);
   //count the inversion
   count+=inversion(a,b);
   merge(a,b,v);
   a.clear();
   b.clear();
}
int main(){
    int arr[]={1,546,7843,351,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v);
    cout<<count;
       
}