///Big Mod *iterative
#include <stdio.h>
#define ll long long int 
#define ull unsigned long long int
ll power(ll x, ull y) {
    ll res = 1;     // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;

        // n must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll power_mod(ll x, ull y, ll p) {
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)% p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x)% p;
    }
    return res;
}

// Driver program to test above functions
int main() {
    ll x = 100000000;
    ll y = 200;
    ll p = 13;
    printf("Power is %u", power(x, y));
    return 0;
}
