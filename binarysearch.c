#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *create_bst(NODE *root)
{
    int i, n, num;
    NODE *newnode, *temp, *parent;
    printf("\nEnter How Many Nodes Do You Want??\n");
    scanf("%d", &n);
    printf("\nEnter Data In Node:\n");
    for (i = 0; i < n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        scanf("%d", &num);
        newnode->data = num;
        newnode->left = newnode->right = NULL;
        if (root == NULL)
        {
            root = newnode;
            continue;
        }
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (num < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (num < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
    return root;
}

void preorder(NODE *root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        printf("%d", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(NODE *root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d", temp->data);
        inorder(temp->right);
    }
}

void postorder(NODE *root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d", temp->data);
    }
}

NODE *search(NODE *root, int key)
{
    NODE *temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        else if (key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return NULL;
}

int count(NODE *root)
{
    static int cnt = 0;
    NODE *temp = root;
    if (temp != NULL)
    {
        cnt++;
        count(temp->left);
        count(temp->right);
    }
    return cnt;
}

int countLeaf(NODE *root)
{
    static int leaf = 0;
    NODE *temp = root;
    if (temp != NULL)
    {
        if ((temp->left == NULL) && (temp->right == NULL))
            leaf++;
        countLeaf(temp->left);
        countLeaf(temp->right);
    }
    return leaf;
}

void main()
{
    NODE *root = NULL;
    NODE *t;
    int ch,n,k,l ,ln;

    do
    {
        printf("\n1.Create \n2.Search\n3.Preorder\n4.Inorder\n5.Postorder\n6.Total Nodes\n7.Total Leaf Nodes\n8.Exit");
        printf("\nEnter Your Choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create_bst(root);
            break;

        case 2:
            printf("\nEnter A Node You Want To Search:\n");
            scanf("%d", &k);
            t = search(root, k);
            if (t == NULL)
            {
                printf("\nNot Found!!!!!\n");
            }
            else
            {
                printf("\nFound.\n");
            }
            break;

        case 3:
            preorder(root);
            break;

        case 4:
            inorder(root);
            break;

        case 5:
            postorder(root);
            break;

        case 6:
            n = count(root);
            printf("Total Nodes = %d\n", n);
            break;

        case 7:
            ln = countLeaf(root);
            printf("Total Leaf Nodes = %d\n", ln);
            break;

        case 8:
            exit(0);
        }
    } while (ch != 8);
}