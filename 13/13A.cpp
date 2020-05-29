#include<bits/stdc++.h>
using namespace std;

vector<int> pattern;

vector<int> search(string pat, string txt)
{
	int M = pat.size();
	int N = txt.size();
	
	for(int i = 0; i <= N - M; i++)
	{
		int j;
		for(j = 0; j < M; j++) 
		{
			if(txt[i+j] != pat[j])
				break;
		}
		
		if(j == M)
			pattern.push_back(i+1);
	}
	return pattern;
}

int main()
{
	ifstream fin("search1.in");
	ofstream fout("search1.out");
	
	string p, t;
	fin >> p >> t;
	
	search(p, t);
	fout << pattern.size() << '\n';
	
	for(auto i: pattern)
	{
		fout << i << " ";
	}
}
