#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }
        return q.top();
    }
};

int main() {
    Solution s;
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKthLargest(nums, 4) << endl;


    //implementation of iterators in C++;
    int arr[5] = { 1,2,3,4,5 };
    int* curr = arr;
    int* end = arr + 5;
    for (curr; curr != end; curr++) {
        printf("%d", *curr);
    }
}