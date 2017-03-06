#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;

inline double add(double a, double b){
    return abs(a+b)<(1e-10)*(abs(a)+abs(b)) ? 0.0 : a+b;
}
 
struct vec{
    double x,y;
    vec operator-(vec b){
        return (vec){add(x,-b.x),add(y,-b.y)};
    }
    vec operator+(vec b){
        return (vec){add(x,b.x),add(y,b.y)};
    }
    vec operator*(double d){
        return (vec){x*d,y*d};
    }
    double dot(vec v){
        return add(x*v.x,y*v.y);
    }
    double cross(vec v){
        return add(x*v.y,-y*v.x);
    }
    double norm(){
        return sqrt(x*x+y*y);
    }
};
 
int ccw(vec& a, vec& b, vec& c){
    vec ab = b-a, ac = c-a;
    double o = ab.cross(ac);
    if(o>0) return 1; //CCW
    if(o<0) return -1; //CW
    if(ab.dot(ac)<0){
        return 2; //C-A-B
    }else{
        if(ab.dot(ab)<ac.dot(ac)){
            return -2; //A-B-C
        }else{
            return 0; //A-C-B
        }
    }
}
 
vector<vec> convex_hull(vector<vec>& V){
    vector<vec> C;
    vector<vec>::iterator ite;
    sort(V.begin(),V.end(),[](const vec& a, const vec& b){return a.y==b.y ? a.x < b.x : a.y< b.y;});
    C.push_back(V[0]),C.push_back(V[1]);
    for(auto i=V.begin()+2; i!=V.end(); ++i){
        C.push_back(*i);        
        while(ite=C.end()-1, C.size()>2&&ccw(*(ite-2),*(ite-1),*ite)== -1){
            C.erase(ite-1);
        }
    }
    sort(V.begin(),V.end(),[](const vec& a, const vec& b){return a.y==b.y ? a.x > b.x : a.y>b.y;});
    for(auto i=V.begin()+1; i!=V.end(); ++i){
        C.push_back(*i);
        while(ite=C.end()-1, C.size()>2&&ccw(*(ite-2),*(ite-1),*ite)== -1){
            C.erase(ite-1);
        }
    }
    C.pop_back();
    return C;
}

int main(void){
	vector<vec> v;
	rep(i, 5){
		vec tmp;
		cin >> tmp.x >> tmp.y;
		v.push_back(tmp);
	}
	rep(i, 5)reps(j, i + 1, 5)reps(k, j + 1, 5){
		int d = ccw(v[i], v[j], v[k]);
		if(d == 2 || d == -2 || d == 0){
			printf("NO\n");
			return 0;
		}
	}
	auto ret = convex_hull(v);
	// printf("%d\n", ret.size());
	if(ret.size() == 5){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}