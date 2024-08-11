#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int selectionS(int a[],int n)
{
 int count=0;
 for(int i=0;i<n-1;i++){
  int pos=i;
 for(int j=i+1;j<n;j++){
  count++;
  if(a[j]<a[pos])
  pos=j;
 }
int temp=a[i];
a[i]=a[pos];
a[pos]=temp;
}
if(n<=10){
printf("\n sorted elements are\n");
for(int j=0;j<n;j++)
printf("%d\t",a[j]);
}
return count;
}

void exec()
{
FILE *fp1,*fp2,*fp3;
fp1=fopen("selectB.txt","w");
fp2=fopen("selectW.txt","w");
fp3=fopen("selectA.txt","w");
int count;
//best case
for(int i=5;i<=50;i+=5){
int a[i];
  if(i<=10)
 {
  printf("\n enter the %d best case array elements ",i);
  for(int j=0;j<i;j++)
  scanf("%d",&a[j]);
  count=selectionS(a,i);
   printf("\n count = %d",count);
 }
 else{
 for(int j=0;j<i;j++)
 a[j]=j+3;
 count=selectionS(a,i);
 }
 fprintf(fp1,"%d\t%d\n",i,count);
}

//average case
for(int i=5;i<=50;i+=5){
int a[i];
  if(i<=10)
 {
  printf("\n enter the %d avg case array elements ",i);
  for(int j=0;j<i;j++)
  scanf("%d",&a[j]);
  count=selectionS(a,i);
   printf("\n count = %d",count);
 }
 else{
 for(int j=0;j<i;j++)
 a[j]=rand()%i;
 count=selectionS(a,i);
 }
 fprintf(fp2,"%d\t%d\n",i,count);
}
//worst case
for(int i=5;i<=50;i+=5){
int a[i];
  if(i<=10)
 {
  printf("\n enter the %d best case array elements ",i);
  for(int j=0;j<i;j++)
  scanf("%d",&a[j]);
  count=selectionS(a,i);
   printf("\n count = %d",count);
 }
 else{
 for(int j=0;j<i;j++)
 a[j]=i-j+3;
 count=selectionS(a,i);
 }
 fprintf(fp3,"%d\t%d\n",i,count);
}
}

void main()
{
 exec();
}
