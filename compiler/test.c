int main() {
    int variable = 1;

    for(int i = 0; i < 10; i = i+1){
        variable = variable + 1;
        if(variable == 6){
            int c = 3;
            break;
        }
        int d = 5;
    }
    return variable;
}