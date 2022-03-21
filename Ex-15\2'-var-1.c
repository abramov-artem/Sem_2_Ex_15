#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int n, len, odd, k1=0, k2=0, flag=0;
  int **graph[10][10];

  FILE *fread = fopen("input.txt", "r");
  fscanf(fread, "%d", &len);

  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      fscanf (fread, "%d", &odd);
      if(odd) graph[i][j]=1;
      else graph[i][j]=0;
    }
  }
  fclose(fread);

  for (int i=0; i<len; i++){
    for (int j=0; j<len; j++){
      if (i>j && graph[i][j]==1){
        k1++;
      }
      if (i==j && graph[i][j]==1){
        printf("Это псевдограф");
        flag=1;
        break;
      }
    }
    if (flag==1) break;
  }
  if (flag!=1){
    if (k1>(len-1)*(len-2)/2) printf("Граф связный");
    else printf("Граф несвзяный");
  }
}
