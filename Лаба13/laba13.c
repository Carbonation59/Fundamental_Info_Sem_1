#include <stdio.h>
#include <stdbool.h>

const int rus_A=1040;
const int rus_YA=1071;
const int rus_a=1072;
const int rus_ya=1103;
const int rus_YO=1025;
const int rus_yo=1105;

const int rus_e=1077;
const int rus_u=1080;
const int rus_o=1086;
const int rus_y=1091;
const int rus_bl=1099;
const int rus_3=1101;
const int rus_yu=1102;

bool is_sep(char c){
        return c==' ' || c=='\n' || c=='\t' || c==EOF;
}

bool is_alpha(int c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                return 1;
        }
        return 0;
}

bool bykva_li(int c){
        if((c>=rus_a && c<=rus_ya) || (c>=rus_A && c<=rus_YA) || (c==rus_YO) || (c==rus_yo)){
                return 1;
        }
        return 0;
}

unsigned int char_to_set(int c){
        if(c>='a' && c<='z'){
                return 1u << (c-'a');
        }
        if(c>='A' && c<='Z'){
                return 1u << (c-'A');
        }
        if((c>=rus_a && c<=rus_ya)){
                return 1u << (c-rus_a);
        }
        if((c>=rus_A && c<=rus_YA)){
                return 1u << (c-rus_A);
        }
        if(c==rus_YO || c==rus_yo){
                return 1u << 0;
        }

        return 0;
}

int red_point(){
        int c=getchar();
        if(c==EOF){
                return EOF;
        }
        if(c>=192 && c<224){
                int c1=getchar();
                return ((c&((1<<5)-1))<<6)|(c1&((1<<6)-1));
        } else if(c>=224 && c<240){
                int c1=getchar();
                int c2=getchar();
                return ((((c&((1<<4)-1))<<5)|(c1&((1<<5)-1)))<<6)|(c2&((1<<6)-1));
        } else if(c>=240 && c<248){
                int c1=getchar();
                int c2=getchar();
                int c3=getchar();
                return ((((((c&((1<<4)-1))<<5)|(c1&((1<<5)-1)))<<6)|(c2&((1<<6)-1)))<<6)|(c3&((1<<6)-1));
        } else if(c>=248 && c<252){
                int c1=getchar();
                int c2=getchar();
                int c3=getchar();
                int c4=getchar();
                return ((((((((c&((1<<4)-1))<<5)|(c1&((1<<5)-1)))<<6)|(c2&((1<<6)-1)))<<6)|(c3&((1<<6)-1)))<<6)|(c4&((1<<6)-1));
        } else if(c>=252 && c<254){
                int c1=getchar();
                int c2=getchar();
                int c3=getchar();
                int c4=getchar();
                int c5=getchar();
                return ((((((((((c&((1<<4)-1))<<5)|(c1&((1<<5)-1)))<<6)|(c2&((1<<6)-1)))<<6)|(c3&((1<<6)-1)))<<6)|(c4&((1<<6)-1)))<<6)|(c5&((1<<6)-1));
        }
        return c;
}

typedef enum{
        LOOKING_FOR_WORD,
        READING_WORD,
        TRUE_WORD,
        VOWEL,
        NOT_VOWEL,
        EOOF
} state_t;

int main() {
        state_t state=LOOKING_FOR_WORD;
        unsigned int vowels=char_to_set('a')|char_to_set('e')|char_to_set('i')|char_to_set('o')|char_to_set('u')|char_to_set('y');
        unsigned int glasnye=char_to_set(rus_a)|char_to_set(rus_e)|char_to_set(rus_yo)|char_to_set(rus_u)|char_to_set(rus_o)|char_to_set(rus_y)|char_to_set(rus_bl)|char_to_set(rus_3)|char_to_set(rus_yu)|char_to_set(rus_ya);
        int sum=0;
        while(state!=EOOF){
                int c=red_point();
                unsigned int y=char_to_set(c);
                if(state==LOOKING_FOR_WORD){
                        if(!is_sep(c)){
                                if(((y&vowels)!=0 && (is_alpha(c))) || ((y&glasnye)!=0 && (bykva_li(c)))){
                                        state=TRUE_WORD;
                                } else{
                                        state=READING_WORD;
                                }
                        } else if(c==EOF){
                                state=EOOF;
                        }
                } else if(state==READING_WORD || state==TRUE_WORD || state==NOT_VOWEL || state==VOWEL){
                        if((state==TRUE_WORD || state==NOT_VOWEL || state==VOWEL) && !(is_sep(c))){
                                if(((y&vowels)!=0 && (is_alpha(c))) || ((y&glasnye)!=0 && (bykva_li(c)))){
                                        state=VOWEL;
                                } else {
                                        state=NOT_VOWEL;
                                }
                        }
                        if(is_sep(c)){
                                if(state==VOWEL || state==TRUE_WORD){
                                        sum++;
                                }
                                state=LOOKING_FOR_WORD;
                                if(c==EOF){
                                        state=EOOF;
                                }
                        }
                }
        }
        if(sum!=0){
                printf("\n%s\n%d\n","YES",sum);
        } else{
                printf("\n%s\n","NO");
        }
}
