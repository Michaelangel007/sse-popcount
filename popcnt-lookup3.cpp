const std::uint8_t aBitCountNibbles[ 16 ] =
{
    0, // 0000 0
    1, // 0001 1
    1, // 0010 2
    2, // 0011 3
    1, // 0100 4 // 1 + f(0)
    2, // 0101 5 // 1 + f(1)
    2, // 0110 6 // 1 + f(2)
    3, // 0111 7 // 1 + f(3)
    1, // 1000 8 // 1 + f(0)
    2, // 1001 9 // 1 + f(1)
    2, // 1010 A // 1 + f(2)
    3, // 1011 B // 1 + f(3)
    2, // 1100 C // 1 + f(4)
    3, // 1101 D // 1 + f(5)
    3, // 1110 E // 1 + f(6)
    4  // 1111 F // 1 + f(7)
};

// 1.25s
inline uint8_t bitcount3( uint8_t x )
{
    uint8_t total = 0;
    for( int i = 0; i < 2; i++ )
    {
        total += aBitCountNibbles[ x & 0x7 ] + ((x >> 3) & 1);
        x >>= 4;
    }
    return total;   
}

std::uint64_t popcnt_lookup3_8bit(const uint8_t* data, const size_t n) {

    uint64_t result = 0;

    for (size_t i=0; i < n; i++) {
        result += bitcount3(data[i]);
    }

    return result;
}

