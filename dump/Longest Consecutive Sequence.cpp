using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
    // Solution Time Complexity O(nlong(n)).
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        sort(nums.begin(), nums.end());
        for (auto iter = next(nums.begin()); iter != nums.end(); iter = next(iter, 1)) {
            if (*iter == *prev(iter, 1)) {
                nums.erase(iter);
                iter = prev(iter, 1);
            }
        }
        int counter = 1;
        int maxSeq = 1;
        int i = 1;
        while (i < nums.size()) {
            if (abs(nums[i] - nums[i - 1]) == 1) {
                counter++;
                maxSeq = counter > maxSeq ? counter : maxSeq;
            }
            else {
                counter = 1;
            }
            i++;
        }
        return maxSeq;
    }
};

int main() {
    Solution s;
    vector<int> nums{100,4,200,1,3,2};
    cout << s.longestConsecutive(nums);
    return 0;
}