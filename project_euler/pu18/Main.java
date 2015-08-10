import java.util.*;
import java.io.*;

public class Main {
    public static void main(String... args) throws Exception {
        BufferedReader br = new BufferedReader(
                                new InputStreamReader(
                                System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] input = new int[n][n];
        for (int i = 0; i < n; ++i) {
            int col = 0;
            for (String num : br.readLine().split(" "))
                input[i][col++] = Integer.parseInt(num);
        }
        int[][] maxDP = maxPathDP(input);
        display(maxDP);
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < maxDP[n-1].length; ++i)
            if(max < maxDP[n-1][i])
                max = maxDP[n-1][i];
        System.out.println(max);
    }

    private static int[][] maxPathDP(int[][] arr) {
        int[][] dped = Arrays.copyOf(arr, arr.length);
        for (int i = 1; i < dped.length; ++i) {
            for (int j = 0; j <= i; ++j) {
                dped[i][j] += Math.max(j == 0 ? 0 : dped[i-1][j-1], dped[i-1][j]);
            }
        }
        return dped;
    }

    private static void display(int[][] arr) {
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.printf("%-7d", arr[i][j]);
            }
            System.out.println();
        }
    }
}
