class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int num = minutesToTest / minutesToDie;
        return (log(buckets)/ log(num + 1));
    }
};