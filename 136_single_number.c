int singleNumber(int* nums, int numsSize)
{
    int res = nums[0]; // note numsSize >= 1
    for (int i = 1; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}
