int func(){
    return a + 1;
}


int main() {
    int a = 5;

    int b = func(func(func()));
    return b;
}