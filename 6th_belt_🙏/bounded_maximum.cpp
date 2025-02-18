#include<iostream>
#include<vector>
using namespace std;

int boundedMax(vector<int>& A, int L, int R) {
    int result = 0, left = -1, right = -1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > R) {
            left = i;
        }
        
        if (A[i] >= L) {
            right = i;
        }

        result += right - left;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int L, R;
    cin >> L >> R;
    cout << boundedMax(A, L, R) << endl;

    return 0;
}
