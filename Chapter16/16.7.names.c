/* names.c -- 定义names_st函数 */
#include <stdio.h>
#include "16.6.names.h"

void get_names(names *pn)
{
    int i;

    printf("Please enter your first name: ");
    fgets(pn->first, SLEN, stdin);
    i = 0;
    while (pn->first[i] != '\n' && pn->first[i] != '\0')
    {
        i++;
    }
    if (pn->first[i] == '\n')
    {
        // 检测到换行，替换为字符串结束符
        pn->first[i] = '\0';
    }
    else
    {
        // 检测到字符串结尾
        while (getchar() != '\n')
        {
            // 清理剩余字符
            continue;
        }
    }
    printf("Please enter your last name: ");
    fgets(pn->last, SLEN, stdin);
    i = 0;
    while (pn->last[i] != '\n' && pn->last[i] != '\0')
    {
        i++;
    }
    if (pn->last[i] == '\n')
    {
        // 检测到换行，替换为字符串结束符
        pn->last[i] = '\0';
    }
    else
    {
        // 检测到字符串结尾
        while (getchar() != '\n')
        {
            // 清理剩余字符
            continue;
        }
    }
}

void show_names(const names *pn)
{
    printf("%s %s", pn->first, pn->last);
}