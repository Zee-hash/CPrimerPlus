/* films3.c -- 使用抽象数据类型风格的链表 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "17.3.list.h"
void showmovies(Item item);
char *s_gets(char *st, int n);
int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    // 获取用户输入并储存
    puts("Enter first movie title:");
    while(s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while(getchar() != '\n')
            continue;
        if(AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    if (ListIsEmpty(&movies))
    {
        printf("No data entered. ");
    }
    else
    {
        printf("Here is the movies list:\n");
        Traverse(&movies, showmovies);
    }
    printf("Your entered %d movies.\n", ListItemCount(&movies));
    // 清理
    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}

void showmovies(Item item)
{
    printf("Movie: %s | Rating: %d\n", item.title, item.rating);
}

char *s_gets(char * st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}