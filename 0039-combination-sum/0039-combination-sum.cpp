class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&v,int ind,vector<int>&candidates,int target)
    {
        if(candidates.size()==ind)
        {//if index equal to size of inp arr and target is zero push arr
            if(target==0)
            {
                ans.push_back(v);
            }
             return;
        }
       
        if(candidates[ind]<=target)
        {
            v.push_back(candidates[ind]);
            solve(ans,v,ind,candidates,target-candidates[ind]);
            v.pop_back();//pop element so that when we skip this index it is not included for call on line 20 as all calls includiung this have been done by line 17
        }
         solve(ans,v,ind+1,candidates,target);//dont include index
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(ans,v,0,candidates,target);
        return ans;
    }
};