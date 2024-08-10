int integerReplacement(size_t n) {
        int result = 0;

        for (; n > 1; ++result) {
            if ((bool)(n & 1) == false) n >>= 1;
            else if (n == 3 || (bool)((n >> 1) & 1) == false) --n;
            else ++n;
        } 

        return result;
}
