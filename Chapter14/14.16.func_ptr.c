/* func_ptr.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char *s_gets(char *st, int n);
char showMenu(void);
void eatLine(void); // 读取至行末尾
void show(void(*fp)(char *), char *str);
void toUpper(char *); // 把字符串转换为大写
void toLower(char *); // 把字符串转换为小写
void transpose(char *); // 大小写转置
void dummy(char *); // 不更改字符串

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);
    puts("Enter a string (empty line to quiet):");
    while(s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while((choice=showMenu()) != 'n')
        {
            switch (choice)
            {
            case 'u':
                pfun = toUpper;
                break;
            case 'l':
                pfun = toLower;
                break;
            case 't':
                pfun = transpose;
                break;
            case 'o':
                pfun = dummy;
                break;
            default:
                break;
            }
            strcpy(copy, line); // 为show()函数拷贝一份
            show(pfun, copy); // 根据用户的选择，使用选定的函数
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");
    return 0;
}

char showMenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u)uppercase\tl)lowercase");
    puts("t)transposed case\to)original case");
    puts("n)next string");
    ans = getchar(); // 获取用户输入
    ans = tolower(ans); // 转换为小写(调用系统自带处理函数)
    eatLine(); // 清理输入行
    while(strchr("ulton", ans) == NULL)
    {
        puts("Please enter a u,l,t,o or n:");
        ans = tolower(getchar());
        eatLine();
    }
    return ans;
}

void eatLine(void)
{
    while(getchar() != '\n')
        continue;
}

void toUpper(char * str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void toLower(char * str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void transpose(char * str)
{
    while (*str)
    {
        if(islower(*str))
            *str = toupper(*str);
        else if(isupper(*str))
            *str = tolower(*str);    
        str++;
    }
}

void dummy(char * str)
{
    // 不改变字符串
}

void show (void(*fp)(char *), char * str)
{
    (*fp)(str); //根据用户选定的函数对str处理
    puts(str); // 显示结果
}

char *s_gets(char *st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}