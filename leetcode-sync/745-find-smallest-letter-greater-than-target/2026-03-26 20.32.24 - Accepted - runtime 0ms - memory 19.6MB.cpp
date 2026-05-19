class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        // Find the first element strictly greater than 'target'
        auto it = std::upper_bound(letters.begin(), letters.end(), target);
        
        // If it points to the end, it means no character is greater than target.
        // In that case, wrap around and return the first character.
        return (it == letters.end()) ? letters[0] : *it;
    }
};