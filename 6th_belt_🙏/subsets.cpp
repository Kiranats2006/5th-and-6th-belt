#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void backtrack(vector<int>& nums, vector<vector<int>>& result, int index, vector<int>& current){
    result.push_back(current);
    for(int i=index; i<nums.size(); i++){
        current.push_back(nums[i]);
        backtrack(nums, result, i + 1, current);
        current.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> nums){
    vector<vector<int>> results;
    vector<int> current;
    backtrack(nums,results,0,current);
    return results;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<vector<int>> result = subsets(nums);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}