#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED


// Defines data to store in tree
typedef char* data_type;

// Defines node and its pointer
typedef struct bstnd {
	char data[30];
	int maara;
	struct bstnd* parent;
	struct bstnd* left;
	struct bstnd* right;
} bstnode, *pbstnode;

//Määritellään array
typedef struct arrnd {
    data_type sana;
    int* maara2;
} arraynode;

// Defines the tree
typedef struct bt {
	pbstnode root;
} bst;

// Minimum and maximum values
pbstnode bst_min(pbstnode rt);
pbstnode bst_max(pbstnode rt);

// Searches key from the tree
pbstnode bst_search(bst bt, data_type key);

// Inserts key in the tree
pbstnode bst_insert(bst *bt, data_type key);

// Removes key from the tree
int bst_remove(bst *bt,data_type key);

// Prints node
void print_node(pbstnode n);

// Prints the tree
void print_tree_inorder(bst bt);

// Deletes a tree whose root is node
void bst_delete(pbstnode node);

#endif
