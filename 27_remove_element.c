int removeElement(int* nums, int numsSize, int val) 
{
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] == val) {
            nums[i] = nums[--numsSize];
        }
    }
    return numsSize;
}
