int singleNumber(int* nums, int numsSize)
{
    if (nums == NULL)
        return 0;
    int once = nums[0];
    for (int i = 1; i < numsSize; i++) {
        once ^= nums[i];
    }
    return once;
}
