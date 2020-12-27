## Dynamic Programming approach to solving the Knapsack Problem ##
## Context: The Knapsack Problem is an NP hard problem that is embedded in many real life phenomenona. One example is the concept of vickrey auctions, where bidders submit there bid values without knowledge of the bids of the other people in the auction, try to find the connection! ##

#include <iostream>
using namespace std;
int max(int x, int y) {
   return (x > y) ? x : y;
}

## As an exercise, try to think about what W, w[], v[] and n should represent ##
int knapSack(int W, int w[], int v[], int n) {
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= W; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   return K[n][W];
}
