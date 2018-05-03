#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "bst.h"





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

int sanahaku(char *teksti) {
    // Empty linked list
    bst coll;
    coll.root=0;

  //  int maara = 0;
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
        bst_insert(&coll, splitti, maara);
        //printf("%s\n",splitti);
    //    maara = maara + 1;
        splitti = strtok(NULL, " ,.-_:;!@#$&/""()=?`<>|§½{[]}+0123456789öäå*\n\t\r ");
      }

      //Tässä sitten puu filuun.
      printf("Tree:\n");
      print_tree_inorder(coll);
      return 0;
}



int sanan_maara(char* sana){
  int maara = 0;

/*
TÄHÄN TULEE JOTAIN TÄLLAISTA
if (bst_search(coll, num) == 0) {
  printf("not found\n");
}
else {
  print_node(bst_search(coll, num));
}

MUOKKAA HAKUFUNKKARIA SILLEE ETTÄ PALAUTTAA MYÖS SINNE TALLENNETUN INTIN!!

*/
  return maara;
}


int main() {


    avaa_filu();
    return 0;
}
