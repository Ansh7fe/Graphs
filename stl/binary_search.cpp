#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int arr[]={20,30,40,40,40,50,60,70,80,90,100};
  int n=sizeof(arr)/sizeof(int);

  int key;
  cin>>key;
// binary_search function returns true or false

  bool present=binary_search(arr,arr+n,key);
  if(present){
    cout<<'Present';
  }
  else{
    cout<<"Not Present";
  }

  // Two more things
  // Get the index of key
  // lower_bound(s,e,key) and upper_bound(s,e,key)

  auto it =lower_bound(arr,arr+n,40);  //first element greater than equal to 40;
  cout<<(it-arr)<endl;

  // upper_bound
  auto upIt=upper_bound(arr,arr+n,40);  //first element that is strictly greater than 40
  cout<<(upIt-arr)<endl;

  cout<<"Frequency of 40"<<(upIt-it);

  return 0;
}