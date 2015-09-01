// 0.8249s -> 0.8195s
inline uint8_t bitcount4( uint8_t x )
{
    uint8_t total = 
        aBitCountNibbles[ (x >> 0) & 0xF ]
    +   aBitCountNibbles[ (x >> 4) & 0xF ];
    return total;   
}

std::uint64_t popcnt_lookup4_8bit(const uint8_t* data, const size_t n) {

    uint64_t result = 0;

    for (size_t i=0; i < n; i++) {
        result += bitcount4(data[i]);
    }

    return result;
}

