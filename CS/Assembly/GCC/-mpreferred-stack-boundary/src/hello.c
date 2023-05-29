/*
 *
 * WARNING: Vulnerable to buffer overflow attack!
 *
 */

#include <stdio.h>
#include <string.h>

void fun(char *str){
    char buf[135];
    strcpy(buf, str);
    printf("Hello, %s\n", buf);
}

int main(int argc, char *argv[]){
    fun(argv[1]);
    return 0;
}
