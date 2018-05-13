//
// Created by 张鹏霄 on 2018/4/28.
//

// str函数族的部分实现

#include <cstdio>
#include <cassert>

char* _strcpy(char* des, const char* src);
int _strlen(const char* str);
int _strcmp(const char *s1,const char *s2);
char* _strchr(char *s, char c);
char* _strstr(const char *str1, const char *str2);


//实现
char* _strcpy(char* des, const char* src)
{
    assert(des);
    assert(src);
    char *address = des;
    while((*des++ = *src++) != '\0')
        ;
    return address;
}

char* _strncpy(char* des, const char* src, size_t len)
{
    size_t count = 0;
    assert(des);
    assert(src);
    char *address = des;
    while((*des++ = *src++) != '\0' && count++ < len)
        ;

    if(*des != '\0')
        *des = '\0';

    return address;
}

int _strlen(const char* str)
{
    assert(str != NULL);
    int len = 0;
    while((*str++) != '\0')
        ++len;
    return len;
}

int _strcmp(const char *s1,const char *s2)
{
    assert((s1!=NULL) && (s2!=NULL));
    while(*s1 == *s2)
    {
        if(*s1 == '\0')
            return 0;

        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

char* _strchr(char *s, char c)
{
    while(*s != '\0' && *s != c)
    {
        ++s;
    }
    return *s==c ? s : NULL;
}

char* _strstr(const char *str1, const char *str2)
{
    char *cp = (char*)str1;
    char *s1, *s2;

    if (!*str2)
        return((char *)str1);

    while (*cp)
    {
        s1 = cp;
        s2 = (char *)str2;

        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;

        if (!*s2)
            return(cp);

        cp++;
    }
    return(NULL);
}

