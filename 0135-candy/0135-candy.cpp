class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<vector<int>> v;//make vector for store element of rating with index and want get fist minimum rating element and give him minimum candy 1
        for(int i = 0; i < ratings.size(); i++){
            v.push_back({ratings[i],i});
        }
        sort(v.begin(),v.end());
        int n = ratings.size(),x = 0, k= 0;
        vector<int> ans(n,0);
        for(auto &i: v){
            x = 0;
            if(i[1]-1>=0&&ratings[i[1]]>ratings[i[1]-1]){//if ith index person have rating >= left person than he desirve more candy compare to left
                x = max(x,ans[i[1]-1]);
            }
            if(i[1]+1 < n&&ratings[i[1]]>ratings[i[1]+1]){//same for right.
                x = max(x,ans[i[1]+1]);
            }
            ans[i[1]] = x+1;//how much candy ith person get
            k += x+1;//total candy allocated
        }
        return k;
    }
};