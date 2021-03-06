/*
 * include/linux/platform_data/ina230.h
 *
 * Copyright (c) 2011, NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _INA230_H
#define _INA230_H

#include <linux/types.h>

struct ina230_platform_data {
	const char *rail_name;
	s32 current_threshold;
	s32 resistor;
	s32 min_cores_online;
};

#ifdef CONFIG_SENSORS_INA230
s32 ina230_get_bus_voltage_multi(s32 *voltage_mV, u32 num);
s32 ina230_get_batt_voltage_current(s32 *voltage_mV, s32 *current_mA);
s32 ina230_get_batt_volt(void);
s32 ina230_get_batt_curr(void);
#else
static s32 ina230_get_bus_voltage_multi(s32 *voltage_mV, u32 num) { return 0; }
static s32 ina230_get_batt_voltage_current(s32 *voltage_mV, s32 *current_mA) { return 0; }
static inline s32 ina230_get_batt_volt(void) { return 0; }
static inline s32 ina230_get_batt_curr(void) { return 0; }
#endif
#endif /* _INA230_H */
