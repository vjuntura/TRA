#include <stdio.h>
#include <stdlib.h>
#include "bst.h"



int main() {
// Empty linked list
bst coll;
coll.root=0;

char * splitti;
splitti = "asd";

bst_insert(&coll, splitti);


printf("Original tree:\n");
print_tree_inorder(coll);
printf("\n Root was: ");
print_node(coll.root);



return 0;
}
