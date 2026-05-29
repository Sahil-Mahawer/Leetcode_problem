class Solution {
public:

int findpivot(vector<int>& nums, int n){

    int l = 0, r = n-1;

    while(l < r){

        int mid = l+(r-l)/2;

        if(nums[mid] > nums[r]){  // it is confirmed .. minimum element will exist in right side 
            l = mid + 1; 
        }
        else{
            r = mid;
        }
    }

    return r;
}

int binarySearch(int l, int r, vector<int>& nums, int target){

    int idx = -1;

    while(l <= r){

        int mid = l +(r-l)/2;

        if(nums[mid] == target){
            idx = mid;
            return idx;
        }
        else if(nums[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1; 
        }
    }

    return idx;
}
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        
        int pivot_index = findpivot(nums,n);  // find index of minimum element in rotated sorted array 

        int idx = binarySearch(0,pivot_index-1, nums, target);  // left side of pivot element 

        if(idx != -1){
            return idx;
        }

        idx = binarySearch(pivot_index, n-1, nums, target); //right side of pivot element including pivot element 

        return idx;
    }
};