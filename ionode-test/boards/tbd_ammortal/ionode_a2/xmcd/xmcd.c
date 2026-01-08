/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "xmcd.h"

#if defined(XIP_BOOT_HEADER_ENABLE) && (XIP_BOOT_HEADER_ENABLE == 1)

#if defined(XIP_BOOT_HEADER_XMCD_ENABLE) && (XIP_BOOT_HEADER_XMCD_ENABLE == 1)
__attribute__((section(".boot_hdr.xmcd_data"), used))

#if 1
const uint32_t xmcd_data[] = {
	/* Tag = 0xC, Version = 0, Memory Interface: SEMC,
	 * Instance: 0 - ignored,
	 * Configuration block type: 0 - Ignored(Handled inside
	 * the SDRAM configuration structure)
	 * Configuration block size: 13 (4-byte header + 9-byte
	 * option block)
	 */
	0xC010000D,
	/* Magic_number = 0xA1, Version = 1,
	 * Config_option: Simplified, SDRAM clock: 133MHz
	 */
	0x850001A1,
	/* SDRAM CS0 size: 64MBytes */
	0x00010000,
	/* Port_size: 16-bit */
	0x01};
#endif

// IS42S16320F-7TL
// 512Mbit (32MB x 16)
// 10bit addr
// 143MHz: CAS 3, RAS 6, 7ns
// 133MHz: CAS 2, RAS 7, 7.5ns

const uint32_t xmcd_data[] = {
	/* Tag = 0xC, Version = 0, Memory Interface: SEMC,
	 * Instance: 0 - ignored,
	 * Configuration block type: 0 - Ignored(Handled inside
	 * the SDRAM configuration structure)
	 * Configuration block size: 13 (4-byte header + 68-byte
	 * option block)
	 */
	0xC0100048,
	/* Magic_number = 0xA1, Version = 1, Config_option: Full, SDRAM clock: 133MHz */
	0x85FF01A1,
	/* SDRAM CS0 size: 64MBytes */
	0x00010000,
	/* Port_size: 16-bit, pull_config: pulldown, drive_strength: high, mux_rdy: invalid */
	0x00000201,
    /* mux_cs0/1/2/3: invalid */
    0x00000000,
    /* bank: 4, burst_len: 8, col_addr: 10bit, cas_latency: 2 */
    0x02020300,
    /*  wr_recov: 2ns, refr_recov: 70ns, act2rdwr: 15ns, pre2act: 15ns  */
    0x0f0f4602,
    /* act2act: 2ns, refr2refr: 60ns, selfrefr_recovery: 70ns, act2pre: 40ns */
    0x28463c02,
    /* act2pre max: 160 * (1000000000 / clockFrq) */
    0x000004bc,
    /* refresh: (64 * 1000000) / 8192 */
    0x00001e84,
    /* mode: prog burst len, standard op, cas 2, seq burst, burst len 8 (see datasheet) */
    0x00000023,
    /* CS0/1/2/3 base */
    0x80000000,
    0x00000000,
    0x00000000,
    0x00000000,
    /* CS1/2/3 size */
    0x00000000,
    0x00000000,
    0x00000000,
};


#endif /* XIP_BOOT_HEADER_XMCD_ENABLE */
#endif /* XIP_BOOT_HEADER_ENABLE */
