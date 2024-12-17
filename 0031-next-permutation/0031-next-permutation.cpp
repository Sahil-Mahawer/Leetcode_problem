class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        //  next_permutation(nums.begin(),nums.end());
        
        int pivot = -1;
        int n = arr.size();

        //find pivot element 

        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(arr.begin(), arr.end());
            return;
        }

        for(int i=n-1;i>pivot;i--){
            if(arr[i]>arr[pivot]){
                swap(arr[i],arr[pivot]);
                break;
            }
        }

        int i=pivot+1, j = n-1;
        while(i<=j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};