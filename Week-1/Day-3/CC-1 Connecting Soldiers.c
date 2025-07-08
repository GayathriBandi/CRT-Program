#include <stdio.h>
int f(int n)
{   int x,y;
    if(n == 0)
    return 0;
    if(n & 1)
    {  x=y=n/2;
    }
    else
    {   x=n/2-1;
        y=n/2;
    }
    return n+1+f(x)+f(y);
}
    int main(void)
    {   int n,a,b;
        scanf("%d",&n);
        while(n--)
        {   scanf("%d%d",&a,&b);
            int max,min;
            min=f(a);
            max=a*(a+3)/2;
            if(b<min)
            printf("-1\n");
            else if(b>max)
            printf("%d\n",b-max);
            else
            printf("0\n");
    }
	return 0;
}
