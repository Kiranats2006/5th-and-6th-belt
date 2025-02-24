#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void nextPermutations(vector<int>& nums){
    int n=nums.size();
    int i=n-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i>=0){
        int j=n-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    int left=i+1, right=n-1;
    while(left<right){
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }
    nextPermutations(nums);
    for (int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}