/* Väinö Juntura
TRA lopputyö */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "bst.h"

#define SANA_MAARA 50000


char * splitti;
long int uniikitSanat = 0;
pbstnode node;

//Kelloa varten
clock_t alku, loppu;
double yht;

//Paikka tiedoston nimelle
char tiedosto[30];

//protot
int sanahaku(char *teksti);
void sanalajittelu(char *sana);

// Vertailufunktio
int vertailu(const void *r, const void *h){
    int e = *((arraynode*) r)->maara2;
    int t = *((arraynode*) h)->maara2;
    return (t-e);
}

int avaa_filu() {




    FILE *filukahva;
    long lSize;
    char *puskuri;
    int error = 1;
    //avataan filukahva ja käsitellään mahdolliset typot yms.
    while(error){
      printf("Anna tiedoston nimi: \n");
      scanf("%s", tiedosto);
      filukahva = fopen (tiedosto , "rb");

      if(filukahva == 0){
        perror(tiedosto);
        error = 1;
      }
      else{
        error = 0;
      }
    }

    // Kello käyntiin
    alku = clock();

    fseek(filukahva , 0L , SEEK_END);
    lSize = ftell(filukahva);
    rewind(filukahva);


    puskuri = calloc(1, lSize + 1);
    if(puskuri == 0){
        fclose(filukahva);
        fputs("memory alloc fails",stderr);
        exit(1);
      }
    //kopioi koko tiedosto puskuriin
    if(fread(puskuri, lSize, 1, filukahva) != 1){
        fclose(filukahva);
        free(puskuri);
        fputs("entire read fails",stderr);
        exit(1);
      }

    fclose(filukahva);

    //Täällä ihmeet tapahtuvat
    sanahaku(puskuri);

    free(puskuri);
    return 0;
}

int sanahaku(char *teksti) {

    //Tyhjä bst
    bst coll;
    coll.root=0;

    FILE *filukahvaout;

    long int lkm = 1;
    //Array mihin sanat laitetaan
    arraynode *sanaArray = malloc(SANA_MAARA * sizeof(arraynode));

    int i = 0;
    int len = 0;

    //otetaan eka sana
    splitti = strtok(teksti," ,.-_:;!@#$%&/\"~^()=?`<>|§½{[]}+0123456789öäå*\n\t\r");

    //loopataan kunnes sanoja ei enää ole
    while(splitti != NULL) {
        len = strlen(splitti) + 1;
        for (i = 0; i < len; i++) {
            splitti[i] = tolower(splitti[i]);
        }
        node = bst_insert(&coll, splitti);

        //uuden sanan löytyessä laitetaan se arrayhyn
        if (node != 0) {
          sanaArray[uniikitSanat].sana = node->data;
          sanaArray[uniikitSanat].maara2 =  &(node->maara);

          uniikitSanat = uniikitSanat + 1;
        }


        lkm++;
        splitti = strtok(NULL, " ,.-_:;!@#$%&/\"~^()=?`<>|§½{[]}+0123456789öäå*\n\t\r");
      }

      //lajitellaan array esiintymislukumäärän mukaan
      qsort(sanaArray, uniikitSanat, sizeof(arraynode), vertailu);

      //Avataan tiedosto johon kirjoitetaan
      filukahvaout = fopen("satasanaa.txt", "w");

      //Siirretään tieto arraysta filuun
      fprintf(filukahvaout, "Uniikeja sanoja %ld \n\n", uniikitSanat);
      fprintf(filukahvaout, "Sanoja yhteensä %ld \n\n", lkm);
      fprintf(filukahvaout, "Sata yleisintä sanaa tiedostossa %s \n\n", tiedosto);
      fprintf(filukahvaout, "Sana              Esiintymiskerrat\n\n");
      for(int j = 0; j<100;j++){
          fprintf(filukahvaout, "%-17s %d\n", sanaArray[j].sana, *sanaArray[j].maara2);
      }

      printf("Kirjoitettu tiedostoon satasanaa.txt\n");

      //poistetaan bst
      bst_delete(coll.root);
      coll.root=0;

      //poistetaan array
      free(sanaArray);
      fclose(filukahvaout);

      return 0;
}



int main() {


    //Mennään itse ohjelman suoritukseen
    avaa_filu();
    //Kello pysäytetään
    loppu = clock();

    //LAsketaan kauon meni
    yht = ((double) (loppu - alku)) / CLOCKS_PER_SEC;

    //Tulostetaan käyttäjälle
    printf("Ohjelman suorittamiseen kului aikaa: %f seknutia\n", yht);

    return 0;
}
