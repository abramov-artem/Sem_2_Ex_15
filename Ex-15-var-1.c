#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int n, len, odd;

  FILE *fread = fopen("input.txt", "r");
  fscanf(fread, "%d", &len);

  FILE *fwrite = fopen("output.txt", "w");
  for (int i=0; i<len; i++){
    fprintf(fwrite, "%c;\n", 'a'+i);
  }

  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      fscanf (fread, "%d", &odd);
      if (odd && j>=i){
        fprintf(fwrite, "%c -> %c;\n", 'a' + i, 'a' + j);
      }
    }
  }
  fclose(fwrite);
  fclose(fread);
}
