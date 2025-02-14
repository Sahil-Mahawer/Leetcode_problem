class ProductOfNumbers {
public:
vector<int> store;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        store.push_back(num);
    }
    
    int getProduct(int k) {
        int prod=1;
        int i= store.size()-1;
        while(k){
            prod = prod*store[i];
            i--;
            k--;
        }

        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */