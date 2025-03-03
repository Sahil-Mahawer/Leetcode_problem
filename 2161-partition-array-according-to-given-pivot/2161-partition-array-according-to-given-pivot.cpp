class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int> less;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
        }

        vector<int> equal;

         for(int i=0;i<n;i++)
        {
            if(nums[i]==pivot){
                equal.push_back(nums[i]);
            }
        }

        vector<int> greater;

         for(int i=0;i<n;i++)
        {
            if(nums[i]>pivot){
                greater.push_back(nums[i]);
            }
        }

       less.insert(less.end()/*postion*/ , equal.begin() /*start_iterator*/  , equal.end() /*end_iterator*/ );

       less.insert(less.end()/*postion*/ , greater.begin() /*start_iterator*/ , greater.end() /*end_iterator*/ );

        return less;
        
    }
};