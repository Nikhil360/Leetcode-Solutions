class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int length, start;
        for(int i = 0; i < n;i++){
            dp[i][i] = true;
            start = i;
            length = 1;
        }
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                length = 2;
            }
        }
        for(int k = 3; k <= n;k++){
            for(int i = 0; i <= n-k;i++){
                int j = i + k - 1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(length < k){
                        length = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,length);
    }
};


//Without DP

class Solution {
public:
    vector<int> expand(string s, int leftIndex, int rightIndex){
        vector<int> ans;
        while(leftIndex >= 0 && rightIndex < s.size()){
            if(s[leftIndex] == s[rightIndex]){
                leftIndex--;
                rightIndex++;
            }else{
                break;
            }
        }
        return {leftIndex + 1, rightIndex};
    }
    
    
    string longestPalindrome(string s) {
        vector<int> longest{0,1};
        int maxLength = -1;
        int leftIndex, rightIndex;
        for(int i = 1; i < s.size();i++){
            vector<int> odd = expand(s, i-1, i+1);
            vector<int> even = expand(s, i-1, i);
            vector<int> currentMax = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
            longest = currentMax[1] - currentMax[0] > longest[1] - longest[0] ? currentMax: longest;
        }
        return s.substr(longest[0], longest[1]-longest[0]);
    }
};