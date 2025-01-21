/*
   Version:  1.3.0
   Date:     1/18/2025
*/

#include <stdio.h>
#include <stdlib.h>

int main(int a,char**v) {
    FILE*f;char*c,b[0xFFF]={0},*p=b;
    if(a!=2||!(f=fopen(v[1],"r")))return 0x16;
    fseek(f,0,SEEK_END);long z=ftell(f),s[0xFFF],k=0;rewind(f);
    if(!(c=malloc(z+1)))return fclose(f),0xC;fread(c,1,z,f);fclose(f);
    for(long i=0;c[i];i++)switch(c[i]){
        case'+':++*p;break;case'-':--*p;break;case'>':++p;break;case'<':--p;break;
        case'[':if(*p)s[k++]=i;else for(int n=1;n;n+=(c[++i]=='[')-(c[i]==']'));break;
        case'.':putchar(*p);break;case',':*p=getchar();break;case']':*p?i=s[k-1]:--k;
    } return free(c),0;
}
