#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _clouds_skybox_yay0SegmentRomStart, _clouds_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x01, 10057, 5700, 26127),
		INSTANT_WARP(0x01, 0x01, -21986, -4038, 4699),
		INSTANT_WARP(0x02, 0x01, 9246, 1997, 19331),
		WARP_NODE(0xFF, LEVEL_CASTLE, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xFE, LEVEL_CASTLE, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC2, LEVEL_JRB, 0x01, 0xC2, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC1, LEVEL_JRB, 0x01, 0xC1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC3, LEVEL_JRB, 0x01, 0xC3, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC4, LEVEL_JRB, 0x01, 0xC4, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -10530, 10257, 8618, 0, 180, 0, 0x00C10000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -10618, 9945, 7185, 0, -4, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10966, 9945, -3623, 0, 8, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6714, 7343, -1539, 0, 7, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7736, 6055, 12498, 0, -37, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12036, 5879, 13542, 0, -138, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -14001, 4562, -3094, 0, 164, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10536, 8169, -10114, 0, -44, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_ELEVATOR, -10546, 9322, 10094, 0, -90, 0, (0x02 << 24) | (0x0A << 16), bhvAnotherElavator),
		OBJECT(MODEL_FALL_PIECE_2_TEMPLE, -10413, 8965, 66, 0, -4, 0, 0x00010000, bhvFallingPiece),
		OBJECT(MODEL_FALL_PIECE_2_TEMPLE, -11164, 9557, 5181, 0, -4, 0, 0x00000000, bhvFallingPiece),
		OBJECT(MODEL_NONE, -10546, 9464, 10149, 0, 180, 0, 0x000A0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 1770, 8557, 8274, 0, 180, 0, 0x00C20000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 9483, 1413, 12977, 0, -90, 0, 0x00C30000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 1664, 8398, 6869, 0, -177, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2700, 6949, -3094, 0, 179, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4426, 6183, 4965, 0, 25, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2372, 6706, 5018, 0, 126, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4020, 4919, -10574, 0, -40, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 14590, 3085, -10562, -3, 179, 1, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 11768, 1549, 13019, 0, 91, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6843, 654, -2433, 0, 7, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4593, 364, -8164, 0, 82, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1950, 333, -9371, 0, 92, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10326, -453, -6447, 0, 160, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10512, -381, -4336, 0, 174, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6776, -312, -3338, 0, 174, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -949, -1129, 13215, 0, -89, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6245, -312, -7278, 0, -15, 0, 0x00040000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 62, -1129, 12876, -1, 134, -2, 0x00040000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4683, -1129, 10648, 0, -79, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1151, -1129, 10237, 0, -86, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 983, 4199, -13990, 0, -86, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 10139, 3683, -13535, -13, -110, -4, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 13954, 2266, 844, -1, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4239, 5551, -261, 0, -15, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4324, 5201, -5598, 0, 22, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -265, 7401, -5846, 0, 71, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9166, 569, -1291, 0, -20, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9479, 466, -4626, 0, 51, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7483, 323, -8434, 0, 62, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4029, 135, -10045, 0, 66, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_RED_COIN, 6800, 4176, -13797, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 13154, 3995, -12135, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 14807, 3220, -8178, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 14592, 2897, -5990, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 14975, 2612, -3694, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 14000, 2367, 5449, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 13929, 2245, 1663, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 14469, 2127, 7511, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_NONE, 14138, 1999, 11236, 0, -37, 0, 0x06000000, bhvHiddenDragonCoin),
		OBJECT(MODEL_DRAGON_COIN, -10852, -670, -554, 0, -37, 0, 0x07000000, bhvDragonCoin),
		OBJECT(MODEL_RED_CIRCLE, 3581, 4646, -13770, 0, -88, 0, 0x00000000, bhvRedRing),
		OBJECT(MODEL_NONE, -9484, -6087, 13328, 0, 180, 0, 0x00C40000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -8773, -6221, 10444, 0, 167, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -9031, -6228, 6360, 0, -173, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8695, -6517, 2164, 0, 113, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2653, -6874, 5483, 0, 63, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6370, -7389, 8367, 0, 148, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8479, -7528, 1036, 0, -177, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7482, -7716, -4426, 0, 174, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2036, -8249, -3073, 0, -58, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6052, -8229, 85, 0, -95, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7664, -7770, -1191, 0, -152, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8179, -7752, 3440, 0, 159, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 20, -7169, 8992, 0, -151, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_DRAGON_COIN, -10965, -6332, 7178, 0, -37, 0, 0x08000000, bhvDragonCoin),
		OBJECT(MODEL_NONE, -10182, -9401, -6946, 0, 179, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10182, -9401, -8425, 0, 179, 0, 0x00000000, bhvCoinFormation),
		TERRAIN(jrb_area_1_collision),
		ROOMS(jrb_area_1_collision_rooms),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_ESCAPE),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
