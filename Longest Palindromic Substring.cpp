class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 1;
        int len = s.length();
        int low, high;
        int start = 0;
        for(string::size_type iter = 1; iter < len; iter++)
        {
            low = iter-1;
            high = iter;
            while(low >= 0 && high < len && s[low] == s[high])
            {
                if(high-low+1 > maxLength)
                {
                    maxLength = high-low+1;
                    start = low;
                }
                --low;
                ++high;
            }

            low = iter-1;
            high = iter+1;
            while(low >= 0 && high < len && s[low] == s[high])
            {
                if(high-low+1 > maxLength)
                {
                    maxLength = high-low+1;
                    start = low;
                }
                --low;
                ++high;
            }
        }
        string str = "";
        for(int iter = start; iter < start+maxLength; iter++)
        {
            str += s[iter];
        }
        return str;

    }
};
