/*
 * Copyright (c) 2024 Hiroki Mori. All rights reserved.
 */

#define	PYMEMSTART	0x40000000
#define	PYMEMEND	0x40ffffff

#define FLASH_ADDR	0x1f000000
#if MZK
#define BOOT_SIZE	0x20014
#define UBOOTENVOFFSET	0x3f0000
#else
#define BOOT_SIZE	0x10000
#define UBOOTENVOFFSET	0xe000
#endif

#define	MMUTABLEBASE	0x40004000
