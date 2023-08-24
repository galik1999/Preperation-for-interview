using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr;
        arr.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            arr.push_back(arr[arr.size() - 1] ^ encoded[i]);
        }
        return arr;
    }
};

int main() {
    Solution s;
    vector<int> encoded = {1,2,3};
    int first = 1;
    vector<int> arr = s.decode(encoded, first);
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        if (next(iter, 1) == arr.end()) {
            cout << *iter;
        }
        else {
            cout << *iter << ",";
        }
    }
    return 0;
}