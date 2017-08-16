#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* res = (int*)malloc(2*sizeof(int));
    res[0] = 1;
    res[1] = 2;
    int i, j;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > target) {
            continue;
        }
        
        for (j = i+1; j <numsSize; j++) {
            if (nums[j] > target) {
                continue;
            }
            
            if (nums[i]  + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    
    return res;
    
}

int main()
{
    int array[] = {7, 2, 4, 8, 14};
    int target = 12;

    int* res = twoSum(array, sizeof(array), target);
    printf("[%d, %d]\n", res[0], res[1]);

    return 0;
}
