/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* RGB Matrix Configuration */
#define DRIVER_1_LED_TOTAL 46
#define DRIVER_2_LED_TOTAL 40
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define CKLED2001_CURRENT_TUNE \
    { 0xA0, 0xA0, 0x4D, 0xA0, 0xA0, 0x4D, 0xA0, 0xA0, 0x4D, 0xA0, 0xA0, 0x4D }

/* Encoder Configuration */
#define ENCODERS_PAD_A { A10 }
#define ENCODERS_PAD_B { A8 }
#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 45