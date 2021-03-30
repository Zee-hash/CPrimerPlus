/* dualview.c -- 位字段和位运算 */
#include <stdio.h>
// 是否透明和可见
#define YES 1
#define NO 0
// 边框线的样式
#define SOLID 0
#define DOTTED 1
#define DASHED 2
// 三原色
#define BLUE 4
#define GREEN 2
#define RED 1
// 混合颜色
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

// 位运算中使用的常量
#define OPAQUE 0x1         //                0001
#define FILL_BLUE 0x8      //                1000
#define FILL_GREEN 0x4     //                0100
#define FILL_RED 0x2       //                0010
#define FILL_MASK 0xE      //                1110
#define BORDER 0x100       //      0001 0000 0000
#define BORDER_BLUE 0x800  //      1000 0000 0000
#define BORDER_GREEN 0x400 //      0100 0000 0000
#define BORDER_RED 0x200   //      0010 0000 0000
#define BORDER_MASK 0xE00  //      1110 0000 0000
#define B_SOLID 0          // 0000 0000 0000 0000
#define B_DOTTED 0x1000    // 0001 0000 0000 0000
#define B_DASHED 0x2000    // 0010 0000 0000 0000
#define STYLE_MASK 0x3000  // 0011 0000 0000 0000

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

union Views
{
    struct box_props st_view;
    unsigned int ui_view;
};

void show_settings(const struct box_props *pb);
void show_settings1(unsigned short);
char *itobs(int n, char *ps);

int main(void)
{
    union Views box = {{YES, YELLOW, YES, GREEN, DASHED}};
    char bin_str[8 * sizeof(unsigned int)];

    printf("Original box settings: \n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view: \n");
    show_settings1(box.ui_view);

    printf("bits are %s\n", itobs(box.ui_view, bin_str));
    // 填充色位重置
    box.ui_view &= ~FILL_MASK;
    // 设置颜色
    box.ui_view |= (FILL_BLUE | FILL_GREEN);
    // 转置指示是否透明的位
    box.ui_view ^= OPAQUE;
    // 错误的置边框颜色的方法（未重置）
    box.ui_view |= BORDER_RED;
    // 边框样式位重置
    box.ui_view &= ~STYLE_MASK;
    // 设置边框样式
    box.ui_view |= B_DOTTED;
    printf("\nModified box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.ui_view);
    printf("bits are %s\n", itobs(box.ui_view, bin_str));
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

void show_settings1(unsigned short us)
{
    printf("box is %s.\n", us & OPAQUE == OPAQUE ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[(us >> 1) & 07]);
    printf("Border %s.\n", us & BORDER == YES ? "shown" : "not shown");
    printf("The border styles is ");
    switch ((us & STYLE_MASK) >> 12)
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
    printf("The border color is %s.\n", colors[(us >> 9) & 07]);
}

char *itobs(int n, char *ps)
{
    // int to binary string
    int i;
    static int size = 8 * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}