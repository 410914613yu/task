#include<stdio.h>
#include<stdlib.h>
 
int n,k,count=0;          //全局变量
int a[21];
int isprime(int num){
    int i;
    for(i=2;i*i<=num;i++)
          if(num%i==0)
          return 0;
    return 1;
}
//p标记当前元素的下标，left 标记还有几个数没选出来
void dfs(int sum,int p,int left){     
    //因为n-1是数组最大的下标，所以left为0时，某一种组合已经完成
     if(left==0){    
        if(isprime(sum)){
           count++;
           return ;
        }
    }
     //n-left是当前所选下标的最大值，若超过，则会选不够；因为这是按照从前往后的顺序以此进行选择
    else for(int i=p;i<=n-left;i++)  
          dfs(sum+a[i],i+1,left-1); //每递归一次，就会选出一个数来，left就减一
}
int main(){
   int i;
   scanf("%d %d",&n,&k);
   for(i=0;i<n;i++)
   scanf("%d",a+i);
   dfs(0,0,k);
   printf("%d\n",count);
   return 0;
}
 
