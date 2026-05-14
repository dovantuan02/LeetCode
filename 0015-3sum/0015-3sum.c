/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void sort_array(int arr[], int size) {
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
int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    sort_array(nums, numsSize);

    int capacity = 128;
    int** result = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int total3Num = nums[i] + nums[j] + nums[k];

            if (total3Num < 0) {
                j++;
            } else if (total3Num > 0) {
                k--;
            } else {
                // assign array
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = realloc(result, sizeof(int*) * capacity);
                    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * capacity);
                }
                result[*returnSize] = malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }

                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }
    }
    return result;
}