// kadane's algo
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int maxSubarray(vector<int>& nums){
    int currSum=nums[0];
    int maxSum=nums[0];
    for(int i=1; i<nums.size(); i++){
        currSum=(currSum+nums[i]>nums[i]?currSum+nums[i]: nums[i]);
        maxSum=(currSum>maxSum?currSum:maxSum);
    }
    return maxSum;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<maxSubarray(nums);
}