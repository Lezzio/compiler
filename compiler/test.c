#include <inttypes.h>
int test2(int d){
    int j = 8;
    return j;
}

int test(int c){
    int y = 4;
    int j = 9;
    test2(5);
    return y;
}


int main() {
    int a = 0;
    int c = test(5);
    int d= test2(7);
    int y = test(5);
    int j = test(8);
    test(5);
    return y;
}