#include <stdio.h>
#include <limits.h>
void insertSort(int* nums, int numSize)
{
    int* sortArr = (int*)malloc(numSize*sizeof(int));

    int i = 0, j = 0, p = 0;
    sortArr[i] = nums[i];
    for (i = 1; i < numSize; i++) {
        for (j = 0; j < i; j++) {
            if (nums[i] < sortArr[j]) {
                break;
            }
        }
        int p = j;

        if (j < i) {
            for (j = i-1; j >= p; j--) {
                sortArr[j+1] = sortArr[j];
            }
        }
        sortArr[p] = nums[i];
    }

    for (i = 0; i < numSize; i++) {
        printf("%d ", sortArr[i]);
    }
    printf("\n");
}

void selectSort(int* nums, int numSize)
{
    int i, j;
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));
    for (i = 0; i < numSize; i++) {
        int min = INT_MAX;
        int min_index;
        for (j = i; j < numSize; j++) {
            if (min > sortAry[j]) {
                min = sortAry[j];
                min_index = j;
            }
        }
        if (i != min_index) {
            sortAry[i] = sortAry[min_index] - sortAry[i];
            sortAry[min_index] = sortAry[min_index] - sortAry[i];
            sortAry[i] = sortAry[min_index] + sortAry[i];
        }
    }
    for (j = 0; j < numSize; j++) {
        printf("%d ", sortAry[j]);
    }
    printf("\n");
}

void bubbleSort(int* nums, int numSize)
{
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));
    int i, j, times = 0;
    for (i = 0; i < numSize - 1; i++) {
        int oredered = 0;
        for (j = 0; j < numSize - i - 1; j++) {
            times++;
            if (sortAry[j] > sortAry[j+1]) {
                sortAry[j] = sortAry[j+1] - sortAry[j];
                sortAry[j+1] = sortAry[j+1] - sortAry[j];
                sortAry[j] = sortAry[j+1] + sortAry[j];
                oredered++;
            }
        }
        if (oredered == 0) {
            break;
        }
    }
    printf("times: %d\n", times);
    for (j = 0; j < numSize; j++) {
        printf("%d ", sortAry[j]);
    }
    printf("\n");
}

void qSort(int* nums, int start, int end)
{
    if (start >= end) {
        return;
    }

    int base = nums[start];
    int l = start, r = end;

    while (l < r) {
        while (l < r && nums[r] >= base) r--;
        nums[l] = nums[r];
        while (l < r && nums[l] <= base) l++;
        nums[r] = nums[l];
    }

    nums[l] = base;
    
    qSort(nums, start, l-1);
    qSort(nums, r+1, end);

}

void quickeSort(int* nums, int numSize)
{
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));

    qSort(nums, 0, numSize-1);
    int i;
    for (i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void heaperAdjust(int* nums, int root, int numSize)
{
    int i, r_val;
    r_val = nums[root];
    i = root * 2 + 1;

    while (i < numSize) {
        if (i + 1 < numSize && nums[i] > nums[i+1]) i++;

        if (nums[i] >= r_val) {
            break;
        }

        nums[root] = nums[i];
        root = i;
        i = root * 2 + 1;
    }

    nums[root] = r_val;
}

void heaperSort(int* nums, int numSize)
{
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));

    int last_root = (numSize - 1) / 2;
    int i;
    for (i = last_root; i >= 0; i--) {
        heaperAdjust(nums, i, numSize);
    }

    for (i = numSize-1; i > 0; i--) {
        nums[0] = nums[i] - nums[0];
        nums[i] = nums[i] - nums[0];
        nums[0] = nums[i] + nums[0];

        heaperAdjust(nums, 0, i);
    }

    for (i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void shellInsertSort(int* nums, int step, int numSize)
{
    int s, i, j;
    for (s = 0; s < step; s++) {
        for (i = s+step; i < numSize; i+=step) {
            for (j = i - step; j >= 0; j -= step) {
                if (nums[j] < nums[i]) {
                    break;
                }
            }

            if (j != i - step) {
                int val = nums[i];
                int k;
                for (k = i - step; k > j; k-=step) {
                    nums[k+step] = nums[k];
                }
                nums[j+step] = val;
            }
        }
    }
}

void shelllSort(int* nums, int numSize)
{
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));

    int step = numSize / 2;

    while (step >= 1) {
        shellInsertSort(nums, step, numSize);
        step /= 2;
    }

    int i;
    for (i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {49, 38, -65, 97, 76, -13, 27, 49, -58, 7};
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //insertSort(arr, sizeof(arr)/sizeof(int));
    //selectSort(arr, sizeof(arr)/sizeof(int));
    //bubbleSort(arr, sizeof(arr)/sizeof(int));
    //quickeSort(arr, sizeof(arr)/sizeof(int));
    //heaperSort(arr, sizeof(arr)/sizeof(int));
    shelllSort(arr, sizeof(arr)/sizeof(int));
}
