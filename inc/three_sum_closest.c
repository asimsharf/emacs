#include "main.h"

int three_sum_closest(int* nums, int numsSize, int target){

    int i, j, k;
    int min = 100000;
    int result = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            for (k = j + 1; k < numsSize; k++) {
                if (abs(nums[i] + nums[j] + nums[k] - target) < min) {
                    min = abs(nums[i] + nums[j] + nums[k] - target);
                    result = nums[i] + nums[j] + nums[k];
                }
            }
        }
    }
    return result;
}
