#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height){
    int left=0, right=height.size()-1;
    int maxWater=0;
    while(left<right){
        int width=right-left;
        int minHeight=(height[left]<height[right])?height[left]:height[right];
        int area=width*minHeight;
        if(area>maxWater){
            maxWater=area;
        }
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxWater;
}
int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    int result=maxArea(height);
    cout<<result;
}
