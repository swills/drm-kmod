/*
 * Copyright 2018 Advanced Micro Devices, Inc.
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

#include "mod_info_packet.h"
#include "core_types.h"

enum ColorimetryRGBDP {
	ColorimetryRGB_DP_sRGB               = 0,
	ColorimetryRGB_DP_AdobeRGB           = 3,
	ColorimetryRGB_DP_P3                 = 4,
	ColorimetryRGB_DP_CustomColorProfile = 5,
	ColorimetryRGB_DP_ITU_R_BT2020RGB    = 6,
};
enum ColorimetryYCCDP {
	ColorimetryYCC_DP_ITU601        = 0,
	ColorimetryYCC_DP_ITU709        = 1,
	ColorimetryYCC_DP_AdobeYCC      = 5,
	ColorimetryYCC_DP_ITU2020YCC    = 6,
	ColorimetryYCC_DP_ITU2020YCbCr  = 7,
};

static void mod_build_vsc_infopacket(const struct dc_stream_state *stream,
		struct dc_info_packet *info_packet)
{
	unsigned int vscPacketRevision = 0;
	unsigned int i;
	unsigned int pixelEncoding = 0;
	unsigned int colorimetryFormat = 0;

	if (stream->timing.timing_3d_format != TIMING_3D_FORMAT_NONE && stream->view_format != VIEW_3D_FORMAT_NONE)
		vscPacketRevision = 1;

	/*VSC packet set to 2 when DP revision >= 1.2*/
	if (stream->psr_version != 0)
		vscPacketRevision = 2;

	if (stream->timing.pixel_encoding == PIXEL_ENCODING_YCBCR420)
		vscPacketRevision = 5;

	/* VSC packet not needed based on the features
	 * supported by this DP display
	 */
	if (vscPacketRevision == 0)
		return;

	if (vscPacketRevision == 0x2) {
		/* Secondary-data Packet ID = 0*/
		info_packet->hb0 = 0x00;
		/* 07h - Packet Type Value indicating Video
		 * Stream Configuration packet
		 */
		info_packet->hb1 = 0x07;
		/* 02h = VSC SDP supporting 3D stereo and PSR
		 * (applies to eDP v1.3 or higher).
		 */
		info_packet->hb2 = 0x02;
		/* 08h = VSC packet supporting 3D stereo + PSR
		 * (HB2 = 02h).
		 */
		info_packet->hb3 = 0x08;

		for (i = 0; i < 28; i++)
			info_packet->sb[i] = 0;

		info_packet->valid = true;
	}

	if (vscPacketRevision == 0x1) {

		info_packet->hb0 = 0x00;	// Secondary-data Packet ID = 0
		info_packet->hb1 = 0x07;	// 07h = Packet Type Value indicating Video Stream Configuration packet
		info_packet->hb2 = 0x01;	// 01h = Revision number. VSC SDP supporting 3D stereo only
		info_packet->hb3 = 0x01;	// 01h = VSC SDP supporting 3D stereo only (HB2 = 01h).

		if (stream->timing.timing_3d_format == TIMING_3D_FORMAT_INBAND_FA)
			info_packet->sb[0] = 0x1;

		info_packet->valid = true;
	}

	/* 05h = VSC SDP supporting 3D stereo, PSR2, and Pixel Encoding/Colorimetry Format indication.
	 *   Added in DP1.3, a DP Source device is allowed to indicate the pixel encoding/colorimetry
	 *   format to the DP Sink device with VSC SDP only when the DP Sink device supports it
	 *   (i.e., VSC_SDP_EXTENSION_FOR_COLORIMETRY_SUPPORTED bit in the DPRX_FEATURE_ENUMERATION_LIST
	 *   register (DPCD Address 02210h, bit 3) is set to 1).
	 *   (Requires VSC_SDP_EXTENSION_FOR_COLORIMETRY_SUPPORTED bit set to 1 in DPCD 02210h. This
	 *   DPCD register is exposed in the new Extended Receiver Capability field for DPCD Rev. 1.4
	 *   (and higher). When MISC1. bit 6. is Set to 1, a Source device uses a VSC SDP to indicate
	 *   the Pixel Encoding/Colorimetry Format and that a Sink device must ignore MISC1, bit 7, and
	 *   MISC0, bits 7:1 (MISC1, bit 7. and MISC0, bits 7:1 become “don’t care”).)
	 */
	if (vscPacketRevision == 0x5) {
		/* Secondary-data Packet ID = 0 */
		info_packet->hb0 = 0x00;
		/* 07h - Packet Type Value indicating Video Stream Configuration packet */
		info_packet->hb1 = 0x07;
		/* 05h = VSC SDP supporting 3D stereo, PSR2, and Pixel Encoding/Colorimetry Format indication. */
		info_packet->hb2 = 0x05;
		/* 13h = VSC SDP supporting 3D stereo, + PSR2, + Pixel Encoding/Colorimetry Format indication (HB2 = 05h). */
		info_packet->hb3 = 0x13;

		info_packet->valid = true;

		/* Set VSC SDP fields for pixel encoding and colorimetry format from DP 1.3 specs
		 * Data Bytes DB 18~16
		 * Bits 3:0 (Colorimetry Format)        |  Bits 7:4 (Pixel Encoding)
		 * ----------------------------------------------------------------------------------------------------
		 * 0x0 = sRGB                           |  0 = RGB
		 * 0x1 = RGB Wide Gamut Fixed Point
		 * 0x2 = RGB Wide Gamut Floating Point
		 * 0x3 = AdobeRGB
		 * 0x4 = DCI-P3
		 * 0x5 = CustomColorProfile
		 * (others reserved)
		 * ----------------------------------------------------------------------------------------------------
		 * 0x0 = ITU-R BT.601                   |  1 = YCbCr444
		 * 0x1 = ITU-R BT.709
		 * 0x2 = xvYCC601
		 * 0x3 = xvYCC709
		 * 0x4 = sYCC601
		 * 0x5 = AdobeYCC601
		 * 0x6 = ITU-R BT.2020 Y'cC'bcC'rc
		 * 0x7 = ITU-R BT.2020 Y'C'bC'r
		 * (others reserved)
		 * ----------------------------------------------------------------------------------------------------
		 * 0x0 = ITU-R BT.601                   |  2 = YCbCr422
		 * 0x1 = ITU-R BT.709
		 * 0x2 = xvYCC601
		 * 0x3 = xvYCC709
		 * 0x4 = sYCC601
		 * 0x5 = AdobeYCC601
		 * 0x6 = ITU-R BT.2020 Y'cC'bcC'rc
		 * 0x7 = ITU-R BT.2020 Y'C'bC'r
		 * (others reserved)
		 * ----------------------------------------------------------------------------------------------------
		 * 0x0 = ITU-R BT.601                   |  3 = YCbCr420
		 * 0x1 = ITU-R BT.709
		 * 0x2 = xvYCC601
		 * 0x3 = xvYCC709
		 * 0x4 = sYCC601
		 * 0x5 = AdobeYCC601
		 * 0x6 = ITU-R BT.2020 Y'cC'bcC'rc
		 * 0x7 = ITU-R BT.2020 Y'C'bC'r
		 * (others reserved)
		 * ----------------------------------------------------------------------------------------------------
		 * 0x0 =DICOM Part14 Grayscale          |  4 = Yonly
		 * Display Function
		 * (others reserved)
		 */

		/* Set Pixel Encoding */
		switch (stream->timing.pixel_encoding) {
		case PIXEL_ENCODING_RGB:
			pixelEncoding = 0x0;  /* RGB = 0h */
			break;
		case PIXEL_ENCODING_YCBCR444:
			pixelEncoding = 0x1;  /* YCbCr444 = 1h */
			break;
		case PIXEL_ENCODING_YCBCR422:
			pixelEncoding = 0x2;  /* YCbCr422 = 2h */
			break;
		case PIXEL_ENCODING_YCBCR420:
			pixelEncoding = 0x3;  /* YCbCr420 = 3h */
			break;
		default:
			pixelEncoding = 0x0;  /* default RGB = 0h */
			break;
		}

		/* Set Colorimetry format based on pixel encoding */
		switch (stream->timing.pixel_encoding) {
		case PIXEL_ENCODING_RGB:
			if ((stream->output_color_space == COLOR_SPACE_SRGB) ||
					(stream->output_color_space == COLOR_SPACE_SRGB_LIMITED))
				colorimetryFormat = ColorimetryRGB_DP_sRGB;
			else if (stream->output_color_space == COLOR_SPACE_ADOBERGB)
				colorimetryFormat = ColorimetryRGB_DP_AdobeRGB;
			else if ((stream->output_color_space == COLOR_SPACE_2020_RGB_FULLRANGE) ||
					(stream->output_color_space == COLOR_SPACE_2020_RGB_LIMITEDRANGE))
				colorimetryFormat = ColorimetryRGB_DP_ITU_R_BT2020RGB;
			break;

		case PIXEL_ENCODING_YCBCR444:
		case PIXEL_ENCODING_YCBCR422:
		case PIXEL_ENCODING_YCBCR420:
			/* Note: xvYCC probably not supported correctly here on DP since colorspace translation
			 * loses distinction between BT601 vs xvYCC601 in translation
			 */
			if (stream->output_color_space == COLOR_SPACE_YCBCR601)
				colorimetryFormat = ColorimetryYCC_DP_ITU601;
			else if (stream->output_color_space == COLOR_SPACE_YCBCR709)
				colorimetryFormat = ColorimetryYCC_DP_ITU709;
			else if (stream->output_color_space == COLOR_SPACE_ADOBERGB)
				colorimetryFormat = ColorimetryYCC_DP_AdobeYCC;
			else if (stream->output_color_space == COLOR_SPACE_2020_YCBCR)
				colorimetryFormat = ColorimetryYCC_DP_ITU2020YCbCr;
			break;

		default:
			colorimetryFormat = ColorimetryRGB_DP_sRGB;
			break;
		}

		info_packet->sb[16] = (pixelEncoding << 4) | colorimetryFormat;

		/* Set color depth */
		switch (stream->timing.display_color_depth) {
		case COLOR_DEPTH_666:
			/* NOTE: This is actually not valid for YCbCr pixel encoding to have 6 bpc
			 *       as of DP1.4 spec, but value of 0 probably reserved here for potential future use.
			 */
			info_packet->sb[17] = 0;
			break;
		case COLOR_DEPTH_888:
			info_packet->sb[17] = 1;
			break;
		case COLOR_DEPTH_101010:
			info_packet->sb[17] = 2;
			break;
		case COLOR_DEPTH_121212:
			info_packet->sb[17] = 3;
			break;
		/*case COLOR_DEPTH_141414: -- NO SUCH FORMAT IN DP SPEC */
		case COLOR_DEPTH_161616:
			info_packet->sb[17] = 4;
			break;
		default:
			info_packet->sb[17] = 0;
			break;
		}

		/* all YCbCr are always limited range */
		if ((stream->output_color_space == COLOR_SPACE_SRGB_LIMITED) ||
				(stream->output_color_space == COLOR_SPACE_2020_RGB_LIMITEDRANGE) ||
				(pixelEncoding != 0x0)) {
			info_packet->sb[17] |= 0x80; /* DB17 bit 7 set to 1 for CEA timing. */
		}

		/* Content Type (Bits 2:0)
		 *  0 = Not defined.
		 *  1 = Graphics.
		 *  2 = Photo.
		 *  3 = Video.
		 *  4 = Game.
		 */
		info_packet->sb[18] = 0;
	}

}

void mod_build_infopackets(struct info_packet_inputs *inputs,
		struct info_packets *info_packets)
{
	if (info_packets->pVscInfoPacket != NULL)
		mod_build_vsc_infopacket(inputs->pStream, info_packets->pVscInfoPacket);
}

