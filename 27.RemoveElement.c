int removeElement(int* nums, int numsSize, int val) {
    int i, leaving_index = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[leaving_index++] = nums[i];
        }
    }

    return leaving_index;
}

int main()
{
    int arr[] = {3, 2, 2, 3};
    int len = removeElement(arr, sizeof(arr)/sizeof(int), 3);
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
