class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length == 1) return 0;
        Arrays.sort(intervals,(a,b)->(a[1] - b[1]));
        int result = 0;
        int prevFirstIdx, firstIdx, secondIdx;
        prevFirstIdx = firstIdx = 0;
        secondIdx = 1;
        while(secondIdx < intervals.length)
        {
            if(intervals[firstIdx][1] > intervals[secondIdx][0])
            {
                result++;
                secondIdx++;
            }else{
                firstIdx = secondIdx;
                secondIdx++;
            }
        }
        return result;
    }
}
