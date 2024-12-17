class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
         next_permutation(arr.begin(),arr.end());
        
        // int pivot = -1;
        // int n = arr.size();

        // //find pivot element.. pivot element is element which is smaller than to its next element -- see from backward.. 
        // for(int i=n-2;i>=0;i--){
        //     if(arr[i]<arr[i+1]){
        //         pivot = i;
        //         break;
        //     }
        // }

        // // check if pivot exist or not .. if not exist return array in reverse order 
        // if(pivot == -1){
        //     reverse(arr.begin(), arr.end());
        //     return;
        // }

        // // now find element just greater than pivot .. it is always present at last..  because after pivot element , element are arranged in decreasing order.  and swap that element with pivot element 
        // for(int i=n-1;i>pivot;i--){
        //     if(arr[i]>arr[pivot]){
        //         swap(arr[i],arr[pivot]);
        //         break;
        //     }
        // }

        // //and at last reverse array from pivot+1 element to n-1 element
        // int i=pivot+1, j = n-1;
        // while(i<=j){
        //     swap(arr[i], arr[j]);
        //     i++;
        //     j--;
        // }
    }
};