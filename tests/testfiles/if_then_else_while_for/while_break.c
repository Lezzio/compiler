int main() {
    int variable = 1;
    while(variable != 5){
        variable = variable + 1;
        if(variable == 4){
            break;
        }
    }
    return variable;
}