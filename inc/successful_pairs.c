#include "main.h"

int* successful_pairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i, j;
    for (i = 0; i < spellsSize; i++) {
        for (j = 0; j < potionsSize; j++) {
            if (spells[i] + potions[j] == success) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}


