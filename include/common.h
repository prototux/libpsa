#ifndef __COMMON_H__
#define __COMMON_H__

// Basics
#define SUCCESS 1

// PSA Architectures (eg. generations)
#define ARCH_VAN        0x01
#define ARCH_AEE2004    0x02
#define ARCH_AEE2010    0x04

#include "VAN.h" // VAN+CAN bus defines
#include "AEE2004.h" // AEE2004 defines
#include "AEE2010.h" // AEE2010 defines

#endif /* __COMMON_H__ */
