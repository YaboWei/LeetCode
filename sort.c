#include <stdio.h>
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

int main()
{
    int arr[] = {49, 38, -65, 97, 76, -13, 27, 49, -58, 7};

    insertSort(arr, sizeof(arr)/sizeof(int));
}
