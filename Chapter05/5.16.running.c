/* running.c -- 一个对于长跑运算员有用的程序 */
#include <stdio.h>
const int S_PER_M = 60; // 每分钟的秒数
const int S_PER_H = 3600; //每小时的秒数
const double M_PER_K = 0.62137; // 每公里的英里数
int main(void)
{
    double distk, distm; // 跑过的距离（分别以公里和英里为单位）
    double rate; // 平均速度
    int min, sec; // 跑步用时（以分钟和秒为单位）
    int time; // 跑步用时（以秒为单位）
    double mtime; // 跑1英里所用的时间（以秒为单位）
    int mmin, msec; // 跑完1英里所用的时间（分别以分钟和秒为范围）

    printf("This a program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average\n");
    printf("speed in miles per hours.\n");
    printf("Please enter, in kilometers, the distance run.\n");
    scanf("%lf", &distk);
    printf("Next enter the time inminutes and seconds.\n");
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);
    printf("Now enter the seconds.\n");
    scanf("%d", &sec);

    time = S_PER_M * min + sec; // 把时间转换为秒
    distm = M_PER_K * distk; // 把公里转换成英里
    rate = distm / time * S_PER_H; // 英里/秒 * 秒/小时
    mtime = (double) time / distm; // 时间/距离 跑一英里所用的时间
    mmin = (int) mtime / S_PER_M; // 求出分钟数
    msec = (int) mtime % S_PER_M; // 求出剩余的秒数
    printf("Your ran %1.2f km(%1.2f miles) in %d min, %d sec.\n", 
        distk, distm, min, sec);
    printf("That pace correspinds to runningg a mile in %d min, ", mmin);
    printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);
    return 0;
}