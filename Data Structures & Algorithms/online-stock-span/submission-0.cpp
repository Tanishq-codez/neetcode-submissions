class StockSpanner {
   public:
    vector<int> v;
    stack <int> s;
    int idx ; 
    StockSpanner() {idx = 0 ; }

    int next(int price)
    { v.push_back(price); 
      
      while ( !s.empty() && v[s.top()] <= price){
        s.pop();
      }
      int res = idx +1 ; 
      if ( !s.empty())
      res = idx - s.top()  ;
      s.push(idx);
      idx++ ; 
      return res ;
      
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */