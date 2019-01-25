#include<bits/stdc++.h>

using namespace std;
long long knapSack(long long W, long long wt[], long long val[], int n)
{
   long long i, w;
   long long K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long w;
    cin>>w;
    long long wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<knapSack(w,wt,val,n);
}
