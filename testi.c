#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* result = "asdasdasdasda";

//Yhdistää tekstin palaset yhdeksi tekstiksi
char* yhdista(char *osa1, char *osa2)
{
    const size_t len1 = strlen(osa1);
    const size_t len2 = strlen(osa2);
    char *result = malloc(len1 + len2 + 1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here TSEKKAA!!!
    memcpy(result, osa1, len1);
    memcpy(result + len1, osa2, len2 + 1); //+1 to copy the null-terminator
    printf("%s\n", result);
    return result;
}



int main() {
  char* s = yhdista(result, "herp");
  //do things with s

  free(s);//deallocate the string
  return 0;
}
