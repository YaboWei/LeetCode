#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void sum(int* nums, int start, int end, int target, int** res, int* sumSize)
{
    int l = start, r = end;

    while (l < r) {
        if (nums[l] + nums[r] + target == 0) {
            res[*sumSize] = malloc(3);
            res[*sumSize][0] = target; res[*sumSize][1] = nums[l]; res[*sumSize][2] = nums[r];
            *sumSize += 1;
            while (l < r && nums[l] == nums[l+1]) l++;
            while (l < r && nums[r] == nums[r-1]) r--;
            l++;
            r--;
        } else if (nums[l] + nums[r] + target < 0) {
            l++;
        } else {
            r--;
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }

    int i, j, k;
    int** sumNums = malloc(10*sizeof(int));
    *returnSize = 0;

    for (i = 0; i < numsSize -2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        sum(nums, i+1, numsSize-1, nums[i], sumNums, returnSize);
    }

    return sumNums;
}

int main()
{
    //int nums[] = {-1, 0, 1, 2, -1, -4};
    // sort
    int nums[] = {-4, -1, -1, 0, 1, 2};
    int sumSize = 0;
    int** sums = threeSum(nums, sizeof(nums)/sizeof(int), &sumSize);
    printf("sumSize: %d\n", sumSize);

    int i = 0;
    for (i = 0; i < sumSize; i++) {
        printf("%d, %d, %d\n", sums[i][0], sums[i][1], sums[i][2]);
    }
}
