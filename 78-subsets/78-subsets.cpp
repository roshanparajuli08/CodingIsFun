
class Solution {
    public:
    void printSubset(int index,vector<vector<int>>& ans, vector<int>& int_ans , vector<int> &nums){
        
        if(index == nums.size()){
            ans.push_back(int_ans);
            return;    
        }  
        //not take the number
        printSubset(index+1, ans, int_ans, nums);
        
         //take the number
          int_ans.push_back(nums[index]);
           printSubset(index+1, ans, int_ans, nums);
           int_ans.pop_back();     
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> int_ans;
        int index = 0;
        printSubset(index, ans, int_ans, nums);
        return ans;
        
}
};