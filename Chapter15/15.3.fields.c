/* fields.c -- 定义和使用字段 */
#include <stdio.h>
// 是否透明和可见
#define YES 1
#define NO 0
// 边框线的样式
#define SOLID 0
#define DOTTED 1
#define DASHED 2
// 三原色
#define BLUE 4  // 4
#define GREEN 2 // 2
#define RED 1   // 1
// 混合颜色
#define BLACK 0                    // 0
#define YELLOW (RED | GREEN)       // 3
#define MAGENTA (RED | BLUE)       // 5
#define CYAN (GREEN | BLUE)        // 6
#define WHITE (RED | GREEN | BLUE) // 7

const char *colors[8] = {"black", "red", "green",
                         "yellow", "blue", "maganta", "cyan", "white"};
// 位字段
struct box_props
{
    unsigned int opaque : 1;
    unsigned int fill_color : 3;
    unsigned int : 4; // 间隙
    unsigned int show_border : 1;
    unsigned int border_color : 3;
    unsigned border_style : 2;
    unsigned int : 2;
};

void show_settings(const struct box_props *pb);

int main(void)
{
    // 创建和初始化box_props结构
    struct box_props box = {YES, YELLOW, YES, GREEN, DASHED};

    printf("Original box settings:\n");
    show_settings(&box);

    box.opaque = NO;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);

    return 0;
}

void show_settings(const struct box_props *pb)
{
    printf("Box is %s.\n",
           pb->opaque == YES ? "oqaque" : "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s\n",
           pb->show_border == YES ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style)
    {
    case SOLID:
        printf("solid.\n");
        break;
    case DOTTED:
        printf("dotted.\n");
        break;
    case DASHED:
        printf("dashed.\n");
        break;
    default:
        printf("unknown type.\n");
        break;
    }
}