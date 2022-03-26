#include <iostream>

using namespace std;

enum class LineStatus {
    CLEAR,
    PENDING,
    MULTILINE_COMMENT,
};

enum class CharStatus {
    CLEAR,
    ESCAPE,
    STRING,
    COMMENT_PENDING,
    LINE_COMMENT,
    MULTILINE_COMMENT,
    MULTILINE_COMMENT_PENDING,
};

int main() {
    string result;
    string line;
    auto lineStatus = LineStatus::CLEAR;
    while (getline(cin, line)) {
        auto charStatus = CharStatus::CLEAR;
        for (auto a: line) {
            switch (charStatus) {
                case CharStatus::CLEAR:
                    switch (a) {
                        case '"':
                            charStatus = CharStatus::STRING;
                            break;
                        case '/':
                            charStatus = CharStatus::COMMENT_PENDING;
                            break;
                        default:
                            result += a;
                            break;
                    }
                    break;
                case CharStatus::ESCAPE:
                    result += a;
                    charStatus = CharStatus::CLEAR;
                    break;
                case CharStatus::STRING:
                    switch (a) {
                        case '\\':
                            charStatus = CharStatus::ESCAPE;
                            break;
                        case '"':
                            charStatus = CharStatus::CLEAR;
                            break;
                        default:
                            result += a;
                            break;
                    }
                    break;
                case CharStatus::COMMENT_PENDING:
                    switch (a) {
                        case '/':
                            charStatus = CharStatus::LINE_COMMENT;
                            break;
                        case '*':
                            charStatus = CharStatus::MULTILINE_COMMENT_PENDING;
                            break;
                        default:
                            charStatus = CharStatus::CLEAR;
                            break;
                    }
                    break;
                case CharStatus::LINE_COMMENT:
                    if (a == '\n') {
                        charStatus = CharStatus::CLEAR;
                    }
                    break;
                case CharStatus::MULTILINE_COMMENT_PENDING:
                    switch (a) {
                        case '*':
                            charStatus = CharStatus::MULTILINE_COMMENT;
                            break;
                        default:
                            charStatus = CharStatus::MULTILINE_COMMENT;
                            break;
                    }
                    break;
                case CharStatus::MULTILINE_COMMENT:
                    switch (a) {
                        case '*':
                            charStatus = CharStatus::MULTILINE_COMMENT;
                            break;
                        case '/':
                            charStatus = CharStatus::CLEAR
            }
        }
    }
}