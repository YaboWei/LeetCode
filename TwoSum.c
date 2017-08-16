/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* res = (int*)malloc(2*sizeof(int));
    res[0] = 1;
    res[1] = 2;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > target) {
            continue;
        }
        
        for (int j = i+1; j <numsSize; j++) {
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
