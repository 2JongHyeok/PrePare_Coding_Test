#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score = 0;
    int prescore = 0;
    for (int i = 0; i < dartResult.length(); ++i) {
        if ('0' <= dartResult[i] && dartResult[i] <= '9') {
            answer += prescore;
            prescore = score;
            if (dartResult[i] == '1') {
                if (dartResult[i + 1] == '0') {
                    score = 10;
                    ++i;

                }
                else {
                    score = 1;
                }
                continue;
            }
            score = (dartResult[i] - '0');
            continue;
        }
        else if (dartResult[i] == 'S') {
            continue;
        }
        else if (dartResult[i] == 'D') {
            score = score * score;
            continue;
        }
        else if (dartResult[i] == 'T') {
            score = score * score * score;
            continue;
        }
        else if (dartResult[i] == '*') {
            prescore = prescore * 2;
            score = score * 2;
        }
        else if (dartResult[i] == '#') {
            score = -score;
        }
    }
    answer += prescore;
    answer += score;
    return answer;
}