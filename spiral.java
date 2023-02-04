class Solution {
    public int[][] generateMatrix(int n) {
        int[][] arr = new int[n][n];
        int count=1, sq = n*n;
        int[][] op = {{0,1},{1,0},{0,-1}, {-1,0}};int d = 0;
        int row=0;int col = 0;
        while(count <= sq)
        {
            arr[row][col] = count++;
            int x = Math.floorMod(row + op[d][0], n);
            int y = Math.floorMod(col + op[d][1], n);
            if(arr[x][y] != 0){d = (d + 1) % 4 ;}
            row += op[d][0];
            col += op[d][1];
        }
        return arr;
    }
}
