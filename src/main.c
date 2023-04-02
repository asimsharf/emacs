#include <stdio.h>
#include "../inc/main.h"



int main(void)
{

    // successful_pairs test
    int spells[] = {1, 2, 3, 4, 5};
    int potions[] = {1, 2, 3, 4, 5};
    int returnSize;
    int *result = successful_pairs(spells, 5, potions, 5, 6, &returnSize);
    printf("[%d, %d]\n", result[0], result[1]);

    // three_sum test
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize2;
    int *returnColumnSizes;
    int **result2 = three_sum(nums, 6, &returnSize2, &returnColumnSizes);
    for (int i = 0; i < returnSize2; i++) {
        printf("[%d, %d, %d]\n", result2[i][0], result2[i][1], result2[i][2]);
    }

    // three_sum_closest test
    int nums2[] = {-1, 2, 1, -4};
    int result3 = three_sum_closest(nums2, 4, 1);
    printf("%d\n", result3);
    
    

    return 0;
}
