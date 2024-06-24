#include <stdio.h>
#include <stdbool.h>
bool is_in_area(int i,int j){
        if(((i-10)*(i-10)+(j-10)*(j-10))>=25 && ((i-10)*(i-10)+(j-10)*(j-10)<=100)){
                return 1;
        } else {
                return 0;
        }
}
int min(int i, int j){
        if(i<=j){
                return i;
        } else {
                return j;
        }
}
int max(int i, int j){
        if(i>=j){
                return i;
        } else {
                return j;
        }
}
int abc(int a){
        if(a<0){
		return -a;
        } else {
		return a;                                                                                                                        
        }
}
int sign(int a) {
        if(a>0){
                return 1;
        } else if(a<0){
                return -1;
        } else {
                return 0;
        }
}
int mod(int a, int b){
        if(a>=0 || a%b==0){
                return a%b;
        } else {
                return b*((abc(a)/b)+1)-abc(a);
        }
}
int main(){
        int i=1;
        int j=-30;
        int l=1;
        int a,b,c;
        for(int k=0;k<50;k++){
                if(k>0){
                        a=i;
                        b=j;
                        c=l;
                        i=max(min(a+b-c-(k-1),a-b+c-(k-1)),min((k-1)+a-b-c,(k-1)-a-b+c));
                        j=b+mod(c*sign(b),20)+mod((k-1)*sign(a),10);
                        l=abc(a-b+c-(k-1))*sign(a)*sign(b);
                }
                if(is_in_area(i,j)==1){
                        printf("%d %d %d %d\n",i,j,l,k);
                        return 0;
                }
                if(is_in_area(i,j)==0 && k==49){
                        printf("%d %d %d %d %s\n",i,j,l,k,"The End");
                }
        }
}
