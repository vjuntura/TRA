#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.h"


int sanahaku(char *teksti) {
    // Empty linked list
    bst coll;
    coll.root=0;

    char * splitti;
    int i = 0;
    int len = 0;
    splitti = strtok(teksti," ,.-_:;!@#$&/""()=?`<>|§½{[]}+0123456789öäå*\n\t\r ");
    while(splitti != NULL) {
        len = strlen(splitti) + 1;
        for (i = 0; i < len; i++) {
            splitti[i] = tolower(splitti[i]);
        }
        //Tässä välissä tavaraa puuhun
        bst_insert(&coll, splitti);
        //printf("%s\n",splitti);
        splitti = strtok(NULL, " ,.-_:;!@#$&/""()=?`<>|§½{[]}+0123456789öäå*\n\t\r ");
      }
      printf("Original tree:\n");
      print_tree_inorder(coll);
      return 0;
}

int avaa_filu() {
    FILE *filukahva;
    long lSize;
    char *puskuri;
    //avataan filukahva
    filukahva = fopen ("small.txt" , "rb");
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


int main() {


    avaa_filu();
    return 0;
}
