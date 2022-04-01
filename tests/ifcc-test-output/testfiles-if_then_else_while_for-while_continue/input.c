int main() {
    int variable = 1;
    int var2 = 3;
    while(variable != 5){
        variable = variable + 1;
        if(variable == 4){
            continue;
        }
        var2 = variable;
    }
    return variable;
}