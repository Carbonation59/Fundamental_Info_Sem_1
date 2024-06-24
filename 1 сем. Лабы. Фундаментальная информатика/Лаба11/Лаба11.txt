#include <stdio.h>
#include <stdbool.h>

bool is_sep(char c){
        return c==' ' || c=='\n' || c=='\t';
}

bool is_letter(char c){
        return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

bool is_digit(char c){
        if(c<'0' || c>'9'){
                return 0;
        } else {
                return 1;
        }
}

bool is_underline(char c){
        return c=='_';
}

typedef enum{
        LOOKING_FOR_WORD,
        READING_WORD,
        NO_WORD,  
	TRUE_WORD
} state_t;
      
int main() {
        int c=getchar();
        state_t state=LOOKING_FOR_WORD;
        int sum=0;
        state_t y=NO_WORD;
        while(c!=EOF){
                if(state==LOOKING_FOR_WORD){
                        if(!is_sep(c)){
                                if(is_letter(c) || is_underline(c)){
                                        y=TRUE_WORD;
                                }
                                state=READING_WORD;
                        }
                } else if(state==READING_WORD){
                        if(is_sep(c)){
                                if(y==TRUE_WORD){
                                        y=NO_WORD;
                                        sum++;
                                }
                                state=LOOKING_FOR_WORD;
                        }
                        if(y==TRUE_WORD){
                                if(!is_letter(c) && !is_underline(c) && !is_digit(c)){
                                        y=NO_WORD;
                                }
                        }
                }
                c=getchar();
        }
        if(y==TRUE_WORD){
                sum++;
        }
        printf("%d\n",sum);
}
