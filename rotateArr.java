class Solution {
    public void rotate(int[][] matrix) {
        //Transpose
        for(int j = 0;j<matrix.length;j++)
        {
            for(int i=j;i<matrix[0].length;i++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        int first, last;
        for(int arr[] : matrix)
        { first = 0;last = arr.length - 1;
            while(first <= last)
            {
                int temp = arr[first];
                arr[first] = arr[last];
                arr[last] = temp;
                first++;last--;
            }
        }
    }
}
    // }
    // public void swap(int[][] matrix, int a1, int a2, int b1, int b2)
    // {
    //     int temp = matrix[a1][a2];
    //     matrix[a1][a2] = matrix[b1][b2];
    //     matrix[b1][b2] = temp;
    // }