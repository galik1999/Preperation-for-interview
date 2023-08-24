#include <vector>
using namespace std;
#include <iostream>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0 && n <= 1 || n == 0) {
                return true;
            }
            else return false;
        }
        for (int i = 0; i < flowerbed.size(); i++) {
            checkAndPlot(flowerbed, i, n);
        }
        return n <= 0;
    }
private:
    void checkAndPlot(vector<int>& flowerbed, int index, int& n) {
        if (index == 0) {
            if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                flowerbed[0] = 1;
                n--;
            }
            else return;
        }
        if (index == flowerbed.size() - 1) {
            if (flowerbed[index] == 0 && flowerbed[index - 1] == 0) {
                flowerbed[index] = 1;
                n--;
            }
            else return;
        }
        else {
            if (flowerbed[index] == 0 && flowerbed[index - 1] == 0 && flowerbed[index + 1] == 0) {
                flowerbed[index] = 1;
                n--;
            }
            else return;
        }
    }
};


int main() {
    Solution s;
    vector<int> vec{1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(vec,2);
    return 0;
}