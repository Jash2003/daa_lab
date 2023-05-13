#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int sack[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                sack[i][w] = 0;
            else if (wt[i-1] <= w)
                sack[i][w] = max(val[i-1] + sack[i-1][w-wt[i-1]], sack[i-1][w]);
            else
                sack[i][w] = sack[i-1][w];
        }
    }
    return sack[n][W];
}

int main() {
    int W, n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;
    int wt[n], val[n];
    cout << "Enter the weight and value of each item: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> wt[i] >> val[i];
    }
    int result = knapsack(W, wt, val, n);
    cout << "The maximum value that can be put in the knapsack is: " << result << endl;
    return 0;
}

