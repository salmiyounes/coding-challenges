uint32_t reverseBits(uint32_t x) {	
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result  |= (uint32_t)((x & ((uint32_t)1 << i)) > 0) << ((uint32_t)31 - i);
    }

    return result;
}
