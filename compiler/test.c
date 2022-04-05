#include <stdio.h>
int print_int(int x)
{
if(x<0)
{
putchar('-');
x = -x;
return x;
}
}
int main() {
    return print_int(-273);
}