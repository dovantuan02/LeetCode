int maxArea(int* height, int heightSize) {
    int totalWater = 0;
    int i = 0;
    int j = heightSize - 1;
    while (i < j) {
        int minHeight = height[i] < height[j] ? height[i] : height[j];
        int ret = (j - i) * minHeight;
        if (totalWater < ret) {
            totalWater = ret;
        }

        if (height[i] < height[j]) {
            i++;
            continue;
        }
        j--;
    }
    return totalWater;
}