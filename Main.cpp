#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    std::map<std::string, std::string> responses = {
        {"hello", "Hi there!"},
        {"how are you", "I'm doing great, thanks for asking!"},
        {"what is your name", "I'm your friendly chatbot."},
        {"bye", "Goodbye! Have a nice day!"}
    };

    std::string input;
    std::cout << "Chatbot: Hello! Type something to chat (type 'exit' to quit).\n";

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, input);
        input = toLower(input);

        if (input == "exit") {
            std::cout << "Chatbot: See you later!\n";
            break;
        }

        if (responses.find(input) != responses.end()) {
            std::cout << "Chatbot: " << responses[input] << "\n";
        }
        else {
            std::cout << "Chatbot: I'm not sure how to respond to that.\n";
        }
    }

    return 0;
}
