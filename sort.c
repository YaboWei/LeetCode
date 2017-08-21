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
    if (start == end) {
        return;
    }

    int base = nums[start];

}

void quickeSort(int* nums, int numSize)
{
    int* sortAry = (int*)malloc(numSize*sizeof(int));
    memcpy(sortAry, nums, numSize*sizeof(int));

    qSort(nums, 0, numSize-1);
}

int main()
{
    int arr[] = {49, 38, -65, 97, 76, -13, 27, 49, -58, 7};

    insertSort(arr, sizeof(arr)/sizeof(int));
    selectSort(arr, sizeof(arr)/sizeof(int));
    bubbleSort(arr, sizeof(arr)/sizeof(int));
    quickeSort(arr, sizeof(arr)/sizeof(int));
}
