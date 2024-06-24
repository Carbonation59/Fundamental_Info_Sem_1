#include <stdio.h>

int laba12(int n){
        if(n>9 || n<-9) {
                int j=(n/10)%10;
                int f=n;
                int k=1;
                while(f>=100 || f<=-100){
                        f=f/10;
                        k=k*10;
                }
                f=f%10;
                return n-f*k+j*k-j*10+f*10;
        } else{
                return n;
        }
}

int main() {
        int n;
        while(scanf("%d",&n)==1){
                printf("%d\n", laba12(n));
        }
}
