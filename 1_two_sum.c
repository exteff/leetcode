#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/* currently uses sorting, complexity O(nlogn)
 * TODO: reimplement using hashmap for O(n) time */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int *arr = malloc(numsSize * sizeof(int));
	if (arr == NULL)
		return NULL;
	memcpy(arr, nums, numsSize * sizeof(arr[0]));
    qsort(arr, numsSize, sizeof(arr[0]), comp_int);

	int num1, num2; // exactly one solution so these will be initialized in loop
    for (int i = 0; i < numsSize; i++) {
		num2 = target - arr[i];
		// subtle note: if target - arr[i] == x/2, then the solution must be
		// num1 = num2 = x/2
		// since we search left to right and there is exactly one solution
		// thus we cannot incorrectly consider the same number twice
		if (bsearch(&num2, arr, numsSize, sizeof(arr[0]), comp_int) != NULL) {
			num1 = arr[i];
			break;
		}
    }
	free(arr);

    *returnSize = 2;
    int *indices = malloc(2 * sizeof(int));
    if (indices == NULL)
        return NULL;
    indices[0] = -1;
    indices[1] = -1;

	for (int k = 0; k < numsSize; k++) {
		if (nums[k] == num1 || nums[k] == num2) {
			if (indices[0] == -1)
				indices[0] = k;
			else {
				indices[1] = k;
				break;
			}
		}
	}

    return indices; // caller calls free
}
