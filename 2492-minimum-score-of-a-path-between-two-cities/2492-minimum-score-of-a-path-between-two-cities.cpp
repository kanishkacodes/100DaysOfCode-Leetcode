class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {


        std::unordered_set<int> visitSet;
   std::unordered_map<int, std::unordered_map<int, int>> srcToDestToDist;
        int returnVal = INT_MAX;

        for(const auto& road : roads)
        {
            srcToDestToDist[road[0]][road[1]] = srcToDestToDist[road[1]][road[0]] = road[2];
        }

        visitSet.emplace(1);

        std::queue<int> roadQ;
        roadQ.emplace(1);
        while(roadQ.empty() == false)
        {
            int src = roadQ.front();
            roadQ.pop();

            for(auto& [dest, dist] : srcToDestToDist[src])
            {
                returnVal = std::min(returnVal, dist);

                if(visitSet.count(dest) == 0)
                {
                    roadQ.emplace(dest);
                    visitSet.emplace(dest);
                }
            }
        }

        return returnVal;
    }
};