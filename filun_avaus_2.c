#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int avaa_filu() {
    FILE *filukahva;
    long lSize;
    char *puskuri;
    //avataan filukahva
    filukahva = fopen ( "TheGun.txt" , "rb" );
    if(filukahva == 0){
        perror("TheGun.txt");
        exit(1);
      }
    fseek(filukahva , 0L , SEEK_END);
    lSize = ftell(filukahva);
    rewind(filukahva);

    /* allocate memory for entire content */
    puskuri = calloc(1, lSize + 1);
    if(puskuri == 0){
        fclose(filukahva);
        fputs("memory alloc fails",stderr);
        exit(1);
      }
    //kopioi tiedosto puskuriin
    if(fread(puskuri, lSize, 1, filukahva) != 1){
        fclose(filukahva);
        free(puskuri);
        fputs("entire read fails",stderr);
        exit(1);
      }

    fclose(filukahva);

    /* do your work here, puskuri is a string contains the whole text */
    sanahaku(puskuri);

    free(puskuri);
    return 0;
}

int sanahaku  (char *teksti) {
    char * splitti;
    splitti = strtok (teksti," ,.-_:;!@#$&/""()=?`{[]}+0123456789öäå*");
    while (splitti != NULL) {
        printf ("%s\n",splitti);
        splitti = strtok (NULL, " ,.-_:;!@#$&/""()=?`{[]}+0123456789öäå*");
      }
      return 0;
}


int main() {
    avaa_filu();
    return 0;
}
