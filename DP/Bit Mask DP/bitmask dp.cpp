// Sample problem codeforces contest Hello 2019 problem B 
unordered_map<int,int>dp;
 
void Calc(int mask){
    if(dp.count(mask)!=0)return;
    
    //.. calculate ans here...//
    for(int i=0;i<n;i++){
        //if(mask&(1<<i)) ....;
        //else            ....;
    }
    dp[mask] = ans;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        else            Calc(mask | (1<<i));
    }
}
