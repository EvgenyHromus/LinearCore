#ifndef INT24_HPP
#define INT24_HPP

struct UInt24 { unsigned long v:24; };
typedef struct UInt24 __attribute__((packed)) UInt24;
struct Int24 { signed long v:24; };
typedef struct Int24 __attribute__((packed)) Int24;

#endif