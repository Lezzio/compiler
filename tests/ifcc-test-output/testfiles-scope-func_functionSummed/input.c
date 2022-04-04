int func(int a, int b){
    return a + b;
}

int func2(int a, int b){
    return a+b;
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    int e = func(a, b) + func2(c, d);
    return e;
}