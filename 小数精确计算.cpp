#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c;
    int kase=0;
    while(scanf("%d%d%d",&a,&b,&c)){
        if(a==0&&b==0&&c==0) break;
        int x=floor((double)a/b);  //����ȡ����������x���������
        printf("%d.",x);       //�����������

        int i,s;
        for(i=1;i<c;i++){                 //С�����ǰc-1λ
            a*=10;
            s=floor((double)(a/b));
            printf("%d",s%10);
            a%=b;
        }
        a*=10;
        s=floor((double)a/b+0.5);         //С������cλ
        printf("%d",s);
        printf("\n");
    }
    return 0;
}
