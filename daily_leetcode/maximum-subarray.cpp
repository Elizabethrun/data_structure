#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

//寻找最大连续子数列
//贪心：从头开始找，如果出现累加和小于0的序列就抛弃
//动态规划：寻找前i个元素的数组中的最大子序列。

class Solution {
public:
    //贪心：
    int maxSubArray1(vector<int>& nums) {
        int sum=0;
        int max=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum>max) {
                max=sum;
            }
            if(sum<0) {
                sum=0;
            }
        }
        return max;
    }
    //动态规划
     int maxSubArray(vector<int>& nums) {
        int pre=0;
        int maxAns=nums[0];
        for(int i=0;i<nums.size();i++) {
            pre=max(pre+nums[i],nums[i]); //pre 表示以元素nums[i]结尾的子序列的最大和
            maxAns=max(maxAns,pre);
        }
        return maxAns;
    }
};

int main() {
    Solution sl;
    vector<int> nums={5,4,-1,7,8};
    cout<<sl.maxSubArray(nums)<<endl;
    return 0;
}