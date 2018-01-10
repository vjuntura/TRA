#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="ffff'g fff";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-_:;!@#$&/""()=?`{[]}+0123456789öäå*");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-_:;!@#$&/""()=?`{[]}+0123456789öäå*");
  }
  return 0;
}
