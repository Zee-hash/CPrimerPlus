/* names_st.h -- 带有多次包含保护的修订版本 */
#ifndef NAMES_H_
#define NAMES_H_

#define SLEN 32

struct names_st
{
    char first[SLEN];
    char last[SLEN];
};

typedef struct names_st names;

void get_names(names *);
void show_names(const names *);

#endif