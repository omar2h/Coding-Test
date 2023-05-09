#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long ull;

// recursive approach
ull f1(ull n){
    if(n == 0 || n == 1 || n == 2)
        return n;
    return f1(n-3) + f1(n-2);
}

// iterative approach
ull f2(ull n){
    if(n == 0 || n == 1 || n == 2)
        return n;
    ull a = 0, b = 1, c = 2;
    ull d = 0;
    for(ull i=3; i<=n; i++){
        d = b+a;
        a = b;
        b = c;
        c = d;
    }
    return d;
}

// dynamic programming memoization
ull f3(ull n){
    ull* dp = calloc(n+1, sizeof(ull));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(ull i=3; i<=n; i++){
        dp[i] = dp[i-3] + dp[i-2];
    }
    ull ans = dp[n];
    free(dp);
    return ans;
}

int main () {
    printf("%llu\n", f1(10));
    printf("%llu\n", f2(10));
    printf("%llu\n", f3(10));
    return 0;
}
