#include<iostream>
#include<iomanip>
#include<algorithm>
# include<vector>
using namespace std;
int trap(vector<int>& height){
    int n=height.size();
    if(n==0) return 0;
    int left=0, right=n-1, leftMax=0, rightMax=0, trappedWater=0;
    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>=leftMax){
                leftMax=height[left];
            }
            else{
                trappedWater+=leftMax-height[left];
            }
            left++;
        }
        else{
            if(height[right]>=rightMax){
                rightMax=height[right];
            }
            else{
                trappedWater+=rightMax-height[right];
            }
            right--;
        }
    }
    return trappedWater;
}
int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    int result=trap(height);
    cout<<result;
    return 0;
}