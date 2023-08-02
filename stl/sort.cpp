#include<iostream>
#include<algorithm>
using namespace std;

// Define a comparater function
bool compare(int a,int b){
  return a>b;
}

int main(){
  int n,key;
  cin>>n;

  int a[100001];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  sort(a,a+n,compare);
  for(int i=0;i<n;i++){
    cout<<a[i]<<",";
  }

  
  return 0;
}