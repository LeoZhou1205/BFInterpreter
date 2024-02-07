#include <iostream>
#include <fstream>
#include <stack>

void run_bf(const std::string &code) {
    auto *a = new unsigned char[1000];
    std::stack<int> last_open_bracket_index;
    int code_index = 0;
    auto *pointer = a;
    while (code_index < code.length()) {
        auto current_code = code[code_index];
        switch (current_code) {
            case '+':
                (*pointer)++;
                break;
            case '-':
                (*pointer)--;
                break;
            case '>':
                pointer++;
                break;
            case '<':
                pointer--;
                break;
            case '.':
                std::cout << *pointer;
                break;
            case ',':
                std::cin >> *pointer;
                break;
            case '[':
                last_open_bracket_index.push(code_index);
                break;
            case ']':
                if (*pointer != 0) {
                    code_index = last_open_bracket_index.top();
                    break;
                }
                last_open_bracket_index.pop();
            default:
                break;
        }
        code_index++;
    }
}

int main() {
    std::cout << "Welcome to BFInterpreter 0.1 Alpha!" << std::endl;
    std::cout << "Please choose file input [0] or console input [1]" << std::endl;
    std::string input;
    std::cin >> input;
    while (input != "0" && input != "1") {
        std::cout << "Please try again" << std::endl;
        std::cin >> input;
    }
    bool console_input = std::stoi(input);
    std::string code;
    if (!console_input) {
        std::cout << "Please enter the file name" << std::endl;
        std::string file_name;
        std::ifstream file;
        std::cin >> file_name;
        file.open(file_name);
        while (file.fail()) {
            std::cout << "Please try again" << std::endl;
            std::cin >> file_name;
        }
        while (!file.eof()) {
            std::string temp;
            file >> temp;
            code += temp;
        }
        std::cout << code << std::endl;
    } else {
        std::cin >> code;
    }
    run_bf(code);
}


//