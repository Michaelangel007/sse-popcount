// 0.8249s -> 0.8195s
inline uint8_t bitcount7( uint8_t x )
{
    uint8_t total = lookup8bit[ x & 0x7F ] + ((x >> 7) & 1);
    return total;   
}

std::uint64_t popcnt_lookup7_8bit(const uint8_t* data, const size_t n) {

    uint64_t result = 0;

    for (size_t i=0; i < n; i++) {
        result += bitcount7(data[i]);
    }

    return result;
}


