class Solution {
public:
    void sortColors(vector<int>& arr) {
       int n= arr.size();
       int high = n-1, mid = 0, low = 0;

       while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            low++;  // as low-1 should point to last 0 thats why low++
            mid++; // mid always pont to unsorted array that why mid++
        }

        else if(arr[mid]==1){
            mid++; // now by doing this mid-1 points to last 1 and mid is pointing to unsorted elements
        }

        else{ // arr[mid]==2
        
            swap(arr[mid], arr[high]);
            high--; // by doing this high+1 will point to 2 (new element that is inserted by doing high++) and from range mid to high always point to unsorted element. 
        }
       } 

    }
};