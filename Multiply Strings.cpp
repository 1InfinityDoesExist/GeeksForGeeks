class Solution {
public:
    string multiply(string num1, string num2) {

        int neg = 0;
        if(num1[0] == '-')
        {
            neg++;
            num1.erase(num1.begin());
        }
        if(num2[0] == '-')
        {
            neg++;
            num2.erase(num2.begin());
        }
        int len1 = num1.length();
        int len2 = num2.length();
        string final(len1+len2, '0');
        int iter = len1-1;
        while(iter >= 0)
        {
            int carry = 0;
            int jter = len2-1;
            while(jter >= 0)
            {
                int temp = (final[iter+jter+1] - '0') + (num1[iter] - '0') * (num2[jter] -'0') + carry;
                final[iter+jter+1] = temp%10 + '0';
                carry = temp/10;
                jter--;
            }
            final[iter] += carry;
            iter--;
        }
        size_t startpos = final.find_first_not_of('0');
        if(string::npos != startpos)
        {
            string ans = final.substr(startpos);
            if(neg%2 == 0)
            {
                return ans.erase(0, ans.find_first_not_of('0'));
            }
            else
            {
                ans = '-' + ans.erase(0, ans.find_first_not_of('0'));
                return ans;

            }
        }
        return "0";
    }
};
