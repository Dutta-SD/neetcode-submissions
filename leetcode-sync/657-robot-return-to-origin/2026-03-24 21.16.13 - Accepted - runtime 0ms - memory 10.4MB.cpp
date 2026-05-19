class Solution {
public:
    bool judgeCircle(string moves) {
        int xCount = 0;
        int yCount = 0;

        for (auto c : moves){
            switch(c) {
                case 'U': yCount++; break;
                case 'D': yCount--; break;
                case 'L': xCount++; break;
                case 'R': xCount--; break;
            }
        }

        return xCount == 0 && yCount == 0;
        
    }
};