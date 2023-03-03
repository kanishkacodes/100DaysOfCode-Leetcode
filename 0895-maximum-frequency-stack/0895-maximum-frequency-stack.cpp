class FreqStack {
public:
    
    int Timeline = 0;
    priority_queue<vector<int>>pq;
    unordered_map<int,int>mp;
 
    void push(int val) { mp[val]++ , pq.push({mp[val],Timeline,val}) , Timeline++; }
    
    int pop(vector<int>Top={} , int ans = 0)
    {
        Top = pq.top() , pq.pop() , ans = Top[2] , mp[ans]--;
        return ans;
    }
};