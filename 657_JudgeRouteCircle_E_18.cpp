class Solution {
public:
    bool judgeCircle(string moves) {
        int right = 0;
        int left = 0;
        int up = 0;
        int down = 0;
        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'R') right++;
            else if (moves[i] == 'L') left++;
            else if (moves[i] == 'U') up++;
            else if (moves[i] == 'D') down++;
        }
        return ((right == left) && (up == down));
    }
};