#include <stdio.h>
#include <limits.h>
void insertSort(int* nums, int numSize)
{
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));

    int i = 0, j = 0, p = 0;
    for (i = 1; i < numSize; i++) {
        for (j = i-1; j > 0; j--) {
            if (sortAry[j] < sortAry[i]) {
                break;
            }
        }

        int insertVal = sortAry[i];
        if (j != i-1) {
            int k;
            for (k = i; k > j+1; k--) {
                sortAry[k] = sortAry[k-1];
            }
        }
        sortAry[j+1] = insertVal;
    }

    for (i = 0; i < numSize; i++) {
        printf("%d ", sortAry[i]);
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

    qSort(sortAry, 0, numSize-1);
    int i;
    for (i = 0; i < numSize; i++) {
        printf("%d ", sortAry[i]);
    }
    printf("\n");
}

void heaperAdjust(int* nums, int root, int numSize)
{
    int i, r_val;
    r_val = nums[root];
    i = root * 2 + 1;

    while (i < numSize) {
        if (i + 1 < numSize && nums[i] < nums[i+1]) i++;

        if (nums[i] <= r_val) {
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
        heaperAdjust(sortAry, i, numSize);
    }

    for (i = numSize-1; i > 0; i--) {
        sortAry[0] = sortAry[i] - sortAry[0];
        sortAry[i] = sortAry[i] - sortAry[0];
        sortAry[0] = sortAry[i] + sortAry[0];

        heaperAdjust(sortAry, 0, i);
    }

    for (i = 0; i < numSize; i++) {
        printf("%d ", sortAry[i]);
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
        shellInsertSort(sortAry, step, numSize);
        step /= 2;
    }

    int i;
    for (i = 0; i < numSize; i++) {
        printf("%d ", sortAry[i]);
    }
    printf("\n");
}

void mMerge(int* nums, int start1, int end1, int start2, int end2)
{
    printf("merge %d-%d, %d->%d\n", start1, end1, start2, end2);
    int len = end2-start1+1;
    int* sortBuf = (int*)malloc(sizeof(int)*len);
    int i = 0;
    while (start1 <= end1 && start2 <= end2) {
        if (nums[start1] < nums[start2]) {
            sortBuf[i++] = nums[start1];
            start1++;
        } else {
            sortBuf[i++] = nums[start2];
            start2++;
        }
    }

    while (start1 <= end1) {
        sortBuf[i++] = nums[start1++];
    }

    while (start2 <= end2) {
        sortBuf[i++] = nums[start2++];
    }

    for (i = 0; i < len; i++) {
        nums[end2-i] = sortBuf[len-1-i];
        printf("len: %d %d->%d\n", len, end2-i, nums[end2-i]);
    }
    for (i = 0; i < len; i++) {
        printf("%d ", nums[end2-i-1]);
    }
    printf("\n");
}

void mSort(int* nums, int start, int end)
{
    if (start < end) {
        int mid = (start+end)/2;
        mSort(nums, start, mid);
        mSort(nums, mid+1, end);
        mMerge(nums, start, mid, mid+1, end);
    }
}

void mergerSort(int* nums, int numSize)
{
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));

    mSort(sortAry, 0, numSize-1);
    int i;
    for (i = 0; i < numSize; i++) {
        printf("%d ", sortAry[i]);
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
    //shelllSort(arr, sizeof(arr)/sizeof(int));
    mergerSort(arr, sizeof(arr)/sizeof(int));
}
