int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize -1;

    int max_area = 0;
    while (left < right) {
        int area = 0;
        if (height[left] < height[right]) {
            area = height[left] * (right - left);
            left++;
        } else {
            area = height[right] * (right - left);
            right--;
        }

        if (max_area < area) {
            max_area = area;
        }
    }

    return max_area;
}

int main()
{
    int heights[] = {1,4,9,4};
    printf("maxArea: %d\n", maxArea(heights, sizeof(heights)/sizeof(int)));
}
