#ifndef __COMMON_H__
#define __COMMON_H__

// Basics
#define SUCCESS 1

// PSA Architectures (eg. generations)
enum arch {
	VAN,
	AEE2004,
	AEE2010,
	UNDEFINED=0xff
};

#include "VAN.h" // VAN+CAN bus defines
#include "AEE2004.h" // AEE2004 defines
#include "AEE2010.h" // AEE2010 defines

#endif /* __COMMON_H__ */
