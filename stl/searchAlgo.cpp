#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int arr[]={1,21,44,156,78};
  int n=sizeof(arr)/sizeof(int);

  int key;
  cin>>key;
  auto it=find(arr,arr+n,key);
  int index=it-arr;

  cout<<index<<endl;
  
  return 0;
}