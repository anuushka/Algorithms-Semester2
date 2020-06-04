#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void compute_automaton(string s, int limit, vector<vector<int> > &aut) 
{
    s += "#";
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(limit));
    for (int i = 0; i < n; i++) 
	{
        for (int c = 0; c < limit; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}

int main() 
{
    int limit;
    string s;
   	cin >> limit;
    cin >> s;
	vector<int> prefix = prefix_function(s);
    vector<vector<int> > KMP(s.length(), vector<int>(limit));  
    compute_automaton(s, limit, KMP);
	for (auto& row : KMP) 
	{
        for (auto& i : row) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
