#include <iostream>
#include <vector>
#include <string>

size_t get_number_of_sequence(const size_t& n) {
    size_t numerator = 1, denominator = 1;

    for (size_t i = n + 1; i <= 2 * n; ++i) {   //
        numerator *= i;                         //   1      ( 2*n )
    }                                           //------- * (     )
                                                // n + 1    (  n  )
    for (size_t i = 2; i <= n; ++i) {           //
        denominator *= i;
    }

    return numerator / denominator / (n+1);
}

std::vector<std::string> get_array_of_sequence(const size_t& n,
        const char& open_bracket, const char& close_bracket) {

    size_t number_of_sequence = get_number_of_sequence(n);

    std::string sequence = std::string(n, open_bracket) + std::string(n, close_bracket);

    std::vector<std::string> answer = {sequence};

    for (size_t i = 0; i < number_of_sequence; ++i) {
        for (int j = 2 * n - 1, balance = 0; j >= 0; --j) {
            if (sequence[j] == close_bracket) {
                ++balance;
            }
            else {
                --balance;
            }

            if (sequence[j] == open_bracket && balance > 0) {
                sequence[j] = close_bracket;

                size_t open = (2 * n - 1 - j - --balance) / 2;
                size_t close = 2 * n - 1 - j - open;

                sequence = sequence.substr(0, j + 1) + std::string(open, open_bracket) +
                        std::string(close, close_bracket);

                answer.push_back(sequence);
                break;
            }
        }
    }

    return answer;
}

int main() {
    size_t n;
    char open_bracket = '(', close_bracket = ')';

    std::cout << "Please, enter number of brackets, symbol of open bracket"
                 "and symbol of close bracket" << std::endl;

    std::cout << "n >> ";
    std::cin >> n;

    std::cout << "open_bracket >> ";
    std::cin >> open_bracket;

    std::cout << "close_bracket >> ";
    std::cin >> close_bracket;

    std::vector<std::string> sequences = get_array_of_sequence(n, open_bracket, close_bracket);

    std::cout << "All sequences are:" << std::endl;

    for (const auto& sequence : sequences) {
        std::cout << sequence << std::endl;
    }
}
