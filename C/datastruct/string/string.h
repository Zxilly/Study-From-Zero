//
// Created by zxilly on 2020/12/9.
//

#ifndef C_STRING_H
#define C_STRING_H
#endif //C_STRING_H

#include <stdio.h>
#include <stdlib.h>

#define ElemType char;
#define TRUE 1
#define FALSE 0

typedef struct {
    char *ch;
    int length;
} __attribute__((aligned(16)))  string;

//初始化串
void initstring(string *s) {
    s->length = 0;
    s->ch = NULL;
}

//用字符串常量创建串
int createstring(string *s, const char *chars) {
    if (s->ch) free(s->ch);
    int i = 0;
    while (chars[i]) {
        i++;
    }
    if (i == 0) return FALSE;
    s->length = i;
    s->ch = (char *) malloc(sizeof(char) * s->length);
    if (s->ch == NULL) return FALSE;
    for (i = 0; i < s->length; i++) {
        s->ch[i] = chars[i];
    }
    s->ch[i++] = '\0';
    return TRUE;
}

//比较两个串是否相等若s1>s2返回值>0若s1<s2返回值<0若s1=s2返回0
int stringcompare(string s1, string s2) {
    int i = 0;
    while (s1.ch[i] && s2.ch[i]) {
        if (s1.ch[i] - s2.ch[i] > 0) return s1.ch[i] - s2.ch[i];
        i++;
    }
    return s1.length - s2.length;
}

//取得串长度,串中字符的个数称为串的长度
int stringlength(string s) {
    return s.length;
}

//清空字符串并释放串的所有空间
void stringclear(string *s) {
    if (s->ch) {
        free(s->ch);
        s->length = 0;
        s->ch = NULL;
    }
}

int stringconnection(string *s, string s1, string s2) {
    if (s->ch) free(s->ch);
    s->length = s1.length + s2.length;
    s->ch = (char *) malloc(sizeof(char) * (s->length + 1));
    if (s->ch == NULL) return FALSE;
    int i = 0;
    for (i = 0; i < s1.length; i++) {
        s->ch[i] = s1.ch[i];
    }
    for (; i < s->length; i++) {
        s->ch[i] = s2.ch[i - s1.length];
    }
    s->ch[i] = '\n';
    return TRUE;
}

//从串中截取一段串截取规则是从first开始,从end前一个结束
int stringsub(string *s, string hs, int first, int end) {
    if (s->ch != NULL) free(s->ch);
    if (first < 1 || end > hs.length + 1 || hs.length == 0) return FALSE;
    s->ch = (char *) malloc(sizeof(char) * (end - first + 1));
    if (s->ch == NULL) return FALSE;
    s->length = end - first;
    int i = 0;
    for (i = 0; i < s->length; i++) {
        s->ch[i] = hs.ch[first + i - 1];
    }
    s->ch[s->length] = '\n';
    return TRUE;
}

/*
 * 串匹配得到子串t在串s中pos个字符后的开始位置
 * 0< pos <= s->length
 * 若pos后存在字串返回其位置 否则返回0
 */

int stringindex(string s, string t, int pos) {
    if (pos < 0 || pos >= s.length) return 0;
    int i = pos, j = 0;
    while (i < s.length && j < t.length) {
        if (s.ch[i] == t.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
        if (j == t.length) return i - j + 1;
    }
    return 0;
}

//输出串
void printstring(string *s) {
    if (s->length == 0) {
        printf("空\n");
        return;
    }
    puts(s->ch);
    printf("length = %d\n", s->length);
}
