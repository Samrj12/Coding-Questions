bool canJump(int* nums, int numsSize){
    if(numsSize == 1)return true;
    if(nums[0] == 0)return false;
    numsSize--;
    bool flag;
    while(numsSize>0)
    {
        flag = false;
        int i=numsSize - 1;
        for(;i>= 0; i--)
        {
            if(nums[i] >= (numsSize - i))
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            numsSize = i;
            continue;
        }
        return false;
    }
    return true;
}
