#include<iostream>
#include<vector>
#include<algorithm>

//https://leetcode-cn.com/problems/contains-duplicate/
// containsDuplicate1暴力求解，遍历数组的一半元素，最终超出时间限制
// containsDuplicate先将数组排序，如果数组中有相邻的元素，一定会相互靠近，所以只要遍历数组，看是否存在相邻元素相等的情况。

using namespace std;

class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false;
    }
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()-1) {
            if(nums[i]==nums[i+1])
                return true;
            i++;
        }
        return false;
    }
};

int main() {
    vector<int> nums={1,2,3,4};
    Solution sl;
    cout<<sl.containsDuplicate(nums)<<endl;
    return 0;
}