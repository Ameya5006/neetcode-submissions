class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int winsum =0;
        int n= nums.size();
        int count = 0;
        freq[0] = 1;
        for(int i = 0 ; i < n ;i++){
            winsum += nums[i];
            if(freq.find(winsum -k ) != freq.end()) {
                count += freq[winsum - k];
            }
            freq[winsum]++;
        }
        return count;
    }
};