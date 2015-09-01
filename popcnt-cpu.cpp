#ifdef __clang__
static uint64_t POPCNT64(uint64_t x) {
    __asm__ ("popcnt %1, %0" : "=r" (x) : "0" (x));
    return x;
}
#endif

std::uint64_t popcnt_cpu_64bit(const uint8_t* data, const size_t n) {

    uint64_t result = 0;

    for (size_t i=0; i < n; i += 8) {
        const uint64_t v = *reinterpret_cast<const uint64_t*>(data + i);

#if __GNUC__
    #ifdef __clang__
        result += POPCNT64(v);
    #else
        result += _popcnt64(v);
    #endif
#endif
#if _MSC_VER
        result += __popcnt64(v);
#endif
    }

    for (size_t i=8*(n/8); i < n; i++) {
        result += lookup8bit[data[i]];
    }

    return result;
}
