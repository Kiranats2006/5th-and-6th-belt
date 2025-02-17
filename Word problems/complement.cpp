#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    bool found=false;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]+arr[i]==target){
                cout<<i<<" "<<j;
                return 0;
            }
        }

    }
    cout<<-1;
    return 0;
}