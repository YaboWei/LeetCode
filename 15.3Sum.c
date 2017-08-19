/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i, j, k;
    int** sumNums = malloc(10*sizeof(int));
    *returnSize = 0;

    for (i = 0; i < numsSize; i++) {
        for (j = i+1; j < numsSize; j++) {
            for (k = j+1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    printf("%d, %d, %d\n", nums[i], nums[j], nums[k]);
                    int* list = malloc(3 * sizeof(int));
                    list[0] = nums[i]; list[1] = nums[j]; list[2] = nums[k];
                    sumNums[*returnSize] = list;
                    *returnSize += 1;
                }
            }
        }
    }

    return sumNums;
}

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int sumSize = 0;
    int** sums = threeSum(nums, sizeof(nums)/sizeof(int), &sumSize);
    printf("sumSize: %d\n", sumSize);

    int i = 0;
    for (i = 0; i < sumSize; i++) {
        printf("%d, %d, %d\n", sums[i][0], sums[i][1], sums[i][2]);
    }
}
