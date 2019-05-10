#include<stdio.h>
#include<string.h>
int main()
{
    int i, j, n,x=0,y=0;
    char s[30],b[30],c[30], t;
    scanf("%s", s);       //ÊäÈë×Ö·û´®
    n = strlen(s);  //»ñÈ¡´®³¤n
    for (i = 0; i < n - 1; i++) //Ã°ÅÝÅÅÐò
        for (j = 0; j < n - 1 - i; j++)
            if (s[j] > s[j + 1])
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
    for(i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			c[x++]=s[i];
		}
		else
		{
			b[y++]=s[i];
		}
	}
	c[++x]='\0';        
    printf("%s", b);
	printf("%s",c);  //Êä³ö
    return 0;
}
