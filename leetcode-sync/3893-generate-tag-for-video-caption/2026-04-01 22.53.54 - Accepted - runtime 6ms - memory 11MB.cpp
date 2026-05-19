class Solution {
private:
    std::string toCamelCase(std::string text) {
        std::stringstream ss(text);
        std::string word, result;
        bool isFirstWord = true;

        while (ss >> word) {
            std::transform(word.begin(), word.end(), word.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            if (isFirstWord) {
                result += word;
                isFirstWord = false;
            } else {
                word[0] = std::toupper(word[0]);
                result += word;
            }
        }
        return result;
    }

public:
    string generateTag(string caption) {
        string finalStr = "#" + toCamelCase(caption);
        return finalStr.substr(0, 100);
    }
};