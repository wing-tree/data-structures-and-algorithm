// https://www.acmicpc.net/problem/1316

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	int N(0);
  string word;
    
  cin >> N;

  int n(N);

  for (int i(0); i < N; ++i) {
    unordered_map<char, bool> unordered_map;

    cin >> word;
    word.push_back('A');

    char previous_alphabet = word[0];
    
    for (int i(1); i < word.size(); ++i) {
      if (unordered_map[previous_alphabet]) {
        --n;
        break;
      }
      
      if (previous_alphabet != word[i]) {
        unordered_map[previous_alphabet] = true;
      }
      
      previous_alphabet = word[i];
    }
  }

  cout << n;

	return 0;
}
