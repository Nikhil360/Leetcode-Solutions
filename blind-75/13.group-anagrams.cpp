class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapper;
        for(auto word:strs){
            string nonSortedWord = word;
            sort(word.begin(), word.end());
            if(mapper.find(word) != mapper.end()){
                mapper[word].push_back(nonSortedWord);
            }else{
                mapper[word] = {nonSortedWord};
            }
        }
        vector<vector<string>> ans;
        for(auto el:mapper){
            ans.push_back(el.second);
        }
        return ans;
    }
};