#include <stdio.h>


int main() {
  FILE* pFile;
  pFile = fopen("notexist.txt", "rb");
  if (pFile == NULL)
    perror("ERROR\n");
  else
    fclose(pFile);


    FILE* wonieFile;
   wonieFile = fopen("wonie2.txt", "rb");
  if (wonieFile == NULL)
    perror("error??!?!\n");
  else
  {
    fclose(wonieFile);
    // perror("OH\n");
  }
  return 0;
}