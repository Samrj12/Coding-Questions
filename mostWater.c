/*
* Prompt: Given an integer array nums of length nand an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

int maxArea(int* height, int heightSize){
int maxWater = 0, area = 0;
int i = 0, j = heightSize - 1;
while(i < j)
{
    area = (j - i)*(height[j] > height[i] ? height[i++] : height[j--]);
    if(maxWater < area)
    maxWater = area;
}
return maxWater;
}
