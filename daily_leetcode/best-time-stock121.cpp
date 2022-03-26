#include<iostream>
#include<vector>
#include<algorithm>

//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
//动态规划：采用递归的思想，每次考虑前i天买股票能取得的最大收益
//记录前i天股票最低价格，如果第i天的股票价格小于当前最低价格，更新最低价格
//如果第i天的价格减去最低价格>前i-1天的最大收益，更新最大收益

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int gain=0;
        int min=0;
        //init
        if(prices.size()==0) {
            return 0;
        }
        if(prices[0]<prices[1]) {
            gain=prices[1]-prices[0];
            min=prices[0];
        } else {
            min=prices[1];
        }
        for(int i=2;i<prices.size();i++) {
            if(prices[i]<min) {
                min=prices[i];
            } else if(prices[i]-min>gain) {
                gain=prices[i]-min;
            }
            // cout<<"gain: "<<gain<<" min:"<<min<<endl;
        }
        return gain;
    }
};

int main() {
    vector<int> prices={7,1,5,3,6,4};
    Solution sl;
    cout<<sl.maxProfit(prices)<<endl;
    return 0;
}