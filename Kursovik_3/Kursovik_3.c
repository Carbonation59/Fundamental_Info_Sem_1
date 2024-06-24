#include <stdio.h>
#include <math.h>

double epsilone(){
        double a=1;
        double c;
        while(a+1>1){
                c=a;
                a=a/2;
        }
        return c;
}

int main() {
        int n;
        scanf("%d",&n);
        printf("Machine epsilone is:%.16f\n",epsilone());
        printf("┌──────────────────────┬──────────────┬──────────────────────┬──────────────────────┬──────────────────────┐\n"
               "│         X            │   Iter_numb  │         Sum          │        Cos(x)        │        Delta         │\n"
               "├──────────────────────┼──────────────┼──────────────────────┼──────────────────────┼──────────────────────┤\n");

        int k=10;
        double delta=k*epsilone();
        double segment=1.0/n;
        double x=0;
        for(double i=0;i<=n;i++){
                x=segment*(i);
                double Teilor=1;
		double sum=1;
		long long factorial=1;
                int iteration_number;
                for(int j=1;j<=10;j++){
                        factorial=factorial*(j*2-1)*(j*2);
                        if(fabs(Teilor*x*x/factorial*(-1))>=delta){
                                Teilor=Teilor*x*x/factorial*(-1);
                                sum=sum+Teilor;
                                Teilor=Teilor*factorial;
                        } else {
                                iteration_number=j;
                                break;
                        }
                }
                printf("│  %.16f  │       %d      │  %.16f  │  %.16f  │     %e     │\n",x,iteration_number,sum,cos(x),fabs(sum-cos(x)));
                if(i<n){
                        printf("├──────────────────────┼──────────────┼──────────────────────┼──────────────────────┼──────────────────────┤\n");
                } else {
                        printf("└──────────────────────┴──────────────┴──────────────────────┴──────────────────────┴──────────────────────┘\n");
                }
        }
}
