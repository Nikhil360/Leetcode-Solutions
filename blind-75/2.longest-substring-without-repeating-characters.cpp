class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart = 0, maxLength = 0;
        if(s.size() == 1){
            return 1;
        }
        unordered_map<char, int> charMap;
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++){
            char presentChar = s[windowEnd];
            if(charMap.find(presentChar) != charMap.end()){
                windowStart = max(windowStart, charMap[presentChar] + 1);
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
            charMap[presentChar] = windowEnd;
        }
        return maxLength;
    }
};