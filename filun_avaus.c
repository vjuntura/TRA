#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 50000000


int main() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "TheGun.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s\n", str);
    fclose(fp);
    return 0;
}
