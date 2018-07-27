class Solution {
public:
    //for IPv4
    bool isValidhey(string str)
    {
        if(str.length() > 3 || stoi(str) > 255 || stoi(str) < 0)
        {
            return false;
        }
        if(str.length() > 1 && str[0] == '0')
        {
            return false;
        }
        return true;
    }
    int isValidIPv4(string str)
    {
          //your code here

          if(str[str.length()-1] == '.')
          {
              return 0;
          }
          stack<string> st;
          string s = "";
          for(string::size_type iter = 0; iter < str.length(); iter++)
          {
              if(str[iter] == '.')
              {
                  if(s.length() == 0)
                  {
                      return 0;
                  }
                  else
                  {
                      st.push(s);
                      s = "";
                  }
              }
              else
              {
                  if(isdigit(str[iter]))
                  {
                      s = s+str[iter];
                      if(iter == str.length()-1)
                      {
                          st.push(s);
                      }
                  }
                  else
                  {
                      return 0;
                  }
              }
          }
          if(st.size() < 4 || st.size() > 4)
          {
              return 0;
          }
          while(!st.empty())
          {
             if(!isValidhey(st.top()))
             {
                 return 0;
             }
             st.pop();
          }
          return 1;
    }
    //Now will be starting for IPv6

    bool isvalidIP(string sr)
    {

       for(string::size_type iter = 0; iter < 4; iter++)
       {
           if(isdigit(sr[iter]))
           {
               continue;
           }
           if(isalpha(sr[iter]))
           {
               if(sr[iter] >= 'g' && sr[iter] <= 'z')
               {
                   return false;
               }
               if(sr[iter] >= 'G' && sr[iter] <= 'Z')
               {
                   return false;
               }
           }
       }
        return true;
    }
    bool isValidIPv6(string str)
    {
        string s = "";
        stack<string> st;
        if(str[str.length()-1] == ':')
        {
            return false;
        }
        for(string::size_type iter = 0; iter < str.length(); iter++)
        {
            if(str[iter] == ':')
            {
                if(s.length() == 0)
                {
                    return false;
                }
                else
                {
                    if(s.length() > 4)
                    {
                        return false;
                    }
                    st.push(s);
                    s = "";
                }
            }
            else
            {
                if(str[iter] == '-' || str[iter] == '+')
                {
                    return false;
                }
                s = s + str[iter];
                if(iter == str.length()-1)
                {
                    if(s.length() > 4)
                    {
                        return false;
                    }
                    st.push(s);
                }
            }
        }
        if(st.size() < 8 || st.size() > 8)
        {
            return false;
        }
        while(!st.empty())
        {
            if(!isvalidIP(st.top()))
            {
                return false;
            }
            st.pop();
        }
        return true;
    }

    // main code...
    string validIPAddress(string IP) {
       if(isValidIPv4(IP))
        {
            return "IPv4";
        }
        if(isValidIPv6(IP))
        {
            return "IPv6";
        }
        return "Neither";
    }
};
