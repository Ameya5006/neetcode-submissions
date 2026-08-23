class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }


    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, length);

            ans.push_back(word);

            i = j + 1 + length;
        }

        return ans;
    }
};