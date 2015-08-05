/**
*   Implementation of Matrix ops
*   
*       1.  Multiplication  O(m^3); if m = n
*       2.  Exponentiation  O(log p)
*
*   Used those ops to calculate Nth Fibonacci number
*
*   Where M =   1   1
*               1   0
*
*/

public class MatExp {
    public static void main(String... args) {
        int n = 2;
        if (args.length > 0)
            n = Integer.parseInt(args[0]);

        Matrix a = new Matrix(new int[][]{{1, 1}, {1, 0}});
        Matrix base = new Matrix(new int[][]{{1}, {0}});
        System.out.println(a.exp(n).mul(base));
    }
}

class Matrix {
    int m;
    int n;
    int[][] mat;

    public Matrix(int m, int n) {
        this.m = m;
        this.n = n;
        mat = new int[m][n];
    }

    public Matrix(int[][] arr) {
        this.m = arr.length;
        if (this.m < 1)
            throw new IllegalArgumentException();
        this.n = arr[0].length;
        
        this.mat = new int[m][n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                this.mat[i][j] = arr[i][j];
            }
        }        
    }

    public Matrix mul(Matrix other) {
        if (n != other.m)
            throw new IllegalArgumentException();

        Matrix res = new Matrix(other.m, other.n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < other.n; ++j) {
                int sum = 0;
                for (int k = 0; k < n; ++k) {
                    sum += mat[i][k] * other.mat[k][j];
                }
                res.mat[i][j] = sum;
            }
        }

        return res;
    }

    public Matrix exp(int p) {
        return exp(this, p);
    }

    private Matrix exp(Matrix curr, int p) {
        if (p == 1)
            return curr;
        
        Matrix prod = exp(curr, p/2);
        prod = prod.mul(prod);

        return (p % 2 == 0) ? prod : prod.mul(curr);
    }

    public String toString() {
        StringBuilder buff = new StringBuilder();
        buff.append("\n");

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                buff.append(String.format("%-12d", mat[i][j]));
            }
            buff.append("\n");
        }

        return buff.toString();
    }
}

