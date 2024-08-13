#include<stdio.h>
#include<stdlib.h>

int graph[40][40],n,count=0;

void warshall(int n){

for(int k=0;k<n;k++)
{

 for(int i=0;i<n;i++)
 {
   if(graph[i][k]==1)
  {
     for(int j=0;j<n;j++)
     {
     count++;
     graph[i][j]=(graph[i][j]||(graph[i][k]&&graph[k][j]));
     }
   }
  }
 }
}

  void tester()
{
 printf("\n enter the num of vertices");
 scanf("%d",&n);
 printf("\n enter the adjacency matrix\n");
  for(int k=0;k<n;k++)
{
 for(int i=0;i<n;i++) {
  scanf("%d ",&graph[k][i]);
 } 
 }
  warshall(n);
  printf("\napplying the warshall's algorithm");
  printf("\ntransitive closure matrix\n");
  for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
   
    printf(" %d ",graph[i][j]);
   }
   printf("\n");
  }

printf("operation count =%d",count);
}

void plotter(int key){
FILE *fp1,*fp2;
fp1=fopen("warshallB.txt","a");
fp2=fopen("warshallW.txt","a");
 for(int i=2;i<=20;i+=2)
{
count=0;
n=i;

// best case
if(key==0){
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
   graph[i][j]=0;
 }
 for(int i=0;i<n;++i){
 graph[i][i+1]=1;
 }
}

//worst case
 if(key==1){
   for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   if(i==j)
   graph[i][j]=0;
   else
   graph[i][j]=1;
 }
 
 }
}
 warshall(n);
 if(key==0)
  fprintf(fp1,"%d\t%d\n",n,count);
 else
 fprintf(fp2,"%d\t%d\n",n,count);
 
}
fclose(fp1);
fclose(fp2);
}

void main()
{
tester();
for(int i=0;i<2;++i){
 plotter(i);
}

}



