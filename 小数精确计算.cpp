#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c;
    int kase=0;
    while(scanf("%d%d%d",&a,&b,&c)){
        if(a==0&&b==0&&c==0) break;
        int x=floor((double)a/b);  //向下取整，不大于x的最大整数
        printf("%d.",x);       //输出整数部分

        int i,s;
        for(i=1;i<c;i++){                 //小数点后前c-1位
            a*=10;
            s=floor((double)(a/b));
            printf("%d",s%10);
            a%=b;
        }
        a*=10;
        s=floor((double)a/b+0.5);         //小数点后第c位
        printf("%d",s);
        printf("\n");
    }
    return 0;
}
