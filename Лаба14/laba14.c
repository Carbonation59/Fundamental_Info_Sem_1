#include <stdio.h>

int main() {
        int n;
        scanf("%d",&n);
        int c[n][n];
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        scanf("%d",&c[i][j]);
                }
        }
        int k=n-1;
        int q=0;
        for(int i=n-1;i>=0;i--){
                if(i==n-1){
                        for(int j=0;j<=i;j++){
                                printf("%d ",c[k][j]);
                                k--;
                                q=j;
                        }
                } else{
                        if(q==n-1){
                                k=n-1-i;
                                for(int j=n-1;j>=n-1-i;j--){
                                        printf("%d ",c[k][j]);
                                        k++;
                                        q=0;
                                }
                        } if(q==0){
                                k=i;
                                        for(int j=0;j<=i;j++){
                                                printf("%d ",c[k][j]);
                                                k--;
                                                q=n-1;
                                        }
                                }
                }
        }
        printf("\n");
}
