// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.
    // initialize a stack and a queue
    std::stack<char> stack;
    std::queue<char> queue;
    // loop through the string
    for (auto c : s) {
        // if the character is a letter
        if (isalpha(c)) {
            // push the character to the stack
            stack.push(c);
            // push the character to the queue
            queue.push(c);
        }
    }
    // loop while the stack is not empty
    while (!stack.empty()) {
        // if the top of the stack is not equal to the front of the queue
        if (stack.top() != queue.front()) {
            // return false
            return false;
        }
        // pop the top of the stack
        stack.pop();
        // pop the front of the queue
        queue.pop();
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << (is_palindrome(s)? "true": "false")  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}