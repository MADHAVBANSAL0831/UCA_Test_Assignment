bool isValid(char* s) {
    int n = strlen(s);
    int arr[100000];
    int j=-1;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            arr[++j]=s[i];
        }
        else
        if(j>=0)
        {
            char x = arr[j];
            j--;
            if(s[i]==')' && x=='(' || s[i]=='}' && x=='{' || s[i]==']' && x=='[')
            continue;
            else
            return 0;
        }
        else
        return 0;
    }

    if(j>=0)
    return 0;
    return 1;
}