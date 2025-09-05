#ifndef INT24_HPP
#define INT24_HPP

struct UInt24 {
    unsigned long v:24;

    int toUInt32() const {
        return static_cast<int>(v);
    }
};
typedef struct UInt24 __attribute__((packed)) UInt24;
struct Int24 {
    unsigned long v:24;

    int toInt32() const {
        return static_cast<unsigned int>(v);
    }
};
typedef struct Int24 __attribute__((packed)) Int24;

#endif