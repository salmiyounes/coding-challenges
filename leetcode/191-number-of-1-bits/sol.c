int hammingWeight(int n) {
    int res = 0;

    for (int i = 0; i < 32; i++) {
        res += (n & ((uint32_t)0x1 << i)) > 0;
    }

    return res;
}
