#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int again;
    for (string val : babbling) {
        again = -1;
        for (int i = 0; i < val.size();) {
            if (val.compare(i, 3, "aya") == 0 && again != 1) { i += 3, again = 1; }
            else if (val.compare(i, 2, "ye") == 0 && again != 2) { i += 2, again = 2; }
            else if (val.compare(i, 3, "woo") == 0 && again != 3) { i += 3, again = 3; }
            else if (val.compare(i, 2, "ma") == 0 && again != 4) { i += 2, again = 4; }
            else { again = 0; break; }
        }
        if (again != 0)
            ++answer;
    }


    return answer;
}