#include <iostream>
#include <string>
#include <math.h>
// mod(p) = X, x принадлежит [1,p), [x^1-1, x^2-1, ... x^(p-2)-1]%p != 0, (x^(p-1) - 1) % p = 0

//input: p [2<=p<2000]
#define MIN_INPUT_NUMBER 2
#define MAX_INPUT_NUMBER 2000
void show_help(std::string additional_help_info = "")
{
    if(additional_help_info != "") {
        std::cout<<"ERROR!\t"<<additional_help_info<<std::endl;
    }
    std::cout << "you must input an integer number [2, 2000)" <<std::endl;
}
bool is_simple(int value)
{
    for(int devisor = 2; devisor < value; devisor++) {
        if((value % devisor) == 0 ) {
            return false;
        }
    }
    return true;
}
bool is_devisible_on_input(int powered_value, int user_input)
{
    return ((powered_value - 1) % user_input) == 0;
}
int main(int argc, char** argv)
{
    //handle correct input
    std::string base_string;
    int inputted_number_p = 0;
    if (argc == 2) {
        base_string = argv[1];
        try {
            inputted_number_p = std::stoi(base_string);
        }
        catch(const std::exception& e) {
            show_help(e.what());
            return -1;
        }
        if ((inputted_number_p < MIN_INPUT_NUMBER) or (inputted_number_p > MAX_INPUT_NUMBER))
        {
            show_help(base_string + " is out of range");
            return -1;
        }
        if (not is_simple(inputted_number_p)) {
            show_help(base_string + " is not a simple number");
            return -1;
        }
        std::cout<<"you have inputted: "<<inputted_number_p<<std::endl;
    }
    else {
        show_help("incorrect arguments!");
        return -1;
    }

    //main logic
    int amount_of_primitive_roots = 0;
    for(int value_challenger = 1; value_challenger < inputted_number_p; value_challenger++) {
        int first_powered = pow(value_challenger, inputted_number_p - 1);
        if( not is_devisible_on_input(first_powered, inputted_number_p)) {
            continue;
        }
        bool is_valid = true;
        for(int power = 1; power <= inputted_number_p - 2; power++) {
            if(is_devisible_on_input(pow(value_challenger, power), inputted_number_p)) {
                is_valid = false;
                break;
            }
        }
        if (is_valid)
        {
            if(amount_of_primitive_roots == 0) {
                std::cout <<"primitive roots are: ";
            }
            std::cout <<"["<<value_challenger <<"] ";
            amount_of_primitive_roots++;
        }
    }
    std::cout<<"\nTotal amount of primitive roots is: "<<amount_of_primitive_roots<<std::endl;

    return 0;
}