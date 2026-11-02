class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int minl = n+1;
        int left = 0;
        int winsum = 0;
        for(int i = 0 ; i < n ; i++){
            winsum += nums[i];
            while(winsum >= target){
                minl = min(minl , i - left + 1);
                winsum -= nums[left];
                left++;
            }
        }
        if(minl == n+1) return 0;
        else return minl;
    }
};