/* sort_str.c -- 读进一些字符串并对它们排序 */
#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 20
void stsrt(char *string[], int num);

int main(void)
{
    char input[LIM][SIZE];
    char *ptstr[LIM]; // 指针数组
    int ct = 0; // 输入计数
    int k; // 输出计数

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Space key at a line's start.\n");
    while (ct < LIM && gets(input[ct]) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }
    stsrt(ptstr, ct);
    puts("\nHere's the sorted list: \n");
    for (k = 0; k < ct; k++)
    {
        puts(ptstr[k]);
    }
    return 0;
}

void stsrt(char *string[], int num)
{
    char *temp;
    int top, seek;

    for (top = 0; top < num - 1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
        {
            if (strcmp(string[top], string[seek]) > 0)
            {
                temp = string[top];
                string[top] = string[seek];
                string[seek] = temp;
            }
            
        }
    }
}