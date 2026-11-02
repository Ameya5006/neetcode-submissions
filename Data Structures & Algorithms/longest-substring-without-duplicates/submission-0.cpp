class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        int left = 0;
        int maxl = 0;
        for(int i =0 ;i < n ;i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[left]]--;
                left++;
            }
            maxl = max(maxl , i - left + 1); 
        } 
        return maxl;
    }
};
