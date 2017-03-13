#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int ururuday[100] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int notururuday[100] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string weekday[100] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", };
bool is_ururu(int y){
	if(y % 4) return false;
	else if(y % 100) return true;
	else if(y % 400) return false;
	else return true;
}

int limitday(int month, int year){
	if(is_ururu(year)){
		return ururuday[month - 1];
	}else{
		return notururuday[month - 1];
	}
}

string makedaymonthyear(int day, int month, int year){
	string ret = "";
	if(day <= 9) ret += "0" + to_string(day);
	else ret += to_string(day);
	ret += "/";
	if(month <= 9) ret += "0" + to_string(month);
	else ret += to_string(month);
	ret += "/";
	ret += to_string(year);
	return ret;
}

string moveday(int day, int month, int year, int n){
	rep(i, n){
		int limit = limitday(month, year);
		if(day + 1 <= limit){
			day += 1;
		}else{
			if(month != 12){
				day = 1;
				month++;
			}else{
				day = 1;
				month = 1;
				year++;
			}
		}
	}
	return makedaymonthyear(day, month, year);
}


std::vector<std::string> recurringTask(std::string firstDate, int k, std::vector<std::string> daysOfTheWeek, int n) {
	vector<string> ret;
	int day = stoi(firstDate.substr(0, 2));
	int month = stoi(firstDate.substr(3, 2));
	int year = stoi(firstDate.substr(6));
	// printf("%d %d %d\n", day, month, year);
	vint lis;
	for(auto u : daysOfTheWeek){
		rep(i, 7){
			if(weekday[i] == u)lis.pb(i);
		}
	}
	sort(all(lis));
	// printf("lisr\n");
	// for(auto u : lis) printf("%d\n", u);
	int c = lis[0]; lis[0] = 0;
	reps(i, 1, lis.size()){
		if(c != 0) lis[i] -= c;
		else lis[i]++;
		if(daysOfTheWeek[0] == "Sunday") lis[i]--;
	}
	vector<int> yotei;// yotei.pb(0);
	int now = 0;
	rep(i, n){
		if(i != 0 and i % lis.size() == 0) now += 7 * k;
		// printf("now %d\n", now);
		yotei.pb(now + lis[i % (int)lis.size()]);
	}
	// printf("yotei\n");
	// for(auto u : yotei)printf("%d\n", u);

	for(auto u : yotei){
		int nokori = u;
		// printf("nokori %d\n", nokori);
		auto r = moveday(day, month, year, nokori);
		// cout << r << endl;
		ret.pb(r);
	}
	return ret;
}


int main(void){
	// auto d = recurringTask("01/01/2015", 2,  {"Monday", "Thursday"}, 4);
	auto d = recurringTask("01/02/2100", 4,  {"Sunday", "Monday"}, 4);
	// auto d = recurringTask("23/02/2000", 2,  {"Wednesday", "Friday"}, 4);


	for(auto u : d){
		cout << u << endl;
	}
	return 0;
}

int toAndFroNaive(int a, int b, int t) {
	int len = abs(b - a);
	t %= (2 * len);
	if(t <= len){
		return a + (b - a) / abs(b - a) * t;
	}else{
		t -= len;
		return b - (b - a) / abs(a - b)
	}
}
