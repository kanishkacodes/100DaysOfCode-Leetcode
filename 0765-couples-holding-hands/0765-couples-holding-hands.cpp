class Solution
{
	public:

	int minSwapsCouples(vector<int> &row)
	{
		int n = row.size();
		vector<int> par(n);
		vector<int> ans;
		int parent = 1;
		int swapCount = 0;
		map<int, vector < int>> obj;

		for (int i = 0; i < par.size(); i += 2)
		{
			par[i] = parent;
			par[i + 1] = parent;
			parent++;
		}

		int index = 0;
		for (int i = 0; i < row.size(); i += 2)
		{
			int u = row[i];
			int v = row[i + 1];
			if (par[u] != par[v])
			{
				ans.push_back(par[u]);
				ans.push_back(par[v]);
                obj[par[u]].push_back(index);
				obj[par[v]].push_back(index + 1);
                index+=2; 
			}
		}
        
		for (int i = 0; i < ans.size(); i += 2)
		{
			if (ans[i] != ans[i + 1])
			{
				swapCount++;
				int initIdx = i + 1;
				int newIdx = -1;
				int initval = ans[i + 1];
                
				if (obj[ans[i]][0] > i + 1)
				{
					newIdx = obj[ans[i]][0];
				}
				else
				{
					newIdx = obj[ans[i]][1];
				}

				swap(ans[initIdx], ans[newIdx]);

				if (obj[initval][0] == i + 1)
				{
					obj[initval][0] = newIdx;
				}

				if (obj[initval][1] == i + 1)
				{
					obj[initval][1] = newIdx;
				}
			}
			else
			{
				continue;
			}
		}
		return swapCount;
	}
};