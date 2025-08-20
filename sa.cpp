#include <bits/stdc++.h>
using namespace std;

struct Timer {
    chrono::system_clock::time_point start; int count, interval = 100;
    void Init() { start = chrono::system_clock::now(); count = 0; }
    Timer() { Init(); }
    double CalcDuration() { return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count(); }
    bool IsContinue(double limit) { return (++count % interval != 0 || CalcDuration() < limit); }
};

struct Situation{};

int Score(Situation &situation) {
    return 0;
}

void Init_Solution(Situation &situation) {
    /* 初期解を求める */
}

void Make_Change(Situation &situation) {
    /* 近傍を変更する */
}

random_device seed_gen;
mt19937_64 engine(seed_gen());

int SA() {

    double temp = 1;
    double cooling_rate = 0.99;

    Situation prev_situation;
    Init_Solution(prev_situation);  // 初期解

    int prev_score = Score(prev_situation);
    int best_score = prev_score;
    Situation best_situation = prev_situation;

    uniform_real_distribution<double> transition_dist(0, 1);
    Timer timer;
    while (timer.IsContinue(1920)) {

        temp *= cooling_rate;

        Situation curr_situation = prev_situation;
        Make_Change(curr_situation);  // 近傍探索

        int curr_score = Score(curr_situation);

        if (curr_score > prev_score || transition_dist(engine) < exp((curr_score - prev_score) / temp)) {

            prev_situation = curr_situation;
            prev_score = curr_score;

            if (curr_score > best_score) {

                best_score = curr_score;
                best_situation = curr_situation;
            }
        }
    }
}


