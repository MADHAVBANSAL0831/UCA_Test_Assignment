int longestValidParentheses(char* s) {
        int arr[100000];
        int j=-1;
        int maxi=0;
        int dp[100000];
        for(int i=0;i<100000;i++)
        {
            dp[i]=0;
        }
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='(')
            {
                // st.push(i);
                arr[++j]=i;
            }
            else
            if(s[i]==')')
            {
                if(j>=0)
                {
                    // int x = st.top();
                    // st.pop();
                    int x  = arr[j];
                    j--;
                    if(x-1<0)
                    {
                        dp[i]=i-x+1;
                    }
                    else
                    {
                        dp[i]=dp[x-1]+i-x+1;
                    }

                    if(maxi<dp[i])
                    maxi=dp[i];
                }
            }
        }

        for(int i=0;i<5;i++)
        {
            printf("%d", dp[i]);
        }

        return maxi;
}