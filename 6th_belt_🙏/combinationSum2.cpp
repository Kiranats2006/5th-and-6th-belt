#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int start, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) { 
        result.push_back(current); 
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue; // Skip duplicate elements
        }
        
        if (candidates[i] > target) {
            break; // Stop since further numbers will be larger
        }

        current.push_back(candidates[i]); 
        backtrack(candidates, i + 1, target - candidates[i], current, result);
        current.pop_back(); // Remove last element for backtracking
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end()); // Sorting helps to handle duplicates easily
    backtrack(candidates, 0, target, current, result);
    return result;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> candidates(n);

    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    cin>>target;
    vector<vector<int>> result = combinationSum2(candidates, target);

    for (auto combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
