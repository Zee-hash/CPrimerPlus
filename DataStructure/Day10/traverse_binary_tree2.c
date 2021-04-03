#include <stdio.h>
#include "sq_stack.h"

// gcc traverse_binary_tree2.c sq_stack.c

struct BinaryNode
{
    char ch; // 数据域
    struct BinaryNode *lChild;
    struct BinaryNode *rChild;
    // 用于非递归的标识
    bool flag;
};

// 非递归遍历
void traverse(struct BinaryNode *root)
{
    Stack mystack;
    mystack = initStack();
    if (root == NULL)
    {
        return;
    }
    // 根结点入栈
    push(mystack, root);
    // 开始循环
    while (size(mystack))
    {
        // 栈不空
        // 获取栈顶元素
        struct BinaryNode * topNode = top(mystack);
        // 弹出栈顶元素
        pop(mystack);
        // 判断标记
        if (topNode->flag)
        {
            // 标记为真，输出并开始下一次循环
            printf("%c ", topNode->ch);
            continue;
        }
        else
        {
            // 标记为假，则将标记置为真
            topNode->flag = true;
            // 将右结点、左结点、根结点入栈
            if (topNode->rChild != NULL)
            {
                push(mystack, topNode->rChild);
            }
            if (topNode->lChild != NULL)
            {
                push(mystack, topNode->lChild);
            }
            push(mystack, topNode);
        }
    }
    putchar('\n');
}

void test01()
{   
    struct BinaryNode nodeA = {'A', NULL, NULL, false};
    struct BinaryNode nodeB = {'B', NULL, NULL, false};
    struct BinaryNode nodeC = {'C', NULL, NULL, false};
    struct BinaryNode nodeD = {'D', NULL, NULL, false};
    struct BinaryNode nodeE = {'E', NULL, NULL, false};
    struct BinaryNode nodeF = {'F', NULL, NULL, false};
    struct BinaryNode nodeG = {'G', NULL, NULL, false};
    struct BinaryNode nodeH = {'H', NULL, NULL, false};

    // 建立结点之间的关系
    nodeA.lChild = &nodeB;
    nodeB.rChild = &nodeC;
    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;
    nodeA.rChild = &nodeF;
    nodeF.rChild = &nodeG;
    nodeF.lChild = &nodeH;

    // 非递归遍历
    traverse(&nodeA);

}

int main(void)
{
    test01();
    return 0;
}