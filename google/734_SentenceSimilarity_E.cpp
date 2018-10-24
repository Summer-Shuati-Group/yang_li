class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        set<pair<string, string> > p(pairs.begin(), pairs.end());
        int cnt = 0;
        for (int i = 0; i < words1.size(); i++) {
            if (p.find(pair<string, string>(words1[i], words2[i])) != p.end() ||
            p.find(pair<string, string>(words2[i], words1[i])) != p.end() || words1[i] == words2[i]) {
                // find the designated pair in pairs vector 
                cnt++;
            }
        }
        return (cnt == words1.size());
    }
};