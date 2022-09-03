class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int start = 0;
        while(start <= end)
        {
            int mid = (start+end)/2;
        
        if(target==nums[mid])
          return mid;
            
        //left case
        if (nums[start]<= nums[mid]){
            if(target >=nums[start] && target <= nums[mid])
                end = mid -1;
            else
                start =  mid+1;
            
        }
        
        //right case
        else{
            if(target>= nums[mid] && target<= nums[end])
                start = mid+1;
            else
                end = mid -1;
            
        }
        }
        return -1;
     
    }
};