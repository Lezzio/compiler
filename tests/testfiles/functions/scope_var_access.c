int func(int a){
    int g = 5;
    return a + g;
}


int main() {
    int a = 1;
    int b = 2;

    int e = func(a) + b;
    return e;
}