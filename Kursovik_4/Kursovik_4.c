#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef double(*function)(double);

double epsilone(){
        double a=1;
        double c;
        while(a+1>1){
                c=a;
                a=a/2;
        }
        return c;
}

double e;

double func_A(double x){
        return 0.4+atan(sqrt(x))-x;
}
double func_B(double x){
        return 3*sin(sqrt(x))+0.35*x-3.8;
}

typedef struct{
        int iter_number;
        double root;
	bool success; 
} result;

result diho(function g,double a, double b, double delta){
        result answer;
        answer.iter_number=0;
        answer.root=0;
        answer.success=true;
        if(g(a)*g(b)>0){
                answer.success=false;
                return answer;
        }
        if(g(a)==0){
                answer.root=a;
                return answer;
        }
        if(g(b)==0){
                answer.root=b;
                return answer;
        }
        double mid;
        while(b-a>delta){
                mid=(b+a)/2;
                if(g(a)*g(mid)<0){
                        b=mid;
                } else {
                        a=mid;
                }
                answer.iter_number++;
        }
        answer.root=(a+b)/2;
        return answer;
}

double df(function f, double x){
        double dx=x*sqrt(e);
	if(x>e*1000*(-1) && x<e*1000){
		dx=sqrt(e);
	}
        return ((f(x+dx)-f(x-dx))/(2*dx));
}

double ddf(function f, double x){
        double dx=x*pow(e,1/3.0);
	if(x>e*1000*(-1) && x<e*1000){
		dx=sqrt(e);
	}
        return (f(x+2*dx)-2*f(x)+f(x-2*dx))/(4*dx*dx);
}

result newton(function g, double a, double b, double delta){
        double x=(a+b)/2;
        result answer;
        answer.iter_number=0;
        answer.root=0;
        answer.success=true;
        if(fabs(g(x)*ddf(g,x))>df(g,x)*df(g,x)){
                answer.success=false;
                return answer;
        }
        while(fabs(x-g(x)/df(g,x)-x)>delta){
                if(fabs(g(x)*ddf(g,x))<df(g,x)*df(g,x)){
                        x=x-g(x)/df(g,x);
                } else{
                        answer.success=false;
                        return answer;
                }
                answer.iter_number++;
        }
        answer.root=x;
        return answer;
}

double func_fi(function f, double x){
        return x-f(x)/df(f,x);
}


double df_fi(function f, double x){
        double dx=x*sqrt(e);
	if(x>e*1000*(-1) && x<e*1000){
		dx=sqrt(e);
	}
        return (func_fi(f,x+dx)-func_fi(f,x-dx))/(2*dx);
}

result iter(function f,double a, double b, double delta){
        result answer;
        answer.iter_number=0;
        answer.root=0;
        answer.success=true;
        double x=(a+b)/2;
        if(fabs(df_fi(f,x))>1){
                answer.success=false;
                return answer;
        }
        while(fabs(func_fi(f,x)-x)>delta){
                if(fabs(df_fi(f,x))<1){
                        x=func_fi(f,x);
                } else {
                        answer.success=false;
                        return answer;
                }
                answer.iter_number++;
        }
        answer.root=x;
        return answer;
}

int main() {
        e=epsilone();
        double a,b,A,B;
        scanf("%lf%lf%lf%lf",&a,&b,&A,&B);
        int k=1000;
        double delta=e*k;
        result answer_diho_1=diho(func_A,a,b,delta);
        result answer_diho_2=diho(func_B,A,B,delta);
        result answer_iter_1=iter(func_A,a,b,delta);
        result answer_iter_2=iter(func_B,A,B,delta);
        result answer_newton_1=newton(func_A,a,b,delta);
        result answer_newton_2=newton(func_B,A,B,delta);
        printf("Function 1:\n\n");
        printf("Dihotomia: ");
        if(answer_diho_1.success){
                printf("%d %.4f\n",answer_diho_1.iter_number,answer_diho_1.root);
        } else {
                printf("Impossible\n");
        }
        printf("Iteration: ");
        if(answer_iter_1.success){
                printf("%d %.4f\n",answer_iter_1.iter_number,answer_iter_1.root);
        } else {
                printf("Impossible\n");
        }
        printf("Newton: ");
        if(answer_newton_1.success){
                printf("%d %.4f\n",answer_newton_1.iter_number,answer_newton_1.root);
        } else {
                printf("Impossible\n");
        }
        printf("\nFunction 2:\n\n");
        printf("Dihotomia: ");
        if(answer_diho_2.success){
                printf("%d %.4f\n",answer_diho_2.iter_number,answer_diho_2.root);
        } else {
                printf("Impossible\n");
        }
        printf("Iteration: ");
        if(answer_iter_2.success){
                printf("%d %.4f\n",answer_iter_2.iter_number,answer_iter_2.root);
        } else {
                printf("Impossible\n");
        }
        printf("Newton: ");
        if(answer_newton_2.success){
                printf("%d %.4f\n",answer_newton_2.iter_number,answer_newton_2.root);
        } else {
                printf("Impossible\n");
        }

}
