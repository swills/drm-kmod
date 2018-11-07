/* Copyright 2012-15 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DC_MEM_INPUT_DCN10_H__
#define __DC_MEM_INPUT_DCN10_H__

#include "hubp.h"

#define TO_DCN10_HUBP(hubp)\
	container_of(hubp, struct dcn10_hubp, base)

/* Register address initialization macro for all ASICs (including those with reduced functionality) */
#define HUBP_REG_LIST_DCN(id)\
	SRI(DCHUBP_CNTL, HUBP, id),\
	SRI(HUBPREQ_DEBUG_DB, HUBP, id),\
	SRI(DCSURF_ADDR_CONFIG, HUBP, id),\
	SRI(DCSURF_TILING_CONFIG, HUBP, id),\
	SRI(DCSURF_SURFACE_PITCH, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_PITCH_C, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_CONFIG, HUBP, id),\
	SRI(DCSURF_FLIP_CONTROL, HUBPREQ, id),\
	SRI(DCSURF_PRI_VIEWPORT_DIMENSION, HUBP, id), \
	SRI(DCSURF_PRI_VIEWPORT_START, HUBP, id), \
	SRI(DCSURF_SEC_VIEWPORT_DIMENSION, HUBP, id), \
	SRI(DCSURF_SEC_VIEWPORT_START, HUBP, id), \
	SRI(DCSURF_PRI_VIEWPORT_DIMENSION_C, HUBP, id), \
	SRI(DCSURF_PRI_VIEWPORT_START_C, HUBP, id), \
	SRI(DCSURF_PRIMARY_SURFACE_ADDRESS_HIGH, HUBPREQ, id),\
	SRI(DCSURF_PRIMARY_SURFACE_ADDRESS, HUBPREQ, id),\
	SRI(DCSURF_SECONDARY_SURFACE_ADDRESS_HIGH, HUBPREQ, id),\
	SRI(DCSURF_SECONDARY_SURFACE_ADDRESS, HUBPREQ, id),\
	SRI(DCSURF_PRIMARY_META_SURFACE_ADDRESS_HIGH, HUBPREQ, id),\
	SRI(DCSURF_PRIMARY_META_SURFACE_ADDRESS, HUBPREQ, id),\
	SRI(DCSURF_SECONDARY_META_SURFACE_ADDRESS_HIGH, HUBPREQ, id),\
	SRI(DCSURF_SECONDARY_META_SURFACE_ADDRESS, HUBPREQ, id),\
	SRI(DCSURF_PRIMARY_SURFACE_ADDRESS_HIGH_C, HUBPREQ, id),\
	SRI(DCSURF_PRIMARY_SURFACE_ADDRESS_C, HUBPREQ, id),\
	SRI(DCSURF_PRIMARY_META_SURFACE_ADDRESS_HIGH_C, HUBPREQ, id),\
	SRI(DCSURF_PRIMARY_META_SURFACE_ADDRESS_C, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_INUSE, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_INUSE_HIGH, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_INUSE_C, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_INUSE_HIGH_C, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_EARLIEST_INUSE, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_EARLIEST_INUSE_HIGH, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_EARLIEST_INUSE_C, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_EARLIEST_INUSE_HIGH_C, HUBPREQ, id),\
	SRI(DCSURF_SURFACE_CONTROL, HUBPREQ, id),\
	SRI(HUBPRET_CONTROL, HUBPRET, id),\
	SRI(DCN_EXPANSION_MODE, HUBPREQ, id),\
	SRI(DCHUBP_REQ_SIZE_CONFIG, HUBP, id),\
	SRI(DCHUBP_REQ_SIZE_CONFIG_C, HUBP, id),\
	SRI(BLANK_OFFSET_0, HUBPREQ, id),\
	SRI(BLANK_OFFSET_1, HUBPREQ, id),\
	SRI(DST_DIMENSIONS, HUBPREQ, id),\
	SRI(DST_AFTER_SCALER, HUBPREQ, id),\
	SRI(VBLANK_PARAMETERS_0, HUBPREQ, id),\
	SRI(REF_FREQ_TO_PIX_FREQ, HUBPREQ, id),\
	SRI(VBLANK_PARAMETERS_1, HUBPREQ, id),\
	SRI(VBLANK_PARAMETERS_3, HUBPREQ, id),\
	SRI(NOM_PARAMETERS_4, HUBPREQ, id),\
	SRI(NOM_PARAMETERS_5, HUBPREQ, id),\
	SRI(PER_LINE_DELIVERY_PRE, HUBPREQ, id),\
	SRI(PER_LINE_DELIVERY, HUBPREQ, id),\
	SRI(VBLANK_PARAMETERS_2, HUBPREQ, id),\
	SRI(VBLANK_PARAMETERS_4, HUBPREQ, id),\
	SRI(NOM_PARAMETERS_6, HUBPREQ, id),\
	SRI(NOM_PARAMETERS_7, HUBPREQ, id),\
	SRI(DCN_TTU_QOS_WM, HUBPREQ, id),\
	SRI(DCN_GLOBAL_TTU_CNTL, HUBPREQ, id),\
	SRI(DCN_SURF0_TTU_CNTL0, HUBPREQ, id),\
	SRI(DCN_SURF0_TTU_CNTL1, HUBPREQ, id),\
	SRI(DCN_SURF1_TTU_CNTL0, HUBPREQ, id),\
	SRI(DCN_SURF1_TTU_CNTL1, HUBPREQ, id),\
	SRI(DCN_CUR0_TTU_CNTL0, HUBPREQ, id),\
	SRI(DCN_CUR0_TTU_CNTL1, HUBPREQ, id),\
	SRI(HUBP_CLK_CNTL, HUBP, id)

/* Register address initialization macro for ASICs with VM */
#define HUBP_REG_LIST_DCN_VM(id)\
	SRI(NOM_PARAMETERS_0, HUBPREQ, id),\
	SRI(NOM_PARAMETERS_1, HUBPREQ, id),\
	SRI(NOM_PARAMETERS_2, HUBPREQ, id),\
	SRI(NOM_PARAMETERS_3, HUBPREQ, id),\
	SRI(DCN_VM_MX_L1_TLB_CNTL, HUBPREQ, id)

#define HUBP_REG_LIST_DCN10(id)\
	HUBP_REG_LIST_DCN(id),\
	HUBP_REG_LIST_DCN_VM(id),\
	SRI(PREFETCH_SETTINS, HUBPREQ, id),\
	SRI(PREFETCH_SETTINS_C, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_MSB, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LSB, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PAGE_TABLE_START_ADDR_MSB, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PAGE_TABLE_START_ADDR_LSB, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PAGE_TABLE_END_ADDR_MSB, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PAGE_TABLE_END_ADDR_LSB, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_MSB, HUBPREQ, id),\
	SRI(DCN_VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_LSB, HUBPREQ, id),\
	SRI(DCN_VM_SYSTEM_APERTURE_DEFAULT_ADDR_MSB, HUBPREQ, id),\
	SRI(DCN_VM_SYSTEM_APERTURE_DEFAULT_ADDR_LSB, HUBPREQ, id),\
	SRI(DCN_VM_SYSTEM_APERTURE_LOW_ADDR_MSB, HUBPREQ, id),\
	SRI(DCN_VM_SYSTEM_APERTURE_LOW_ADDR_LSB, HUBPREQ, id),\
	SRI(DCN_VM_SYSTEM_APERTURE_HIGH_ADDR_MSB, HUBPREQ, id),\
	SRI(DCN_VM_SYSTEM_APERTURE_HIGH_ADDR_LSB, HUBPREQ, id),\
	SR(DCHUBBUB_SDPIF_FB_BASE),\
	SR(DCHUBBUB_SDPIF_FB_OFFSET),\
	SRI(CURSOR_SETTINS, HUBPREQ, id), \
	SRI(CURSOR_SURFACE_ADDRESS_HIGH, CURSOR, id), \
	SRI(CURSOR_SURFACE_ADDRESS, CURSOR, id), \
	SRI(CURSOR_SIZE, CURSOR, id), \
	SRI(CURSOR_CONTROL, CURSOR, id), \
	SRI(CURSOR_POSITION, CURSOR, id), \
	SRI(CURSOR_HOT_SPOT, CURSOR, id), \
	SRI(CURSOR_DST_OFFSET, CURSOR, id)

#define HUBP_COMMON_REG_VARIABLE_LIST \
	uint32_t DCHUBP_CNTL; \
	uint32_t HUBPREQ_DEBUG_DB; \
	uint32_t DCSURF_ADDR_CONFIG; \
	uint32_t DCSURF_TILING_CONFIG; \
	uint32_t DCSURF_SURFACE_PITCH; \
	uint32_t DCSURF_SURFACE_PITCH_C; \
	uint32_t DCSURF_SURFACE_CONFIG; \
	uint32_t DCSURF_FLIP_CONTROL; \
	uint32_t DCSURF_PRI_VIEWPORT_DIMENSION; \
	uint32_t DCSURF_PRI_VIEWPORT_START; \
	uint32_t DCSURF_SEC_VIEWPORT_DIMENSION; \
	uint32_t DCSURF_SEC_VIEWPORT_START; \
	uint32_t DCSURF_PRI_VIEWPORT_DIMENSION_C; \
	uint32_t DCSURF_PRI_VIEWPORT_START_C; \
	uint32_t DCSURF_PRIMARY_SURFACE_ADDRESS_HIGH; \
	uint32_t DCSURF_PRIMARY_SURFACE_ADDRESS; \
	uint32_t DCSURF_SECONDARY_SURFACE_ADDRESS_HIGH; \
	uint32_t DCSURF_SECONDARY_SURFACE_ADDRESS; \
	uint32_t DCSURF_PRIMARY_META_SURFACE_ADDRESS_HIGH; \
	uint32_t DCSURF_PRIMARY_META_SURFACE_ADDRESS; \
	uint32_t DCSURF_SECONDARY_META_SURFACE_ADDRESS_HIGH; \
	uint32_t DCSURF_SECONDARY_META_SURFACE_ADDRESS; \
	uint32_t DCSURF_PRIMARY_SURFACE_ADDRESS_HIGH_C; \
	uint32_t DCSURF_PRIMARY_SURFACE_ADDRESS_C; \
	uint32_t DCSURF_PRIMARY_META_SURFACE_ADDRESS_HIGH_C; \
	uint32_t DCSURF_PRIMARY_META_SURFACE_ADDRESS_C; \
	uint32_t DCSURF_SURFACE_INUSE; \
	uint32_t DCSURF_SURFACE_INUSE_HIGH; \
	uint32_t DCSURF_SURFACE_INUSE_C; \
	uint32_t DCSURF_SURFACE_INUSE_HIGH_C; \
	uint32_t DCSURF_SURFACE_EARLIEST_INUSE; \
	uint32_t DCSURF_SURFACE_EARLIEST_INUSE_HIGH; \
	uint32_t DCSURF_SURFACE_EARLIEST_INUSE_C; \
	uint32_t DCSURF_SURFACE_EARLIEST_INUSE_HIGH_C; \
	uint32_t DCSURF_SURFACE_CONTROL; \
	uint32_t HUBPRET_CONTROL; \
	uint32_t DCN_EXPANSION_MODE; \
	uint32_t DCHUBP_REQ_SIZE_CONFIG; \
	uint32_t DCHUBP_REQ_SIZE_CONFIG_C; \
	uint32_t BLANK_OFFSET_0; \
	uint32_t BLANK_OFFSET_1; \
	uint32_t DST_DIMENSIONS; \
	uint32_t DST_AFTER_SCALER; \
	uint32_t PREFETCH_SETTINS; \
	uint32_t PREFETCH_SETTINGS; \
	uint32_t VBLANK_PARAMETERS_0; \
	uint32_t REF_FREQ_TO_PIX_FREQ; \
	uint32_t VBLANK_PARAMETERS_1; \
	uint32_t VBLANK_PARAMETERS_3; \
	uint32_t NOM_PARAMETERS_0; \
	uint32_t NOM_PARAMETERS_1; \
	uint32_t NOM_PARAMETERS_4; \
	uint32_t NOM_PARAMETERS_5; \
	uint32_t PER_LINE_DELIVERY_PRE; \
	uint32_t PER_LINE_DELIVERY; \
	uint32_t PREFETCH_SETTINS_C; \
	uint32_t PREFETCH_SETTINGS_C; \
	uint32_t VBLANK_PARAMETERS_2; \
	uint32_t VBLANK_PARAMETERS_4; \
	uint32_t NOM_PARAMETERS_2; \
	uint32_t NOM_PARAMETERS_3; \
	uint32_t NOM_PARAMETERS_6; \
	uint32_t NOM_PARAMETERS_7; \
	uint32_t DCN_TTU_QOS_WM; \
	uint32_t DCN_GLOBAL_TTU_CNTL; \
	uint32_t DCN_SURF0_TTU_CNTL0; \
	uint32_t DCN_SURF0_TTU_CNTL1; \
	uint32_t DCN_SURF1_TTU_CNTL0; \
	uint32_t DCN_SURF1_TTU_CNTL1; \
	uint32_t DCN_CUR0_TTU_CNTL0; \
	uint32_t DCN_CUR0_TTU_CNTL1; \
	uint32_t DCN_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_MSB; \
	uint32_t DCN_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LSB; \
	uint32_t DCN_VM_CONTEXT0_PAGE_TABLE_START_ADDR_MSB; \
	uint32_t DCN_VM_CONTEXT0_PAGE_TABLE_START_ADDR_LSB; \
	uint32_t DCN_VM_CONTEXT0_PAGE_TABLE_END_ADDR_MSB; \
	uint32_t DCN_VM_CONTEXT0_PAGE_TABLE_END_ADDR_LSB; \
	uint32_t DCN_VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_MSB; \
	uint32_t DCN_VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_LSB; \
	uint32_t DCN_VM_MX_L1_TLB_CNTL; \
	uint32_t DCN_VM_SYSTEM_APERTURE_DEFAULT_ADDR_MSB; \
	uint32_t DCN_VM_SYSTEM_APERTURE_DEFAULT_ADDR_LSB; \
	uint32_t DCN_VM_SYSTEM_APERTURE_LOW_ADDR_MSB; \
	uint32_t DCN_VM_SYSTEM_APERTURE_LOW_ADDR_LSB; \
	uint32_t DCN_VM_SYSTEM_APERTURE_HIGH_ADDR_MSB; \
	uint32_t DCN_VM_SYSTEM_APERTURE_HIGH_ADDR_LSB; \
	uint32_t DCN_VM_SYSTEM_APERTURE_LOW_ADDR; \
	uint32_t DCN_VM_SYSTEM_APERTURE_HIGH_ADDR; \
	uint32_t DCHUBBUB_SDPIF_FB_BASE; \
	uint32_t DCHUBBUB_SDPIF_FB_OFFSET; \
	uint32_t DCN_VM_FB_LOCATION_TOP; \
	uint32_t DCN_VM_FB_LOCATION_BASE; \
	uint32_t DCN_VM_FB_OFFSET; \
	uint32_t DCN_VM_AGP_BASE; \
	uint32_t DCN_VM_AGP_BOT; \
	uint32_t DCN_VM_AGP_TOP; \
	uint32_t CURSOR_SETTINS; \
	uint32_t CURSOR_SETTINGS; \
	uint32_t CURSOR_SURFACE_ADDRESS_HIGH; \
	uint32_t CURSOR_SURFACE_ADDRESS; \
	uint32_t CURSOR_SIZE; \
	uint32_t CURSOR_CONTROL; \
	uint32_t CURSOR_POSITION; \
	uint32_t CURSOR_HOT_SPOT; \
	uint32_t CURSOR_DST_OFFSET; \
	uint32_t HUBP_CLK_CNTL

#define HUBP_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

/* Mask/shift struct generation macro for all ASICs (including those with reduced functionality) */
#define HUBP_MASK_SH_LIST_DCN(mask_sh)\
	HUBP_SF(HUBP0_DCHUBP_CNTL, HUBP_BLANK_EN, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_CNTL, HUBP_TTU_DISABLE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_CNTL, HUBP_UNDERFLOW_STATUS, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_CNTL, HUBP_UNDERFLOW_CLEAR, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_CNTL, HUBP_NO_OUTSTANDING_REQ, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_CNTL, HUBP_VTG_SEL, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_CNTL, HUBP_DISABLE, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_ADDR_CONFIG, NUM_PIPES, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_ADDR_CONFIG, NUM_BANKS, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_ADDR_CONFIG, PIPE_INTERLEAVE, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_ADDR_CONFIG, NUM_SE, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_ADDR_CONFIG, NUM_RB_PER_SE, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_ADDR_CONFIG, MAX_COMPRESSED_FRAGS, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_TILING_CONFIG, SW_MODE, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_TILING_CONFIG, META_LINEAR, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_TILING_CONFIG, RB_ALIGNED, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_TILING_CONFIG, PIPE_ALIGNED, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_PITCH, PITCH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_PITCH, META_PITCH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_PITCH_C, PITCH_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_PITCH_C, META_PITCH_C, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_SURFACE_CONFIG, SURFACE_PIXEL_FORMAT, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_FLIP_CONTROL, SURFACE_FLIP_TYPE, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_FLIP_CONTROL, SURFACE_FLIP_MODE_FOR_STEREOSYNC, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_FLIP_CONTROL, SURFACE_FLIP_IN_STEREOSYNC, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_FLIP_CONTROL, SURFACE_FLIP_PENDING, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_FLIP_CONTROL, SURFACE_UPDATE_LOCK, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_DIMENSION, PRI_VIEWPORT_WIDTH, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_DIMENSION, PRI_VIEWPORT_HEIGHT, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_START, PRI_VIEWPORT_X_START, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_START, PRI_VIEWPORT_Y_START, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_SEC_VIEWPORT_DIMENSION, SEC_VIEWPORT_WIDTH, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_SEC_VIEWPORT_DIMENSION, SEC_VIEWPORT_HEIGHT, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_SEC_VIEWPORT_START, SEC_VIEWPORT_X_START, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_SEC_VIEWPORT_START, SEC_VIEWPORT_Y_START, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_DIMENSION_C, PRI_VIEWPORT_WIDTH_C, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_DIMENSION_C, PRI_VIEWPORT_HEIGHT_C, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_START_C, PRI_VIEWPORT_X_START_C, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_PRI_VIEWPORT_START_C, PRI_VIEWPORT_Y_START_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_SURFACE_ADDRESS_HIGH, PRIMARY_SURFACE_ADDRESS_HIGH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_SURFACE_ADDRESS, PRIMARY_SURFACE_ADDRESS, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SECONDARY_SURFACE_ADDRESS_HIGH, SECONDARY_SURFACE_ADDRESS_HIGH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SECONDARY_SURFACE_ADDRESS, SECONDARY_SURFACE_ADDRESS, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_META_SURFACE_ADDRESS_HIGH, PRIMARY_META_SURFACE_ADDRESS_HIGH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_META_SURFACE_ADDRESS, PRIMARY_META_SURFACE_ADDRESS, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SECONDARY_META_SURFACE_ADDRESS_HIGH, SECONDARY_META_SURFACE_ADDRESS_HIGH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SECONDARY_META_SURFACE_ADDRESS, SECONDARY_META_SURFACE_ADDRESS, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_SURFACE_ADDRESS_HIGH_C, PRIMARY_SURFACE_ADDRESS_HIGH_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_SURFACE_ADDRESS_C, PRIMARY_SURFACE_ADDRESS_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_META_SURFACE_ADDRESS_HIGH_C, PRIMARY_META_SURFACE_ADDRESS_HIGH_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_PRIMARY_META_SURFACE_ADDRESS_C, PRIMARY_META_SURFACE_ADDRESS_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_INUSE, SURFACE_INUSE_ADDRESS, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_INUSE_HIGH, SURFACE_INUSE_ADDRESS_HIGH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_INUSE_C, SURFACE_INUSE_ADDRESS_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_INUSE_HIGH_C, SURFACE_INUSE_ADDRESS_HIGH_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_EARLIEST_INUSE, SURFACE_EARLIEST_INUSE_ADDRESS, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_EARLIEST_INUSE_HIGH, SURFACE_EARLIEST_INUSE_ADDRESS_HIGH, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_EARLIEST_INUSE_C, SURFACE_EARLIEST_INUSE_ADDRESS_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_EARLIEST_INUSE_HIGH_C, SURFACE_EARLIEST_INUSE_ADDRESS_HIGH_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, PRIMARY_SURFACE_TMZ, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, PRIMARY_SURFACE_TMZ_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, PRIMARY_META_SURFACE_TMZ, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, PRIMARY_META_SURFACE_TMZ_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, PRIMARY_SURFACE_DCC_EN, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, PRIMARY_SURFACE_DCC_IND_64B_BLK, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, SECONDARY_SURFACE_TMZ, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, SECONDARY_SURFACE_TMZ_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, SECONDARY_META_SURFACE_TMZ, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, SECONDARY_META_SURFACE_TMZ_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, SECONDARY_SURFACE_DCC_EN, mask_sh),\
	HUBP_SF(HUBPREQ0_DCSURF_SURFACE_CONTROL, SECONDARY_SURFACE_DCC_IND_64B_BLK, mask_sh),\
	HUBP_SF(HUBPRET0_HUBPRET_CONTROL, DET_BUF_PLANE1_BASE_ADDRESS, mask_sh),\
	HUBP_SF(HUBPRET0_HUBPRET_CONTROL, CROSSBAR_SRC_CB_B, mask_sh),\
	HUBP_SF(HUBPRET0_HUBPRET_CONTROL, CROSSBAR_SRC_CR_R, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_EXPANSION_MODE, DRQ_EXPANSION_MODE, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_EXPANSION_MODE, PRQ_EXPANSION_MODE, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_EXPANSION_MODE, MRQ_EXPANSION_MODE, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_EXPANSION_MODE, CRQ_EXPANSION_MODE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, CHUNK_SIZE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, MIN_CHUNK_SIZE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, META_CHUNK_SIZE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, MIN_META_CHUNK_SIZE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, DPTE_GROUP_SIZE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, MPTE_GROUP_SIZE, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, SWATH_HEIGHT, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG, PTE_ROW_HEIGHT_LINEAR, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, CHUNK_SIZE_C, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, MIN_CHUNK_SIZE_C, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, META_CHUNK_SIZE_C, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, MIN_META_CHUNK_SIZE_C, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, DPTE_GROUP_SIZE_C, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, MPTE_GROUP_SIZE_C, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, SWATH_HEIGHT_C, mask_sh),\
	HUBP_SF(HUBP0_DCHUBP_REQ_SIZE_CONFIG_C, PTE_ROW_HEIGHT_LINEAR_C, mask_sh),\
	HUBP_SF(HUBPREQ0_BLANK_OFFSET_0, REFCYC_H_BLANK_END, mask_sh),\
	HUBP_SF(HUBPREQ0_BLANK_OFFSET_0, DLG_V_BLANK_END, mask_sh),\
	HUBP_SF(HUBPREQ0_BLANK_OFFSET_1, MIN_DST_Y_NEXT_START, mask_sh),\
	HUBP_SF(HUBPREQ0_DST_DIMENSIONS, REFCYC_PER_HTOTAL, mask_sh),\
	HUBP_SF(HUBPREQ0_DST_AFTER_SCALER, REFCYC_X_AFTER_SCALER, mask_sh),\
	HUBP_SF(HUBPREQ0_DST_AFTER_SCALER, DST_Y_AFTER_SCALER, mask_sh),\
	HUBP_SF(HUBPREQ0_VBLANK_PARAMETERS_0, DST_Y_PER_VM_VBLANK, mask_sh),\
	HUBP_SF(HUBPREQ0_VBLANK_PARAMETERS_0, DST_Y_PER_ROW_VBLANK, mask_sh),\
	HUBP_SF(HUBPREQ0_REF_FREQ_TO_PIX_FREQ, REF_FREQ_TO_PIX_FREQ, mask_sh),\
	HUBP_SF(HUBPREQ0_VBLANK_PARAMETERS_1, REFCYC_PER_PTE_GROUP_VBLANK_L, mask_sh),\
	HUBP_SF(HUBPREQ0_VBLANK_PARAMETERS_3, REFCYC_PER_META_CHUNK_VBLANK_L, mask_sh),\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_4, DST_Y_PER_META_ROW_NOM_L, mask_sh),\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_5, REFCYC_PER_META_CHUNK_NOM_L, mask_sh),\
	HUBP_SF(HUBPREQ0_PER_LINE_DELIVERY_PRE, REFCYC_PER_LINE_DELIVERY_PRE_L, mask_sh),\
	HUBP_SF(HUBPREQ0_PER_LINE_DELIVERY_PRE, REFCYC_PER_LINE_DELIVERY_PRE_C, mask_sh),\
	HUBP_SF(HUBPREQ0_PER_LINE_DELIVERY, REFCYC_PER_LINE_DELIVERY_L, mask_sh),\
	HUBP_SF(HUBPREQ0_PER_LINE_DELIVERY, REFCYC_PER_LINE_DELIVERY_C, mask_sh),\
	HUBP_SF(HUBPREQ0_VBLANK_PARAMETERS_2, REFCYC_PER_PTE_GROUP_VBLANK_C, mask_sh),\
	HUBP_SF(HUBPREQ0_VBLANK_PARAMETERS_4, REFCYC_PER_META_CHUNK_VBLANK_C, mask_sh),\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_6, DST_Y_PER_META_ROW_NOM_C, mask_sh),\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_7, REFCYC_PER_META_CHUNK_NOM_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_TTU_QOS_WM, QoS_LEVEL_LOW_WM, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_TTU_QOS_WM, QoS_LEVEL_HIGH_WM, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_GLOBAL_TTU_CNTL, MIN_TTU_VBLANK, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_GLOBAL_TTU_CNTL, QoS_LEVEL_FLIP, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_SURF0_TTU_CNTL0, REFCYC_PER_REQ_DELIVERY, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_SURF0_TTU_CNTL0, QoS_LEVEL_FIXED, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_SURF0_TTU_CNTL0, QoS_RAMP_DISABLE, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_SURF0_TTU_CNTL1, REFCYC_PER_REQ_DELIVERY_PRE, mask_sh),\
	HUBP_SF(HUBP0_HUBP_CLK_CNTL, HUBP_CLOCK_ENABLE, mask_sh)

/* Mask/shift struct generation macro for ASICs with VM */
#define HUBP_MASK_SH_LIST_DCN_VM(mask_sh)\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_0, DST_Y_PER_PTE_ROW_NOM_L, mask_sh),\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_1, REFCYC_PER_PTE_GROUP_NOM_L, mask_sh),\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_2, DST_Y_PER_PTE_ROW_NOM_C, mask_sh),\
	HUBP_SF(HUBPREQ0_NOM_PARAMETERS_3, REFCYC_PER_PTE_GROUP_NOM_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_MX_L1_TLB_CNTL, ENABLE_L1_TLB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_MX_L1_TLB_CNTL, SYSTEM_ACCESS_MODE, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_CUR0_TTU_CNTL0, REFCYC_PER_REQ_DELIVERY, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_CUR0_TTU_CNTL0, QoS_LEVEL_FIXED, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_CUR0_TTU_CNTL0, QoS_RAMP_DISABLE, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_CUR0_TTU_CNTL1, REFCYC_PER_REQ_DELIVERY_PRE, mask_sh)

#define HUBP_MASK_SH_LIST_DCN10(mask_sh)\
	HUBP_MASK_SH_LIST_DCN(mask_sh),\
	HUBP_MASK_SH_LIST_DCN_VM(mask_sh),\
	HUBP_SF(HUBP0_DCSURF_SURFACE_CONFIG, ROTATION_ANGLE, mask_sh),\
	HUBP_SF(HUBP0_DCSURF_SURFACE_CONFIG, H_MIRROR_EN, mask_sh),\
	HUBP_SF(HUBPREQ0_PREFETCH_SETTINS, DST_Y_PREFETCH, mask_sh),\
	HUBP_SF(HUBPREQ0_PREFETCH_SETTINS, VRATIO_PREFETCH, mask_sh),\
	HUBP_SF(HUBPREQ0_PREFETCH_SETTINS_C, VRATIO_PREFETCH_C, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_MSB, VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_MSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LSB, VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PAGE_TABLE_START_ADDR_MSB, VM_CONTEXT0_PAGE_TABLE_START_ADDR_MSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PAGE_TABLE_START_ADDR_LSB, VM_CONTEXT0_PAGE_TABLE_START_ADDR_LSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PAGE_TABLE_END_ADDR_MSB, VM_CONTEXT0_PAGE_TABLE_END_ADDR_MSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PAGE_TABLE_END_ADDR_LSB, VM_CONTEXT0_PAGE_TABLE_END_ADDR_LSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_MSB, VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_MSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_MSB, VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_SYSTEM, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_LSB, VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_LSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_SYSTEM_APERTURE_LOW_ADDR_MSB, MC_VM_SYSTEM_APERTURE_LOW_ADDR_MSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_SYSTEM_APERTURE_LOW_ADDR_LSB, MC_VM_SYSTEM_APERTURE_LOW_ADDR_LSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_SYSTEM_APERTURE_HIGH_ADDR_MSB, MC_VM_SYSTEM_APERTURE_HIGH_ADDR_MSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_SYSTEM_APERTURE_HIGH_ADDR_LSB, MC_VM_SYSTEM_APERTURE_HIGH_ADDR_LSB, mask_sh),\
	HUBP_SF(DCHUBBUB_SDPIF_FB_BASE, SDPIF_FB_BASE, mask_sh),\
	HUBP_SF(DCHUBBUB_SDPIF_FB_OFFSET, SDPIF_FB_OFFSET, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_SYSTEM_APERTURE_DEFAULT_ADDR_MSB, MC_VM_SYSTEM_APERTURE_DEFAULT_SYSTEM, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_SYSTEM_APERTURE_DEFAULT_ADDR_MSB, MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR_MSB, mask_sh),\
	HUBP_SF(HUBPREQ0_DCN_VM_SYSTEM_APERTURE_DEFAULT_ADDR_LSB, MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR_LSB, mask_sh),\
	HUBP_SF(HUBPREQ0_CURSOR_SETTINS, CURSOR0_DST_Y_OFFSET, mask_sh), \
	HUBP_SF(HUBPREQ0_CURSOR_SETTINS, CURSOR0_CHUNK_HDL_ADJUST, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_SURFACE_ADDRESS_HIGH, CURSOR_SURFACE_ADDRESS_HIGH, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_SURFACE_ADDRESS, CURSOR_SURFACE_ADDRESS, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_SIZE, CURSOR_WIDTH, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_SIZE, CURSOR_HEIGHT, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_CONTROL, CURSOR_MODE, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_CONTROL, CURSOR_2X_MAGNIFY, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_CONTROL, CURSOR_PITCH, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_CONTROL, CURSOR_LINES_PER_CHUNK, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_CONTROL, CURSOR_ENABLE, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_POSITION, CURSOR_X_POSITION, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_POSITION, CURSOR_Y_POSITION, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_HOT_SPOT, CURSOR_HOT_SPOT_X, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_HOT_SPOT, CURSOR_HOT_SPOT_Y, mask_sh), \
	HUBP_SF(CURSOR0_CURSOR_DST_OFFSET, CURSOR_DST_X_OFFSET, mask_sh)

#define DCN_HUBP_REG_FIELD_LIST(type) \
	type HUBP_BLANK_EN;\
	type HUBP_DISABLE;\
	type HUBP_TTU_DISABLE;\
	type HUBP_NO_OUTSTANDING_REQ;\
	type HUBP_VTG_SEL;\
	type HUBP_UNDERFLOW_STATUS;\
	type HUBP_UNDERFLOW_CLEAR;\
	type NUM_PIPES;\
	type NUM_BANKS;\
	type PIPE_INTERLEAVE;\
	type NUM_SE;\
	type NUM_RB_PER_SE;\
	type MAX_COMPRESSED_FRAGS;\
	type SW_MODE;\
	type META_LINEAR;\
	type RB_ALIGNED;\
	type PIPE_ALIGNED;\
	type PITCH;\
	type META_PITCH;\
	type PITCH_C;\
	type META_PITCH_C;\
	type ROTATION_ANGLE;\
	type H_MIRROR_EN;\
	type SURFACE_PIXEL_FORMAT;\
	type SURFACE_FLIP_TYPE;\
	type SURFACE_FLIP_MODE_FOR_STEREOSYNC;\
	type SURFACE_FLIP_IN_STEREOSYNC;\
	type SURFACE_UPDATE_LOCK;\
	type SURFACE_FLIP_PENDING;\
	type PRI_VIEWPORT_WIDTH; \
	type PRI_VIEWPORT_HEIGHT; \
	type PRI_VIEWPORT_X_START; \
	type PRI_VIEWPORT_Y_START; \
	type SEC_VIEWPORT_WIDTH; \
	type SEC_VIEWPORT_HEIGHT; \
	type SEC_VIEWPORT_X_START; \
	type SEC_VIEWPORT_Y_START; \
	type PRI_VIEWPORT_WIDTH_C; \
	type PRI_VIEWPORT_HEIGHT_C; \
	type PRI_VIEWPORT_X_START_C; \
	type PRI_VIEWPORT_Y_START_C; \
	type PRIMARY_SURFACE_ADDRESS_HIGH;\
	type PRIMARY_SURFACE_ADDRESS;\
	type SECONDARY_SURFACE_ADDRESS_HIGH;\
	type SECONDARY_SURFACE_ADDRESS;\
	type PRIMARY_META_SURFACE_ADDRESS_HIGH;\
	type PRIMARY_META_SURFACE_ADDRESS;\
	type SECONDARY_META_SURFACE_ADDRESS_HIGH;\
	type SECONDARY_META_SURFACE_ADDRESS;\
	type PRIMARY_SURFACE_ADDRESS_HIGH_C;\
	type PRIMARY_SURFACE_ADDRESS_C;\
	type PRIMARY_META_SURFACE_ADDRESS_HIGH_C;\
	type PRIMARY_META_SURFACE_ADDRESS_C;\
	type SURFACE_INUSE_ADDRESS;\
	type SURFACE_INUSE_ADDRESS_HIGH;\
	type SURFACE_INUSE_ADDRESS_C;\
	type SURFACE_INUSE_ADDRESS_HIGH_C;\
	type SURFACE_EARLIEST_INUSE_ADDRESS;\
	type SURFACE_EARLIEST_INUSE_ADDRESS_HIGH;\
	type SURFACE_EARLIEST_INUSE_ADDRESS_C;\
	type SURFACE_EARLIEST_INUSE_ADDRESS_HIGH_C;\
	type PRIMARY_SURFACE_TMZ;\
	type PRIMARY_SURFACE_TMZ_C;\
	type SECONDARY_SURFACE_TMZ;\
	type SECONDARY_SURFACE_TMZ_C;\
	type PRIMARY_META_SURFACE_TMZ;\
	type PRIMARY_META_SURFACE_TMZ_C;\
	type SECONDARY_META_SURFACE_TMZ;\
	type SECONDARY_META_SURFACE_TMZ_C;\
	type PRIMARY_SURFACE_DCC_EN;\
	type PRIMARY_SURFACE_DCC_IND_64B_BLK;\
	type SECONDARY_SURFACE_DCC_EN;\
	type SECONDARY_SURFACE_DCC_IND_64B_BLK;\
	type DET_BUF_PLANE1_BASE_ADDRESS;\
	type CROSSBAR_SRC_CB_B;\
	type CROSSBAR_SRC_CR_R;\
	type DRQ_EXPANSION_MODE;\
	type PRQ_EXPANSION_MODE;\
	type MRQ_EXPANSION_MODE;\
	type CRQ_EXPANSION_MODE;\
	type CHUNK_SIZE;\
	type MIN_CHUNK_SIZE;\
	type META_CHUNK_SIZE;\
	type MIN_META_CHUNK_SIZE;\
	type DPTE_GROUP_SIZE;\
	type MPTE_GROUP_SIZE;\
	type SWATH_HEIGHT;\
	type PTE_ROW_HEIGHT_LINEAR;\
	type CHUNK_SIZE_C;\
	type MIN_CHUNK_SIZE_C;\
	type META_CHUNK_SIZE_C;\
	type MIN_META_CHUNK_SIZE_C;\
	type DPTE_GROUP_SIZE_C;\
	type MPTE_GROUP_SIZE_C;\
	type SWATH_HEIGHT_C;\
	type PTE_ROW_HEIGHT_LINEAR_C;\
	type REFCYC_H_BLANK_END;\
	type DLG_V_BLANK_END;\
	type MIN_DST_Y_NEXT_START;\
	type REFCYC_PER_HTOTAL;\
	type REFCYC_X_AFTER_SCALER;\
	type DST_Y_AFTER_SCALER;\
	type DST_Y_PREFETCH;\
	type VRATIO_PREFETCH;\
	type DST_Y_PER_VM_VBLANK;\
	type DST_Y_PER_ROW_VBLANK;\
	type REF_FREQ_TO_PIX_FREQ;\
	type REFCYC_PER_PTE_GROUP_VBLANK_L;\
	type REFCYC_PER_META_CHUNK_VBLANK_L;\
	type DST_Y_PER_PTE_ROW_NOM_L;\
	type REFCYC_PER_PTE_GROUP_NOM_L;\
	type DST_Y_PER_META_ROW_NOM_L;\
	type REFCYC_PER_META_CHUNK_NOM_L;\
	type REFCYC_PER_LINE_DELIVERY_PRE_L;\
	type REFCYC_PER_LINE_DELIVERY_PRE_C;\
	type REFCYC_PER_LINE_DELIVERY_L;\
	type REFCYC_PER_LINE_DELIVERY_C;\
	type VRATIO_PREFETCH_C;\
	type REFCYC_PER_PTE_GROUP_VBLANK_C;\
	type REFCYC_PER_META_CHUNK_VBLANK_C;\
	type DST_Y_PER_PTE_ROW_NOM_C;\
	type REFCYC_PER_PTE_GROUP_NOM_C;\
	type DST_Y_PER_META_ROW_NOM_C;\
	type REFCYC_PER_META_CHUNK_NOM_C;\
	type QoS_LEVEL_LOW_WM;\
	type QoS_LEVEL_HIGH_WM;\
	type MIN_TTU_VBLANK;\
	type QoS_LEVEL_FLIP;\
	type REFCYC_PER_REQ_DELIVERY;\
	type QoS_LEVEL_FIXED;\
	type QoS_RAMP_DISABLE;\
	type REFCYC_PER_REQ_DELIVERY_PRE;\
	type VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_MSB;\
	type VM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LSB;\
	type VM_CONTEXT0_PAGE_TABLE_START_ADDR_MSB;\
	type VM_CONTEXT0_PAGE_TABLE_START_ADDR_LSB;\
	type VM_CONTEXT0_PAGE_TABLE_END_ADDR_MSB;\
	type VM_CONTEXT0_PAGE_TABLE_END_ADDR_LSB;\
	type VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_MSB;\
	type VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_SYSTEM;\
	type VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR_LSB;\
	type ENABLE_L1_TLB;\
	type SYSTEM_ACCESS_MODE;\
	type HUBP_CLOCK_ENABLE;\
	type MC_VM_SYSTEM_APERTURE_DEFAULT_SYSTEM;\
	type MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR_MSB;\
	type MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR_LSB;\
	type MC_VM_SYSTEM_APERTURE_LOW_ADDR_MSB;\
	type MC_VM_SYSTEM_APERTURE_LOW_ADDR_LSB;\
	type MC_VM_SYSTEM_APERTURE_HIGH_ADDR_MSB;\
	type MC_VM_SYSTEM_APERTURE_HIGH_ADDR_LSB;\
	type MC_VM_SYSTEM_APERTURE_LOW_ADDR;\
	type MC_VM_SYSTEM_APERTURE_HIGH_ADDR;\
	type SDPIF_FB_TOP;\
	type SDPIF_FB_BASE;\
	type SDPIF_FB_OFFSET;\
	type SDPIF_AGP_BASE;\
	type SDPIF_AGP_BOT;\
	type SDPIF_AGP_TOP;\
	type FB_TOP;\
	type FB_BASE;\
	type FB_OFFSET;\
	type AGP_BASE;\
	type AGP_BOT;\
	type AGP_TOP;\
	/* todo:  get these from GVM instead of reading registers ourselves */\
	type PAGE_DIRECTORY_ENTRY_HI32;\
	type PAGE_DIRECTORY_ENTRY_LO32;\
	type LOGICAL_PAGE_NUMBER_HI4;\
	type LOGICAL_PAGE_NUMBER_LO32;\
	type PHYSICAL_PAGE_ADDR_HI4;\
	type PHYSICAL_PAGE_ADDR_LO32;\
	type PHYSICAL_PAGE_NUMBER_MSB;\
	type PHYSICAL_PAGE_NUMBER_LSB;\
	type LOGICAL_ADDR;\
	type CURSOR0_DST_Y_OFFSET; \
	type CURSOR0_CHUNK_HDL_ADJUST; \
	type CURSOR_SURFACE_ADDRESS_HIGH; \
	type CURSOR_SURFACE_ADDRESS; \
	type CURSOR_WIDTH; \
	type CURSOR_HEIGHT; \
	type CURSOR_MODE; \
	type CURSOR_2X_MAGNIFY; \
	type CURSOR_PITCH; \
	type CURSOR_LINES_PER_CHUNK; \
	type CURSOR_ENABLE; \
	type CURSOR_X_POSITION; \
	type CURSOR_Y_POSITION; \
	type CURSOR_HOT_SPOT_X; \
	type CURSOR_HOT_SPOT_Y; \
	type CURSOR_DST_X_OFFSET; \
	type OUTPUT_FP

struct dcn_mi_registers {
	HUBP_COMMON_REG_VARIABLE_LIST;
};

struct dcn_mi_shift {
	DCN_HUBP_REG_FIELD_LIST(uint8_t);
};

struct dcn_mi_mask {
	DCN_HUBP_REG_FIELD_LIST(uint32_t);
};

struct dcn_hubp_state {
	struct _vcs_dpi_display_dlg_regs_st dlg_attr;
	struct _vcs_dpi_display_ttu_regs_st ttu_attr;
	struct _vcs_dpi_display_rq_regs_st rq_regs;
	uint32_t pixel_format;
	uint32_t inuse_addr_hi;
	uint32_t inuse_addr_lo;
	uint32_t viewport_width;
	uint32_t viewport_height;
	uint32_t rotation_angle;
	uint32_t h_mirror_en;
	uint32_t sw_mode;
	uint32_t dcc_en;
	uint32_t blank_en;
	uint32_t underflow_status;
	uint32_t ttu_disable;
	uint32_t min_ttu_vblank;
	uint32_t qos_level_low_wm;
	uint32_t qos_level_high_wm;
};

struct dcn10_hubp {
	struct hubp base;
	struct dcn_hubp_state state;
	const struct dcn_mi_registers *hubp_regs;
	const struct dcn_mi_shift *hubp_shift;
	const struct dcn_mi_mask *hubp_mask;
};

void hubp1_program_surface_config(
	struct hubp *hubp,
	enum surface_pixel_format format,
	union dc_tiling_info *tiling_info,
	union plane_size *plane_size,
	enum dc_rotation_angle rotation,
	struct dc_plane_dcc_param *dcc,
	bool horizontal_mirror,
	unsigned int compat_level);

void hubp1_program_deadline(
		struct hubp *hubp,
		struct _vcs_dpi_display_dlg_regs_st *dlg_attr,
		struct _vcs_dpi_display_ttu_regs_st *ttu_attr);

void hubp1_program_requestor(
		struct hubp *hubp,
		struct _vcs_dpi_display_rq_regs_st *rq_regs);

void hubp1_program_pixel_format(
	struct hubp *hubp,
	enum surface_pixel_format format);

void hubp1_program_size(
	struct hubp *hubp,
	enum surface_pixel_format format,
	const union plane_size *plane_size,
	struct dc_plane_dcc_param *dcc);

void hubp1_program_rotation(
	struct hubp *hubp,
	enum dc_rotation_angle rotation,
	bool horizontal_mirror);

void hubp1_program_tiling(
	struct hubp *hubp,
	const union dc_tiling_info *info,
	const enum surface_pixel_format pixel_format);

void hubp1_dcc_control(struct hubp *hubp,
		bool enable,
		bool independent_64b_blks);

bool hubp1_program_surface_flip_and_addr(
	struct hubp *hubp,
	const struct dc_plane_address *address,
	bool flip_immediate);

bool hubp1_is_flip_pending(struct hubp *hubp);

void hubp1_cursor_set_attributes(
		struct hubp *hubp,
		const struct dc_cursor_attributes *attr);

void hubp1_cursor_set_position(
		struct hubp *hubp,
		const struct dc_cursor_position *pos,
		const struct dc_cursor_mi_param *param);

void hubp1_set_blank(struct hubp *hubp, bool blank);

void min_set_viewport(struct hubp *hubp,
		const struct rect *viewport,
		const struct rect *viewport_c);

void hubp1_clk_cntl(struct hubp *hubp, bool enable);
void hubp1_vtg_sel(struct hubp *hubp, uint32_t otg_inst);

void dcn10_hubp_construct(
	struct dcn10_hubp *hubp1,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dcn_mi_registers *hubp_regs,
	const struct dcn_mi_shift *hubp_shift,
	const struct dcn_mi_mask *hubp_mask);

void hubp1_read_state(struct hubp *hubp);
void hubp1_clear_underflow(struct hubp *hubp);

enum cursor_pitch hubp1_get_cursor_pitch(unsigned int pitch);

void hubp1_vready_workaround(struct hubp *hubp,
		struct _vcs_dpi_display_pipe_dest_params_st *pipe_dest);

#endif
