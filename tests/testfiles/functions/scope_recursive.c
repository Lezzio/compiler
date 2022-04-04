int func(int a){
    return a + 1;
}


int main() {
    int b = 5;

    int a = func(func(func(b)));
    return a;
}