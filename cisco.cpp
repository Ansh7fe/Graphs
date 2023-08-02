#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    vector<vector<int> > cost(26, vector<int>(26));
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        cin >> cost[j][k];
      }
    }
    int min_cost = INT_MAX;
    string min_string = "";
    for (int j = 0; j < 26; j++) {
      string temp = s;
      int curr_cost = 0;
      for (int k = 0; k < s.length(); k++) {
        if (temp[k] != j + 'a') {
          curr_cost += cost[temp[k] - 'a'][j];
          temp[k] = j + 'a';
        }
      }
      if (curr_cost < min_cost) {
        min_cost = curr_cost;
        min_string = temp;
      }
    }
    cout << min_cost << " " << min_string << endl;
  }
  return 0;
}
