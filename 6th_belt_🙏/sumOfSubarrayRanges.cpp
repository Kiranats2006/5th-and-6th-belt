#include <iostream>
using namespace std;

int sumOfSubarrayRanges(int nums[], int n) {
    long long sum_ranges = 0;

    for (int i = 0; i < n; i++) {
        int min_val = nums[i], max_val = nums[i];
        for (int j = i; j < n; j++) {
            if (nums[j] < min_val) min_val = nums[j];
            if (nums[j] > max_val) max_val = nums[j];

            sum_ranges += (max_val - min_val);
        }
    }
    return sum_ranges;
}

int main() {
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << sumOfSubarrayRanges(nums, n) << endl; // Output: 4
    return 0;
}
