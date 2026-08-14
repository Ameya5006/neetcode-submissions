class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ans;
        int n = nums.size();
        int limit = n/2;
        for(int i = 0; i < n;i++){
            ans[nums[i]]++;
            if (ans[nums[i]] > limit){
                return nums[i];
                }
        }
        return -1;
    } 
};