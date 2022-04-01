int main() {
    int variable = 1;

    for(int i = 0; i < 10; i = i+1){
        variable = variable + 1;
        if(variable == 3){
            break;
        }
    }
    return variable;
}