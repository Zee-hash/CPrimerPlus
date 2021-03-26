/* tree.c -- 树的支持函数 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "17.10.tree.h"

// 局部数据类型
typedef struct pair
{
    Trnode *parent;
    Trnode *child;
} Pair;

// 局部函数的原型
static Trnode * MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (* pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
// 注意这里由于要修改的是结点内部指针的指向，所以传递指向Trnode *类型的指针
static void DeleteNode(Trnode **ptr); 
static void DeleteAllNodes(Trnode *ptr);

// 函数定义
void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    if(ptree->root == NULL)
    {
        return true;
    }
    return false;
}

bool TreeIsFull(const Tree *ptree)
{
    if (ptree->size == MAXITEMS)
    {
        return true;
    }
    return false;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode * new_node;
    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full.\n");
        return false;
    }
    if (SeekItem(pi, ptree).child != NULL)
    {
        // 重复结点
        fprintf(stderr, "Attempted to add duplicate item.\n");
        return false;
    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node.\n");
        return false;
    }
    // 成功创建结点
    ptree->size++;
    if (ptree->root == NULL)
    {   
        // 树的第一个结点
        ptree->root = new_node;
    }
    else
    {
        // 在一棵树中添加新结点
        AddNode(new_node, ptree->root);
    }
    return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    // 获取删除结点需要的父节点和要删除结点的信息
    Pair look;
    look = SeekItem(pi, ptree);
    
    if (look.child == NULL)
    {
        // 未找到
        return false;
    }
    
    if (look.parent == NULL)
    {
        // 待删除的结点为根结点
        DeleteNode(&ptree->root);
    }
    else if (look.parent->left == look.child)
    {
        // 待删除的结点位于坐支
        DeleteNode(&look.parent->left);
    }
    else
    {
        // 待删除的结点位于右支
        DeleteNode(&look.parent->right);
    }
    ptree->size--;
    return true;
}

void Traverse(const Tree *ptree, void (* pfun)(Item item))
{
    if (ptree != NULL)
    {
        InOrder(ptree->root, pfun);
    }
}

void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
    {
        DeleteAllNodes(ptree->root);
    }
    ptree->root = NULL;
    ptree->size = 0;
}

// 局部函数
static void InOrder(const Trnode *root, void(* pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
    
}

static void DeleteAllNodes(Trnode *root)
{
    Trnode * pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(root->right);
    }
}

static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            AddNode(new_node, root->left);
        }
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            AddNode(new_node, root->right);
        }
    }
    else
    {
        // 有重复项
        fprintf(stderr, "location error in AddNode().\n");
        exit(EXIT_FAILURE);
    }
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
    {
        return true;
    }
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

static bool ToRight(const Item *i1, const Item *i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
    {
        return true;
    }
    else if (comp1 == 0 && strcmp(i1->petname, i2->petname) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

static Trnode *MakeNode(const Item *pi)
{
    Trnode * new_node;
    new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        // 新结点的初始化
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if (look.child == NULL)
    {
        return look;
    }
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            // 更新继续查找的结点信息
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
        {
            // 相等情况
            break;
        }
    }
    return look;
}

static void DeleteNode(Trnode **ptr)
{
    // ptr是指向目标结点的（待删除结点）父结点指针成员的地址
    Trnode * temp;
    if ((*ptr)->left == NULL)
    {
        // 无左子树
        temp = *ptr;
        // 直接修改指针信息指向右子树
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        // 无右子树
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        // 被删除的结点有两个子结点
        // 重新找到连接右子树的位置
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
        {
            // 左子树的最右结点
            continue;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}