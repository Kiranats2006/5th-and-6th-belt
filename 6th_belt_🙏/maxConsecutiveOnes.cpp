#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int findmax(vector<int>& nums, int k){
    int left=0;
    int maxLength=0;
    int zeroCount=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==0){
            zeroCount++;
        }
        while(zeroCount>k){
            if(nums[left]==0){
                zeroCount--;
            }
            left++;
        }
        maxLength=max(maxLength, i-left+1);
    }
    return maxLength;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<findmax(nums, k);
}