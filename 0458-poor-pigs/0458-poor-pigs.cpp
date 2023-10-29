class Solution {
public:
  #define MAX_PIGS 10
int poorPigs(int buckets, int poisonTime, int totalTime) {
    int base = totalTime/poisonTime + 1;
    for (int i = 0; i < MAX_PIGS; i++) {
        if (powl(base,i) >= buckets)
            return i;
    }
    return MAX_PIGS;
}
};