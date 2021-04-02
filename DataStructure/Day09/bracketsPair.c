#include "sq_stack.h"
#include <stdio.h>
#include <stdbool.h>


// 判断左括号
bool isLeft(char ch)
{
    return ch=='(';
}

// 判断右括号
bool isRight(char ch)
{
    return ch==')';
}

void printErrorInfo(char *str, char *errMsg, char *pos)
{
    printf("Error: %s\n", errMsg);
    printf("%s\n", str);
    int spaceNum = pos - str;
    for (int i = 0; i < spaceNum; i++)
    {
        putchar(' ');
    }
    printf("A\n");
}

int main(void)
{
    char *str = "5+5*(6)+3/3*1-(1+3(";
    char *p = str;

    int spaceCount = 0;
    Stack mystack = initStack();
    // 读取字符串
    while(*p != '\0')
    {
        // 左括号
        if (isLeft(*p))
        {
            // 入栈
            push(mystack, p);
        }
        // 右括号
        if (isRight(*p))
        {
            if (!stackIsEmpty(mystack))
            {
                // 栈不空，则存在匹配的，出栈
                pop(mystack);
            }
            else
            {
                // 栈为空，则当前右括号没有与之匹配的左括号
                printErrorInfo(str, "不存在匹配的左括号", p);
                break;
            }
        }
        p++;
    }
    // 全部读取完毕，若栈非空，则有未匹配完的左括号
    while (!stackIsEmpty(mystack))
    {
        printErrorInfo(str, "不存在匹配的右括号", top(mystack));
        pop(mystack);
    }

    // 销毁栈
    destroyStack(mystack);
    mystack = NULL;
}