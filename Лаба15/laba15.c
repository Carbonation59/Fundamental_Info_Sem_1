#include <stdio.h>

int min(int a, int b){
        if(a<b){
                return a;
        } else {
                return b;
        }
}

int main() {
        int n;
        scanf("%d",&n);
        int c[n][n];
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        scanf("%d",&c[i][j]);
                }
        }
        for(int i=n-2;i>0;i--){
                int m=min(i,n-1-i);
                int k=i-m;
                int q=n-1-i-m; // k и q - координаты первой точки отрезка, параллельного главной диагонали, который проходит через текущую точку побочной диагонали.
                int y=0;
                while(y<m){
                c[i][n-1-i]=c[i][n-1-i]+c[k][q];
                k++;
                q++;
		y++;
		}
                y=0;
                k++;
                q++;
                while(y<m){
                c[i][n-1-i]=c[i][n-1-i]+c[k][q];
                k++;
                q++;
                y++;
                }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        printf("%d ",c[i][j]);
                }
                printf("\n");
        }
} 
