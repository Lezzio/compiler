int main() {
    int variable = 1;
    int var2 = 1;
    while(variable != 5){
        variable = variable + 1;
        while(var2 != 5){
            var2 = var2 + 1;
        }
        var2 = 1;
    }
    return variable;
}