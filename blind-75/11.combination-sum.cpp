class Solution {
public:
    void backtrack(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &currentStack, int index){
        if(target == 0){
            ans.push_back(currentStack);
            return;
        }
        if(target < 0 || index >= candidates.size())
            return;
        currentStack.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], ans, currentStack, index);//include current element
        currentStack.pop_back();
        backtrack(candidates, target, ans, currentStack, index+1);// Don't include current element
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currentStack;
        int index = 0;
        backtrack(candidates, target, ans, currentStack, index);
        return ans;
    }
};