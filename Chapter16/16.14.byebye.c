/* byebye.c -- atexit()示例程序 */
#include <stdio.h>
#include <stdlib.h>
void sign_off(void);
void too_bad(void);

/**
 * 由atexit()注册的函数的类型应该为不接受任何参数的void函数。
 * 通常它们执行内部处理任务，如更新程序监视文件或重置环境变量。
 * 【先调用后注册的函数，main()函数终止会隐式调用exit()】
**/
int main(void)
{
    int n;

    // 注册
    atexit(sign_off);
    puts("Enter an integer: ");
    if (scanf("%d", &n) != 1)
    {
        puts("That's no integer!");
        // 注册too_bad()函数
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n", n, (n % 2 == 0)? "even" : "odd");
    return 0;
}

void sign_off(void)
{
    puts("Thus terminates another magnificent program from");
    puts("SeeSaw Software!");
}

void too_bad(void)
{
    puts("SeeSaw Software extends its heartfelt condolences");
    puts("to your upon the failure of your program.");
}