class MedianFinder {
public:

priority_queue<int> leftside_maxheap;

priority_queue<int, vector<int>, greater<int>> rightside_minheap;

// giving prefernce to left side 

/*  
 -->>> leftside heap side can be equal to rightside heap 

   -->>>  or leftside heap can  have one extra element in it .... but not more than that ... if this happens then  we have to shift one element to the left heap to right heap 

   -->>> or if rightside heap size is greater then leftside heap  then shift one element from rightheap to leftside heap
   
 */


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(leftside_maxheap.empty() || num <= leftside_maxheap.top()){
            leftside_maxheap.push(num);  // always put first element on leftside .. i.e maxheap
        }
        else{
            rightside_minheap.push(num);
        }

        // balance the two heaps

        if(leftside_maxheap.size() > rightside_minheap.size() + 1){ // leftside_maxheap mai 1 se jyada element as compared to minheap... example if minheap has 2 elements then maxheap has 4 elements.

            rightside_minheap.push(leftside_maxheap.top());   // so shift one element to right side ..  
            leftside_maxheap.pop();

        }

        if(rightside_minheap.size() > leftside_maxheap.size()){
                leftside_maxheap.push(rightside_minheap.top());
                rightside_minheap.pop();
        }


    }
    
    double findMedian() {
        
        if(leftside_maxheap.size() > rightside_minheap.size()) // agr ik element jyada hai leftside mai
            return leftside_maxheap.top(); 
        
        else{
            double ans = leftside_maxheap.top() + rightside_minheap.top();
            ans  = ans/2;

            return ans;
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */