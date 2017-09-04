int removeDuplicates(int* nums, int numsSize) {
    int i, sole_index = 0;
    for (i = 1; i < numsSize;) {
        if (nums[i] == nums[sole_index]) {
            i++;
            continue;
        }

        sole_index += 1;
        nums[sole_index] = nums[i];
        i++;
    }

    return sole_index + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 6, 6, 7, 8, 8, 8, 9};
    int len = removeDuplicates(arr, sizeof(arr)/sizeof(int));
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
