int main() {
    int variable = 1;
    int c = 3;
    for(int i = 0; i < 10; i = i+1){
        variable = variable + 1;
        if(variable == 3){
            c = 6;
        }
    }
    return c;
}