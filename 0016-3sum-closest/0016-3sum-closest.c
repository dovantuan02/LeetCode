void sortarray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int threeSumClosest(int* nums, int numsSize, int target) {
    sortarray(nums, numsSize);
    int numCloset = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(numCloset - target) ) {
                numCloset = sum;
            }

            if (sum < target) {
                left++;
            }
            else if (sum > target){
                right--;
            }
            else {
                return numCloset;
            }
        }
    }
    return numCloset;
}