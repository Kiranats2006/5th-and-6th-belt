#include <iostream>
#include <vector>
using namespace std;

// Custom Deque structure
struct Deque {
    int arr[10000]; // Store indices of elements
    int front, rear;

    Deque() {
        front = 0;
        rear = 0;
    }

    bool empty() {
        return front == rear;
    }

    void push_back(int x) {
        arr[rear] = x;
        rear++;
    }

    void pop_back() {
        if (!empty()) {
            rear--;
        }
    }

    void push_front(int x) {
        front--;
        arr[front] = x;
    }

    void pop_front() {
        if (!empty()) {
            front++;
        }
    }

    int get_front() {
        return arr[front];
    }

    int get_back() {
        return arr[rear - 1];
    }
};

// Sliding Window Maximum using Custom Deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    Deque dq;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements that are out of the current window
        if (!dq.empty() && dq.get_front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && nums[dq.get_back()] < nums[i]) {
            dq.pop_back();
        }

        // Add current element's index
        dq.push_back(i);

        // Add the maximum for the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.get_front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
