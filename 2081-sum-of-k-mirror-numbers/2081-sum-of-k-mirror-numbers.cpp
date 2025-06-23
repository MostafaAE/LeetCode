class Solution {
public:
    /*
    * Approach:
    * - Generate decimal palindromes one by one in increasing order:
    *     - Odd-length palindromes
    *     - Even-length palindromes
    * - For each decimal palindrome, check if it is also a palindrome in base-k.
    * - Stop after finding n such k-mirror numbers.
    */
    long long kMirror(int k, int n) 
    {
        int left = 1, count = 0;
        long long ans = 0;

        while (count < n) 
        {
            int right = left * 10;

            // op = 0 → odd-length palindromes
            // op = 1 → even-length palindromes
            for (int op = 0; op < 2; ++op) 
            {
                for (int i = left; i < right && count < n; ++i) 
                {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);

                    // Mirror digits to form full palindrome
                    while (x) 
                    {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }

                    if (isKMirrored(combined, k)) 
                    {
                        ++count;
                        ans += combined;
                    }
                }
            }

            left = right;
        }

        return ans;
    }

private:
    bool isKMirrored(long long num, int k)
    {
        string kBase;

        while (num > 0)
        {
            int rem = num % k;
            kBase += (rem + '0');
            num /= k;
        }

        return isMirrored(kBase);
    }

    bool isMirrored(const string& s)
    {
        int left = 0, right = (int)s.size() - 1;

        while (left <= right)
        {
            if (s[left++] != s[right--])
                return false;
        }

        return true;
    }
};
