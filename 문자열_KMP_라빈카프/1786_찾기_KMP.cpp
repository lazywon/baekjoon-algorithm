//다시 풀것!!!!!!!!!!!!!!! 이해 안감
//KMP 알고리즘

#include <bits/stdc++.h>
using namespace std;

int num;
string sentence, pattern;

vector<int> makeTable()
{
	int size = (int)pattern.size();
	vector<int> table(size, 0);

	int j = 0;
	for (int i = 1; i < size; i++)
	{
		while (j != 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}
	return table;
}
vector<int> kmp()
{
	vector<int>t = makeTable();
	int ssize = (int)sentence.size();
	int psize = (int)pattern.size();

  vector<int> ans;
	int j = 0;
	for (int i = 0; i < ssize; i++)
	{
		while (j != 0 && pattern[j] != sentence[i])
		{
			j = t[j - 1];
		}
		if (pattern[j] == sentence[i])
		{
			if (j == psize - 1)
			{

        ans.push_back(i+2-pattern.size()); //처음 나타난 위치
				j = t[j];
			}
			else
				j++;
		}
	}
	return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, sentence);
  getline(cin, pattern);

  vector<int> ans;
  ans = kmp();

  cout << ans.size() << "\n";
  for(int i=0;i<ans.size();i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}


/*
vector<int> failure(string& S){
  vector<int> f(S.size());
  int j = 0;
  for(int i = 1; i < S.size(); i++){
    while(j > 0 && S[i] != S[j]) j = f[j-1];
    if(S[i] == S[j]) f[i] = ++j;
  }
  return f;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string T,P;
  getline(cin, T);
  getline(cin, P);
  vector<int> f = failure(P);
  int j = 0;
  vector<int> occur;

  for(int i = 0; i < T.size(); i++){
    while(j > 0 and T[i] != P[j]) j = f[j-1];
    if(T[i] == P[j]) j++;
    if(j == P.size()){
      occur.push_back(i+2-P.size());
      j = f[j-1];
    }
  }
  cout << occur.size() << '\n';
  for(auto e : occur) cout << e << ' ';
}
*/


//라빈카프 코드
/*

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 10^9에 가까운 두 개의 수를 곱하는 작업이 반복되기 때문에 long long으로 선언하는 것이 편함. 굳이 int로 하고 싶으면 type casting을 계속 해줘야 함
ll a = 302;
ll p = 1000000007;
ll pow_a[1000001]; // pow_a[i] : a의 i승
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string T,P;
    pow_a[0] = 1;
    for(int i = 1; i < 1000001; i++) pow_a[i] = pow_a[i-1] * a % p;
    getline(cin, T);
    getline(cin, P);
    int lenT = T.size(), lenP = P.size();  
    if(lenT < lenP){
        cout << 0;
        return 0;
    }
    int hash_pattern = 0;
    for(int i = 0; i < lenP; i++)
        hash_pattern = (hash_pattern+P[i]*pow_a[lenP-1-i])%p;
    
    int hash_target = 0;
    for(int i = 0; i < lenP; i++)
        hash_target = (hash_target+T[i]*pow_a[lenP-1-i])%p;

    vector<int> ans;
    if(hash_target == hash_pattern) ans.push_back(1);
    for(int i = 1; i <= lenT-lenP; i++){
        hash_target = (hash_target-pow_a[lenP-1]*T[i-1])%p;
        if(hash_target < 0) hash_target += p; // 음수를 p로 나눈 나머지는 음수이기 때문에 이 처리가 반드시 필요함
        hash_target = hash_target * a % p;
        hash_target = (hash_target+T[i+lenP-1])%p;
        if(hash_target == hash_pattern) ans.push_back(i+1);
    }

    cout << ans.size() << '\n';
    for(auto e : ans) cout << e << ' ';
}

*/