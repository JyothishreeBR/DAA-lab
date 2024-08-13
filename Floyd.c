#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int graph[40][40],n,count=0;

void floyd(int n){
 for(int k=0;k<n;++k){
 
  for(int i=0;i<n;++i){
  
    for(int j=0;j<n;++j){
    if(graph[i][j]>graph[i][k])
    {
     count++;
    if(graph[i][k]+graph[k][j]<graph[i][j])
      graph[i][j]=graph[i][k]+graph[k][j];
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
  floyd(n);
  printf("\napplying the floyd's algorithm");
  printf("\nall pair shortest path matrix\n");
  for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
   
    printf(" %d ",graph[i][j]);
   }
   printf("\n");
  }

printf("operation count =%d",count);
}

void plotter()
{
FILE *fp1;
fp1=fopen("floydG.txt","a");
for(n=1;n<=10;n++){
count=0;
 for(int j=0;j<n;j++){
  for(int k=0;k<n;k++){
   if(j==k)
   graph[j][k]=0;
   else
   graph[j][k]=rand();
  }
 }
 floyd(n);
fprintf(fp1,"%d\t%d\n",n,count);

}
fclose(fp1);
}

void main(){

 tester();
 plotter();
}


