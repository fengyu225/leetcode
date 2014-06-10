class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        
        vector<int> result;
        int n = L[0].size();
        int len = n * L.size();
        if(len > S.size())
            return result;
        
        map<string, int> m;
        for(int i=0;i<L.size();i++)
            m[L[i]]++; 
        int idx = 0;
        map<string, int> tmp;
        while(idx <= S.size() - len)
        {
            bool flag = true;
            tmp.clear();
            for(int i=idx;i<=idx+n*(L.size()-1);i+=n)
            {
                string now = S.substr(i, n);
                if(m.find(now) == m.end())
                {
                    flag = false;
                    break;
                }
                tmp[now]++;
                if(tmp[now] > m[now])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag == true)
                result.push_back(idx);
                
            idx++;
        }
        return result;
    }
};
