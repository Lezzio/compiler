int test(){
    return 10;
}

int main (){
    int a = 10;
    int b = 15;
    int c = a + b;
    int d = test() + c;
    return d;
}