#include <stdio.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int *, int, int);

int main()
{
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d", containsNearbyDuplicate(nums, numsSize, 3));
    return 0;
}
bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j <= i + k && j < numsSize; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}