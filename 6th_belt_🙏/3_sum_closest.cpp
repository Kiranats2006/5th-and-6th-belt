#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int absValue(int x){
    if(x<0) return -x;
    return x;
}
void bubbleSort(vector<int>& nums){
    int n=nums.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}
int threeSumClosest(vector<int>& nums, int target){
    bubbleSort(nums);
    int closestSum=nums[0]+nums[1]+nums[2];
    for(int i=0; i<nums.size()-2; i++){
        int left=i+1;
        int right=nums.size()-1;
        while(left<right){
            int currentSum=nums[i]+nums[left]+nums[right];
            if(absValue(currentSum-target)<absValue(closestSum-target)){
                closestSum=currentSum;
            }
            if(currentSum<target) left++;
            else if(currentSum>target) right--;
            else{
                return currentSum;
            }
        }
    }
    return closestSum;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    cout<<threeSumClosest(nums, target);
}