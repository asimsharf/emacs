#include "main.h"

int** three_sum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int **result = (int **)malloc(sizeof(int *) * 1000);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    int i, j, k;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            for (k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    result[*returnSize] = (int *)malloc(sizeof(int) * 3);
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[k];
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                }
            }
        }
    }
    return result;

}
