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
      if (i!=j && graph[i][j]==1){
        k1++;
        n=j;
      }
    }
    if (k1==0){
      printf("Граф несвязный");
      flag=1;
      break;
    }
    else if (k1==1 && len>2){
      for (int j=0; j<len; j++){
        if (n!=j && graph[n][j]==1){
          k2++;
        }
      }
      if (k2==k1){
        printf("Граф несвязный");
        flag=1;
        break;
      }
    }
    k1=0;
    k2=0;
  }
  if (flag==0) printf("Граф связный");
}
