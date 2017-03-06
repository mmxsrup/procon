class TriangleMaking {
public:
    int maxPerimeter(int a, int b, int c) {
        int maxx = max(a, max(b, c));
        int minn = min(a, min(b, c));
        int midd = a + b + c - maxx - minn;
        int ans = 0;
        if(minn + midd <= max){
            ans = (minn + midd) * 2 - 1;
        }else{
            ans = minn + midd + maxx;
        }
        return ans;
    }
};

//srm697