class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if (n == 1) {
            if (s1 == s2) return 0;
            if (s1[0] == '1') return -1;
            return 1;
        }

        long long total = 0;
        long long count01 = 0;
        int i = 0;
        while (i < n) {
            if (s1[i] == '1' && s2[i] == '0') {
                int j = i;
                while (j < n && s1[j] == '1' && s2[j] == '0') j++;
                long long len = j - i;
                total += (len / 2) + 2 * (len % 2);
                i = j;
            } else {
                if (s1[i] == '0' && s2[i] == '1') count01++;
                i++;
            }
        }

        return (int)(total + count01);
    }
};
