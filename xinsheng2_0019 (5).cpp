#include<stdio.h>
int main()
{
  int l,r,k=0,f=0;
  scanf("%d%d",&l,&r);
  for(int i=l;i<=r;i++){
    k=0;
    for(int j=1;j<=r;j++){
      if(i%j==0){
        k++;
      }
    }
    if(k<=4){
        f++;
    } 
  }
  printf("%d",f);
  return 0;
}