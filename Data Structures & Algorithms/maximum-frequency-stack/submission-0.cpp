class FreqStack {
   public:
    int maxcnt;
    unordered_map<int, int> freqcnt;
    unordered_map<int, stack<int>> stacks;
    FreqStack() { maxcnt = 0; }

    void push(int val) {
        freqcnt[val]++;
        if (maxcnt < freqcnt[val]) {
            maxcnt++;
            stack <int> s ; 
            stacks[maxcnt] = s;
        }

        stacks[freqcnt[val]].push(val);
    }

    int pop() {
        int res = stacks[maxcnt].top();
        freqcnt[res]-- ; 
        stacks[maxcnt].pop();
        if (stacks[maxcnt].empty()) maxcnt--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */