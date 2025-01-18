/*
   Version:  1.0.0
   Date:     1/18/2025
*/

#include<stdio.h>
#include<stdlib.h>
int main(int a,char**v){
    FILE*f;char*c,b[0xFFF]={0},*p=b;
    if(a!=2||!(f=fopen(v[1],"r")))return 0x16;
    fseek(f,0,2);long s=ftell(f);rewind(f);
    if(!(c=malloc(s+1)))return fclose(f),0xC;fread(c,1,s,f);fclose(f);
    for(long i=0;c[i];i++)switch(c[i]){
        case'+':++*p;break;case'-':--*p;break;case'>':p++;break;case'<':p--;break;
        case'.':putchar(*p);break;case',':*p=getchar();break;
		case']':if(*p)for(int n=1;n;n+=(c[--i]==']')-(c[i]=='['));break;
        case'[':if(!*p)for(int n=1;n;n+=(c[++i]=='[')-(c[i]==']'));break;
	}
	return free(c),0x0;
}
