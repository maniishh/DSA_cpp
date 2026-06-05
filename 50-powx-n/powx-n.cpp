class Solution {
public:
double f(double x, int n){
    if(n==0){
        return 1;
    }
    double h=f(x,n/2);
    if(n%2==0)
        return h*h;
   return x*h*h;
    
}
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        return f(x,N);
    }
};