#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            l = mid + 1;
        }

        if (nums[mid] > target) {
            r = mid - 1;
        }
    }

    if (nums[r] < target) {
        return r+1;
    }

    if (nums[r] > target) {
        return r;
    }

    return -1;
}

int main()
{
    int array[] = {1, 3, 5, 7, 9, 11};
    int target = 4;
    int pos = searchInsert(array, sizeof(array)/sizeof(int), target);
    printf("%d: pos %d\n", target, pos);
}
