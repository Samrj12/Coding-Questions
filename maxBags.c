
/*Time complexity:O(n)
Space complexity:O(1)
Code*/
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks){
    int result = 0;
    for(int i=0;i<capacitySize;i++)
    {
        capacity[i] -= rocks[i];
    }
    qsort(capacity, capacitySize,sizeof(int), cmpfunc);
    int i = 0;
    while(additionalRocks > 0 && i<capacitySize)
    {
        if(capacity[i] <= additionalRocks)
        {
            additionalRocks -= capacity[i];
            result++;
       }else
        break;
        i++;
    }
    return result;
}

