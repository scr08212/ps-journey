#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

long long to_base10(const string& num_str, int base) {
    long long result = 0;
    long long power = 1;
    for (int i = num_str.length() - 1; i >= 0; i--) {
        result += (num_str[i] - '0') * power;
        power *= base;
    }
    return result;
}

string from_base10(long long num_10, int base) {
    if (num_10 == 0) return "0";
    string result = "";
    while (num_10 > 0) {
        result += to_string(num_10 % base);
        num_10 /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<string> split(string input, char delimiter = ' ') {
    vector<string> result;
    stringstream ss(input);
    string buf;
    while (getline(ss, buf, delimiter)) {
        result.push_back(buf);
    }
    return result;
}

string calculate(string expression_part, int ds) {
    vector<string> tokens = split(expression_part);
    string A = tokens[0];
    string op = tokens[1];
    string B = tokens[2];

    long long valA = to_base10(A, ds);
    long long valB = to_base10(B, ds);
    long long result_10;

    if (op == "+") {
        result_10 = valA + valB;
    } else { // op == "-"
        result_10 = valA - valB;
    }

    return from_base10(result_10, ds);
}

bool check_cal(string expression, int ds) {
    vector<string> tokens = split(expression, '=');
    string calculation_part = tokens[0];
    
    stringstream ss(tokens[1]);
    string expected;
    ss >> expected;

    string calculated = calculate(calculation_part, ds);
    return expected == calculated;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> known_expressions;
    vector<string> unknown_expressions;

    int max_digit = 0;
    for (const auto& exp : expressions) {
        if (exp.back() == 'X') {
            unknown_expressions.push_back(exp);
        } else {
            known_expressions.push_back(exp);
        }
        for(char c : exp) {
            if(isdigit(c)) {
                max_digit = max(max_digit, c - '0');
            }
        }
    }

    vector<int> possible_bases;
    for (int base = max_digit + 1; base <= 9; ++base) {
        bool is_valid = true;
        for (const auto& known_exp : known_expressions) {
            if (!check_cal(known_exp, base)) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            possible_bases.push_back(base);
        }
    }
    
    if (known_expressions.empty()) {
        possible_bases.clear();
        for (int base = max_digit + 1; base <= 9; ++base) {
            possible_bases.push_back(base);
        }
    }

    for (const auto& unknown_exp : unknown_expressions) {
        vector<string> tokens = split(unknown_exp, '=');
        string calculation_part = tokens[0];

        set<string> results;
        for (int base : possible_bases) {
            results.insert(calculate(calculation_part, base));
        }

        string final_result_str;
        if (results.size() == 1) {
            final_result_str = *results.begin();
        } else {
            final_result_str = "?";
        }
        
        calculation_part.pop_back(); 
        answer.push_back(calculation_part + " = " + final_result_str);
    }

    return answer;
}