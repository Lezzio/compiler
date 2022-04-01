int main() {
    int variable = 1;
    int var2 =0;
    while(variable != 5){
        variable = variable + 1;
        if(variable == 4){
            var2 = variable;
        }
    }
    return var2;
}