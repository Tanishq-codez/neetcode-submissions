class MyStack {
public:
    queue <int> one ;
    queue <int> two ; 
    MyStack() {
        
    }
    
    void push(int x) {
      two.push(x);
      while ( !one.empty()){
        two.push(one.front());
        one.pop();
      }  
      swap(one , two );
    }
    
    int pop() {
       int top = one.front();
       one.pop();
       return top ; 
    }
    
    int top() {
        return one.front();
    }
    
    bool empty() {
        return one.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */