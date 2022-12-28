int searchInsert(int* nums, int numsSize, int target){
    if(nums[0]>=target)return 0;
    int low = 0,high =numsSize;
    int mid = 0;
    while(low < high)
    {
        mid = low + (high - low)/2;
        printf("%d", mid);
        if(nums[mid]>=target)
        {
            high = mid;
        }else{
           low = mid + 1;
        }
    }
    return low;
}
