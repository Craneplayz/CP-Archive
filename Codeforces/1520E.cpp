#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Declarations
#define ll long long
#define veci vector<int>
#define str string

//Functions
#define pb push_back

//Printing
#define printveci for(int i:vec) cout<<i<<" "; cout<<endl;
#define printvecc for(char i:vec) cout<<i<<" "; cout<<endl;

void solve() {
    ll n, sum = 0, ca = 0;
	str a;
	cin >> n >> a;

	//Find and record centre loc
	vector <ll> loc;
	for (ll i = 0; i < n; i++)
		if (a[i] == '*')
			loc.pb(i);

	if (loc.empty()) cout << ca << endl;
	else {
		ca = loc.size();
		if (ca % 2) {
			ca -= (ca / 2);
			ca--;
			//loc[ca] is the centre;

			//left to centre;
			for (ll i = 0; i < ca; i++)
				sum += loc[ca] - loc[i] - (ca - i);

			//right to centre
			for (ll i = loc.size() - 1; i > ca; i--)
				sum += loc[i] - loc[ca] - (i - ca);
		}
		else {
			ca = ca / 2;
			ca--;
			//loc[ca]andloc[ca+1]is the centre

			//match loc[ca] and loc[ca+1]
			sum += loc[ca + 1] - loc[ca] - 1;
			loc[ca + 1] = loc[ca] + 1;

			//left to centre left;
			for (ll i = 0; i < ca; i++)
				sum += loc[ca] - loc[i] - (ca - i);

			//right to centre right
			for (ll i = loc.size() - 1; i > ca + 1; i--)
				sum += loc[i] - loc[ca+1] - (i - ca-1);
		}

		//Output
		cout << sum << endl;
	}
	loc.clear();
}

int main() {
	//Fast Input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//Driving Code
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}