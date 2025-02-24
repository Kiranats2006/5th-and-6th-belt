#include<iostream>
#include<iomanip>
#include<algorithm>
# include<vector>
using namespace std;

int trap(vector<int>& height){
    int n=height.size();
    if(n==0) return 0;
    int left=0, right=n-1, leftmax=0, rightMax=0, trapped=0;
    while(left<=right){
        if(height[left]<height[right]){
            if(height[left]>=leftmax){
                leftmax=height[left];
            }
            else{
                trapped+=leftmax-height[left];
            }
            left++;
        }
        else{
            if(height[right]>=rightMax){
                rightMax=height[right];
            }
            else{
                trapped+=rightMax-height[right];
            }
            right--;
        }
    }
    return trapped;
}
int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    cout<<trap(height);
    return 0;
}