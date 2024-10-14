#include<stdio.h>

int main()
{
  char m;
  long long a;
  long long b;
  long long c;
  scanf("%c%lld%lld%lld",&m,&a,&b,&c);
  if(m=='*'){
    if(a*b==c){
      printf("Yes\n%lld%c%lld=%lld",a,m,b,c);
  }
    else{
      printf("No");
    }
}
    else if(m=='+'){
      if(a+b==c){
      printf("Yes\n%lld%c%lld=%lld",a,m,b,c);}
    else{
      printf("No");}
    }
    else if(m=='-'){
      if(a-b==c){
      printf("Yes\n%lld%c%lld=%lld",a,m,b,c);}
    else{
      printf("No");}
    }
    else if(m=='/'){
     if(a/b==c){
        printf("Yes\n%lld%c%lld%=%lld",a,m,b,c);}
      else{
        printf("No");}
    }
  return 0;

}
