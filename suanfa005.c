//分支限界法解决填数字
#include <stdio.h>
#include <conio.h>
#define MAX 100

//global variables
int count=0;//the number of '-'
int sum=0;//the number of the result
int p[MAX][MAX]={0};       //1 is '-'  0 is '+'
int n=0;
int half=0;//half=n*(n+1)/4

void back_triangle(int t);

int main()
{
    printf("Please input n:");    
    scanf("%d",&n);
    half=n*(n+1)/2;
    if(half%2!=0)
    {
        printf("The number that you input is not meaningful for this problem!");    
        getch();
        return 1;
    }
    half/=2;
    back_triangle(1);    
    printf("The result is %d",sum);
    getch();
    return 0;
}

void back_triangle(int t)
{
    if(count>half || t*(t-1)/2-count>half)//because of this,the "count==half" is not necessary
        return ;    
    if(t>n)   //the count==half is not necessary
    {
        sum++;
        //for(int temp=1;temp<=n;temp++)
        
           // for(int tp=1;tp<=n;tp++)
            
			//	printf("%d ",p[temp][tp]);    
                
           // printf("\n");
        
      //  printf("\n");
    }
    else
    {
        int i,j;
        for(i=0;i<2;i++)
        {
            p[1][t]=i;
            count+=i;
            for(j=2;j<=t;j++)
            {
                p[j][t-j+1]=(p[j-1][t-j+1]^p[j-1][t-j+2]);    
                count+=p[j][t-j+1];
            }

            back_triangle(t+1);

            for(j=2;j<=t;j++)
                count-=p[j][t-j+1];
            count-=i;
        }
    }
}
