#include<stdio.h>
#include<stdlib.h>
 
int n,k,count=0;          //ȫ�ֱ���
int a[21];
int isprime(int num){
    int i;
    for(i=2;i*i<=num;i++)
          if(num%i==0)
          return 0;
    return 1;
}
//p��ǵ�ǰԪ�ص��±꣬left ��ǻ��м�����ûѡ����
void dfs(int sum,int p,int left){     
    //��Ϊn-1�����������±꣬����leftΪ0ʱ��ĳһ������Ѿ����
     if(left==0){    
        if(isprime(sum)){
           count++;
           return ;
        }
    }
     //n-left�ǵ�ǰ��ѡ�±�����ֵ�������������ѡ��������Ϊ���ǰ��մ�ǰ�����˳���Դ˽���ѡ��
    else for(int i=p;i<=n-left;i++)  
          dfs(sum+a[i],i+1,left-1); //ÿ�ݹ�һ�Σ��ͻ�ѡ��һ��������left�ͼ�һ
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
 
