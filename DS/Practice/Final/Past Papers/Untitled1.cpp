#include <iostream>
#include <stack>

std::string removeDuplicates(const std::string& S) {
    // Step 1: Initialize an empty stack to store characters.
    std::stack<char> charStack;

    // Step 2: Iterate through each character in the input string.
    for (char ch : S) {
        // Step 3: Check if the stack is not empty and the current character is equal to the top of the stack.
        if (!charStack.empty() && ch == charStack.top()) {
            // If yes, pop the top element from the stack (remove duplicates).
            charStack.pop();
        } else {
            // If no, push the current character onto the stack.
            charStack.push(ch);
        }
    }

    // Step 4: Construct the result string using the characters remaining in the stack.
    std::string result = "";
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }

    return result;
}

int main() {
    // Example usage:
    std::string input = "abbaca";
    std::string result = removeDuplicates(input);

    std::cout << "Input: " << input << std::endl;
    std::cout << "Output: " << result << std::endl;

    return 0;
}

