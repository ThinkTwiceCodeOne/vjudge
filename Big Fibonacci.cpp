#include <iostream>
#include <string>


std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        result = std::to_string(sum) + result;
        i--;
        j--;
    }

    return result;
}
int findIndexOfDigits(int numDigits) {
    std::string prev = "1";
    std::string curr = "1";
    int index = 2;

    while (curr.length() < numDigits) {
        std::string temp = curr;
        curr = addStrings(curr, prev);
        prev = temp;
        index++;
    }

    return index;
}



int main() {
    int numDigits;
    std::cin>>numDigits;
    int index = findIndexOfDigits(numDigits);
    std::cout << index << std::endl;

    return 0;
}
