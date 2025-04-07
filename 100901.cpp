#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>>ans(2,vector<int>(prices.size(),0));
    ans[0][0]=-prices[0];ans[1][0]=0;
    for(int i=1;i<prices.size();i++){
        ans[0][i]=max(ans[0][i-1],ans[1][i-1]-prices[i]);//持有股票的最大剩余金额
        ans[1][i]=max(ans[1][i-1],ans[0][i-1]-fee);//不持有股票的最大剩余金额
    }
    return ans[1][prices.size()-1];
}
int main(){
	vector<int>prices={1, 3, 2, 8, 4, 9};
	int fee=2;
	int ans=maxProfit(prices,fee);
	cout<<ans<<endl;
	return 0;
}
