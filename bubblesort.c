#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int bubbles(int a[],int n){
int count=0;
 for(int i=0;i<n;i++){
  int flag=0;
 for(int j=0;j<n-i-1;j++)
{
 count++;
  if(a[j]>a[j+1])
{
 int temp=a[j];
 a[j]=a[j+1];
 a[j+1]=temp;
 flag=1;
 }
}
 if(flag==0)
 break;
}
if(n<=10){
printf("\n sorted array is given as");
for(int i=0;i<n;i++)
printf("%d\t",a[i]);
}
 return count;
}

void exec()
{
 FILE *fp1,*fp2,*fp3;
 fp1=fopen("bubbleB.txt","w");
 fp2=fopen("bubbleA.txt","w");
 fp3=fopen("bubbleW.txt","w");
 int count;
 
 // best case
 for(int i=5;i<=50;i+=5){
 
 int a[i];
  if(i<=10)
 {
 printf("\n enter the %d best case array elemnts\n",i);
 for(int j=0;j<i;j++)
 scanf("%d",&a[j]);
 count=bubbles(a,i);
 printf("\ncount = %d",count);
 }
 else{
 for(int j=0;j<i;j++)
 a[j]=j+3;
 count=bubbles(a,i);
 }
 fprintf(fp1,"%d\t%d\n",i,count);
 }
 
 //average case
 for(int i=5;i<=50;i+=5){
 int a[i];
  if(i<=10)
 {
 printf("\n enter the %d avg case array elemnts\n",i);
 for(int j=0;j<i;j++)
 scanf("%d",&a[j]);
 count=bubbles(a,i);
 printf("\ncount = %d",count);
 }
 else{
 for(int j=0;j<i;j++)
 a[j]=rand()%i;
 count=bubbles(a,i);
 }
 fprintf(fp2,"%d\t%d\n",i,count);
 }
 
 // worst case
 for(int i=5;i<=50;i+=5){
 int a[i];
  if(i<=10)
 {
 printf("\n enter the %d worst case array elemnts\n",i);
 for(int j=0;j<i;j++)
 scanf("%d",&a[j]);
 count=bubbles(a,i);
 printf("\ncount = %d",count);
 }
 else{
 for(int j=0;j<i;j++)
 a[j]=i-j+1;
 count=bubbles(a,i);
 }
 fprintf(fp3,"%d\t%d\n",i,count);
 }
 
}

void main()
{
exec();
}
