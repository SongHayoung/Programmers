using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a= b;
        b= r;
    }
    return a;
}

long long solution(int w,int h)
{
    long long answer;
    int g = gcd(h,w);
    return (long long)h * (long long)w - g*((w/g) + (h/g) -1);
}
