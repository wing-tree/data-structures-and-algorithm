// https://www.acmicpc.net/problem/2108

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	int N;
    map<int, int> map;
    vector<int> vector;

    int arithmetic_mean, median, mode, range;

    scanf("%d", &N);

    for (int i(0); i < N; ++i) {
        int key;

        scanf("%d", &key);

        ++map[key];
        vector.push_back(key);
    }
    
    sort(vector.begin(), vector.end());

    arithmetic_mean = round(accumulate(vector.begin(), vector.end(), 0.0) / N);
    median = vector[N / 2];

    int max = map.begin()->second;
    std::vector<int> keys;
    
    for (const auto& [key, value] : map) {
        if (value > max) {
            keys.clear();
            max = value;
        }

        if (value == max) {
            keys.push_back(key);
        }
    }
    
    if (keys.size() > 1) {
        mode = keys[1];
    } else {
        mode = keys[0];
    }

    range = vector.back() - vector.front();

    printf("%d\n%d\n%d\n%d", arithmetic_mean, median, mode, range);

	return 0;
}
