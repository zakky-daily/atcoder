#include <bits/stdc++.h>
using namespace std;

struct Timer {
    chrono::system_clock::time_point start; int count, interval = 100;
    void Init() { start = chrono::system_clock::now(); count = 0; }
    double CalcDuration() { return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count(); }
    bool IsContinue(double limit) { return (++count % interval == 0 || CalcDuration() < limit); }
};
