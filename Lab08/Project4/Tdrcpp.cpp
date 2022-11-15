#include <iostream>
#define MAX_ROWS 10000
#define MAX_COLS 10000

using namespace std;

int dp[MAX_ROWS][MAX_COLS];

void initDp(int n);
int NumPaths(int row, int col, int n);
int NumPaths_dp(int row, int col, int n);

int main() {
	initDp(10);
	cout << NumPaths(1, 1, 10) << endl;
	cout << NumPaths_dp(1, 1, 10) << endl;
	return 0;
}

void initDp(int n) {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = -1;
}

int NumPaths(int row, int col, int n) {
	if (row == n || col == n)
		return 1;
	return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
}

int NumPaths_dp(int row, int col, int n) {
	if (dp[row][col] != -1)
		return dp[row][col];
	else if (row == n || col == n)
		return dp[row][col] = 1;
	return dp[row][col] = NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
}
