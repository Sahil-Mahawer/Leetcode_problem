class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int total1 = 0,  start=0, end=0, count=0 , n=nums.size();

        unordered_map<int,int> freq;

        // Atleaast(k)
        while(end<n){

         freq[nums[end]]++;

         if(freq[nums[end]]==1){  // means koii new element aaya hai 
            count++;    // maintaining the count of new element
         }

         while(count==k){   // when count becomes equal to k ... 
            total1 += (n-end);  // toh uske aage ke saare element valid subarray mai count honge as we are find for atleast(k) elements
            
            // abb window size ko shrink krne ki turn hai ( from left side )

            freq[nums[start]]--;  // shrinking phase 

            if(freq[nums[start]]==0){ // mtlnb agr start prr jo element hai uski frequency  0 hogyi hai toh toh new elemnt ke count mai se bhi ik element kmm hojayga  
                count--;
            }
            start++;
         }
         end++;

        }

        start = 0, end = 0, count = 0;
        freq.clear();
        k++; // for Atleast(k+1)
        int total2=0;

        // Atleast(k+1)
        while(end<n){

         freq[nums[end]]++;

         if(freq[nums[end]]==1){ 
            count++;   
         }

         while(count==k){  
            total2 += (n-end);  
            
            

            freq[nums[start]]--;  

            if(freq[nums[start]]==0){  
                count--;
            }
            start++;
         }
         end++;

        }

        return total1-total2;  // Atleast(k) - Atleast(k+1)
    }
};