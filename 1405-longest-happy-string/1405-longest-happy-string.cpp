class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //using max heap
        priority_queue<pair<int,char>>pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string ans="";
        while(pq.size()>1){
            pair<int,char>one = pq.top();pq.pop();
            pair<int,char>two = pq.top();pq.pop();
           
            ans+=string(one.first>=2? 2:1,one.second);
            one.first-=one.first>=2? 2:1;
            
            ans+=string((two.first>=2 && two.first>=one.first)? 2:1,two.second);
            two.first-=(two.first>=2 && two.first>=one.first)? 2:1;

            if(one.first>0) pq.push(one);
            if(two.first>0) pq.push(two);
        }
        
        if(pq.empty()) return ans;
        ans+=string(pq.top().first>=2? 2:1,pq.top().second);

        return ans;
        
    }
};