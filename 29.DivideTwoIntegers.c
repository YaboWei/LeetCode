int divide(int dividend, int divisor) {
    int sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;
    if (dividend < 0) dividend = -dividend;
    if (divisor  < 0) divisor  = -divisor;

    int max_mod = 0;
    while (dividend > divisor) {
        divisor <<= 1;
        max_mod++;
    }

    int res = 0;
    divisor >>= max_mod;
    max_mod--;

    while (max_mod >= 0) {
        printf("dividend: %d, divisor<<%d: %d\n", dividend, max_mod, divisor << max_mod);
        if (dividend >= (divisor << max_mod)) {
            dividend -= divisor << max_mod;
            res += 1<<max_mod;
        }
        max_mod--;
    }

    return sign*res;
}

int main()
{
    int dividend = 87, divisor = 4;
    int res = divide(dividend, divisor);
    printf("%d / %d = %d\n", dividend, divisor, res);
    return 0;
}
