#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d", &t);
    while(t--!=0)
    {
        int arr[100];
        int j=-1;
        char s[10];
        scanf("%s", s);
        
        while(s[0]!='?')
        {
            // printf("%s", s);
            if(s[0]>='0' && s[0]<='9') 
            {
                int ind=0;
                int no=0;
                while(s[ind]!='\0')
                {
                    no=no*10+(s[ind]-'0');
                    ind++;
                }
                arr[++j]=no;
            }
            else
            {
                int a = arr[j];
                j--;
                int b = arr[j];
                j--;
                

                // printf("%d%d%c ", a, b, s[0]);
                
                if(s[0]=='*')
                    arr[++j]=a*b;
                if(s[0]=='/')
                    arr[++j]=b/a;
                if(s[0]=='-')
                    arr[++j]=b-a;
                if(s[0]=='+')
                    arr[++j]=a+b;
            }
            
            scanf("%s", s);
        }
        
        printf("%d\n", arr[0]);
        // free(s);
        
        // printf("  ");
     
    }
}
