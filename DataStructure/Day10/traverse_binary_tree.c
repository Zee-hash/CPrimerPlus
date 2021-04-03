#include <stdio.h>

struct BinaryNode
{
    char ch; // 数据域
    struct BinaryNode *lChild;
    struct BinaryNode *rChild;
};

// 递归遍历
void recursion(struct BinaryNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // 先序遍历
    printf("%c ", root->ch);
    recursion(root->lChild);
    recursion(root->rChild);
}

void test01()
{   
    struct BinaryNode nodeA = {'A', NULL, NULL};
    struct BinaryNode nodeB = {'B', NULL, NULL};
    struct BinaryNode nodeC = {'C', NULL, NULL};
    struct BinaryNode nodeD = {'D', NULL, NULL};
    struct BinaryNode nodeE = {'E', NULL, NULL};
    struct BinaryNode nodeF = {'F', NULL, NULL};
    struct BinaryNode nodeG = {'G', NULL, NULL};
    struct BinaryNode nodeH = {'H', NULL, NULL};

    // 建立结点之间的关系
    nodeA.lChild = &nodeB;
    nodeB.rChild = &nodeC;
    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;
    nodeA.rChild = &nodeF;
    nodeF.rChild = &nodeG;
    nodeF.lChild = &nodeH;

    // 递归遍历
    recursion(&nodeA);

}

int main(void)
{
    test01();
    return 0;
}