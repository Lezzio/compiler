int main() {
    int c = 3;
    for(int i = 0; i < 10; i = i+1){
        for(int j = 0; j < 10; j = j+1){
            c = i*j;
        }
    }
    return c;
}