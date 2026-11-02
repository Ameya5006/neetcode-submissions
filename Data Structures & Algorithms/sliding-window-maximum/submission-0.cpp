class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        for(int i = 0 ; i < k ;i++){
            while(!q.empty() && q.back() < nums[i] ) q.pop_back();
            q.push_back(nums[i]);    
        }
        vector<int> ans;
        ans.push_back(q.front());
        for(int i = k ;i < n ; i++){
            int ele = nums[i-k];
            while(!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
            if(ele == q.front()) q.pop_front();
            ans.push_back(q.front());
        }
        return ans;
    }
};
