class MedianFinder {
    
public:
   priority_queue<int> smallHeap ; 
   priority_queue<int , vector<int> , greater<int>> largeHeap  ; 

    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
   
        
        if (!smallHeap.empty() && num > smallHeap.top()) largeHeap.push(num);
        else smallHeap.push(num);
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } else if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};
