#include <iostream>
#include <string>
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
        
        std::cout<<"hello: "<<inputted_number_p<<std::endl;

    }
    else {
        show_help();
    }
    return 0;
}