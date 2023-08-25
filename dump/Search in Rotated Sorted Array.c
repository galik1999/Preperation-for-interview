#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    if (numsSize == 1) {
        return target == nums[0] ? 0 : -1;
    }
    int right = numsSize - 1;
    int left = 0;
    //first we should find out in which side of the pivot index we should search for the target.
    while (left <= right && nums[right] < nums[left]) {
        int mid = (left + right) / 2;
        int bounds[3] = { left,mid,right };
        for (int i = 0; i < 3; i++) {
            if (nums[bounds[i]] == target) return bounds[i];
        }
        if (nums[mid] > nums[left]) {
            // left -> mid is sorted in ascending order.
            if (target >= nums[left] && target <= nums[mid]) {
                right = mid;
            }
            else left = mid;
        }
        else {
            // mid -> right is sorted in ascending order.
            if (target > nums[mid] && target < nums[right]) {
                left = mid;
            }
            else right = mid;
        }
    }
    if (left >= right) return -1;
    //secondly apply binary search on the sorted side.
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        if (target > nums[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    int nums[] = { 4,5,6,7,0,1,2};
    int target = 0;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("sizeof(nums)=%d\n",sizeof(nums));
    printf("%d\n", search(nums,numsSize,target));
    return 0;
}