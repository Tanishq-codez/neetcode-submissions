class MinStack {
    pair<int,int>* arr;
    int topp;

public:
    MinStack() {
        arr = new pair<int,int>[10000]; // safer size
        topp = -1;
    }
    
    void push(int val) {
        int currMin = (topp == -1) ? val : min(val, arr[topp].second);
        arr[++topp] = {val, currMin};
    }
    
    void pop() {
        if (topp >= 0)
            topp--;
    }
    
    int top() {
        return arr[topp].first;
    }
    
    int getMin() {
        return arr[topp].second;
    }
};
