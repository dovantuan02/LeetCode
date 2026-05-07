void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    int totalSize = nums1Size + nums2Size;

    int totalNum[totalSize];

    memset(totalNum, 0, sizeof(totalNum));

    if (nums1 != NULL) {
        memcpy(totalNum, nums1, nums1Size * sizeof(int));
    }

    if (nums2 != NULL) {
        memcpy(totalNum + nums1Size, nums2, nums2Size * sizeof(int));
    }

    sortArray(totalNum, totalSize);

    for (int i = 0; i < totalSize; i++) {
        printf("num[%d] = %d\n", i, totalNum[i]);
    }

    if (totalSize % 2 == 1) {
        return totalNum[totalSize / 2];
    }

    return (totalNum[totalSize / 2 - 1] + totalNum[totalSize / 2]) / 2.0;
}