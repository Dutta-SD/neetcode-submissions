class Solution {
private:
    int calculateScore(vector<int>& scores) {
        int counter = 0;
        int total = 0;

        for (auto i : scores) {
            total += (counter > 0 ? 2 : 1) * i;
            counter--;

            if (i == 10) {
                counter = 2;
            }
        }

        return total;
    }

public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int p1 = calculateScore(player1);
        int p2 = calculateScore(player2);

        if (p1 == p2)
            return 0;
        if (p1 > p2)
            return 1;

        return 2;
    }
};