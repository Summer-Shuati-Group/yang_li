class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (int i = 0; i < emails.size(); i++) {
            int j = 0;
            // cout << "found: " << found << endl;
            while (emails[i][j] != '@') {
                if (emails[i][j] == '.') {
                    emails[i].erase(emails[i].begin() + j);
                }
                if (emails[i][j] == '+') {
                    size_t found = emails[i].find('@');
                    emails[i].erase(emails[i].begin() + j, emails[i].begin() + found);
                    break;
                }
                j++;
            }
            // cout << emails[i] << endl;
            s.insert(emails[i]);
        }
        return s.size();
    }
};