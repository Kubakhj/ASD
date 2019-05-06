#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char MAX_NAME_SIZE = 30;

typedef struct node {
    struct node *left, *right, *parent;
    int number;
    char* name;
} node;

node* create_node(int number, char* name) { //returns pointer to newly created BST Node

    node* leaf = (node*) malloc(sizeof(node));
    leaf->left=NULL;
    leaf->right=NULL;
    leaf->parent=NULL;
    leaf->number=number;
    leaf->name=name;
    return leaf;
}

void delete_tree(node* root) { //deletes Bst tree using Post_Order algorithm
        if(root==NULL)
    {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

node* insert (node* root, node* to_insert) { //insertion of an element to a bst tree

    if(root==NULL)
    {
        return to_insert;
    }

    if(to_insert->number<root->number)
    {
            if(root->left==NULL)
            {
                to_insert->parent=root;
            }
        root->left=insert(root->left,to_insert);
    }
    else
    {
                if(root->right==NULL)
            {
                to_insert->parent=root;
            }
        root->right=insert(root->right,to_insert);
    }
}

node* find (node* root, int number) { //finds specific node in a bst tree

    if(root==NULL)
    {
        return NULL;
    }
    if(root->number==number)
    {
        return root;
    }
    if(number<root->number)
    {
        find(root->left,number);
    }
    else
    {
     find(root->right,number);
    }
}

node* delete(node* root, int number) //deletes a node from bst
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (number>root->number)
        root->right = delete(root->right, number);
    else if(number<root->number)
        root->left = delete(root->left, number);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            node *temp = root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            root->number = temp->number;
            root->name=temp->name;
            root->right = delete(root->right, temp->number);
        }
    }
    return root;
}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);

    node* root = NULL;
    int number;
    while (n-- > 0) {
    char* name = malloc(MAX_NAME_SIZE*sizeof(char));
        scanf("%d", &number);
        scanf("%s", name);
        root = insert(root, create_node(number, name));
    }

    while (r--> 0) {
        scanf("%d", &number);
        root = delete(root, number);
    }

    while (f-- > 0) {
        scanf("%d", &number);
        node* x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }
    delete_tree(root);
    }
