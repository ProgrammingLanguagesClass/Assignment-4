#include <gtest/gtest.h>

#include "problem-1/main.h"
#include "problem-2/main.h"
#include "problem-3/main.h"
#include "problem-4/main.h"
#include "problem-5/main.h"

const int n = 3;
const int m = 3;
int x[n][m] = {{1, 2, 3},
               {4, 5, 6},
               {7, 8, 9}};
int y[n][m] = {{1, 1, 1},
               {2, 2, 2},
               {3, 3, 3}};
int z[n][m] = {{14, 14, 14},
               {32, 32, 32},
               {50, 50, 50}};


int **memcpy(int y[n][m]) {
    int **t = new int *[n];
    for (int i = 0; i < n; i++) {
        t[i] = new int[m];
        memcpy(t[i], y[i], sizeof(y[i]));
    }
    return t;
}

TEST(Problem_1_Test, Transpose_Test) {
    int **t = memcpy(y);
    int **r = transpose(t, n);
    for(int i = 0; i< n; i++) {
        for(int j = 0; j< n; j++) {
            EXPECT_EQ(r[i][j], t[j][i]);
        }
    }
}
TEST(Problem_2_Test, Multiply_Test) {
    int **t = memcpy(y);
    for (int i = 0; i < n; i++) {
        int *result = multiply(x[i], t, n);
        for (int j = 0; j < m; j++)
            EXPECT_EQ(result[j], z[i][j]);
        delete[] result;
    }
    for (int i = 0; i < n; i++) {
        delete[] t[i];
    }
    delete[] t;
}

TEST(Problem_3_Test, Multiply_Test) {
    int **t1 = memcpy(x);
    int **t2 = memcpy(y);
    int **result = multiply(t1, t2, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) EXPECT_EQ(result[i][j], z[i][j]);
    for (int i = 0; i < n; i++) {
        delete[] result[i];
        delete[] t1[i];
        delete[] t2[i];
    }
    delete[] result;
    delete[] t1;
    delete[] t2;
}

TEST(Problem_4_Test, MultiplyMatrices_Test) {
    int **t1 = memcpy(x);
    int **t2 = memcpy(y);
    int **result = multiplyMatrices(t1, t2, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) EXPECT_EQ(result[i][j], z[i][j]);
    for (int i = 0; i < n; i++) {
        delete[] result[i];
        delete[] t1[i];
        delete[] t2[i];
    }
    delete[] result;
    delete[] t1;
    delete[] t2;
}

TEST(Problem_5_Test, Factorial_Test) {
    EXPECT_EQ(factorial(0), 1);
    for (int i = 1, f = 1; i < 10; i++, f *= i) {
        EXPECT_EQ(factorial(i), f);
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}