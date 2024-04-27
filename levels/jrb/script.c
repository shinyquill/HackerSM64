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
		INSTANT_WARP(0x01, 0x01, -21986, -3915, 4699),
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
		OBJECT(MODEL_NONE, -7012, 9945, -2844, 0, 7, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7736, 9945, 12498, 0, -37, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -13165, 9945, 12470, 0, -138, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -14001, 9945, -3094, 0, 164, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_ELEVATOR, -10546, 9322, 10094, 0, -90, 0, (0x02 << 24) | (0x0A << 16), bhvAnotherElavator),
		OBJECT(MODEL_NONE, -10546, 9464, 10149, 0, -90, 0, 0x000A0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 1770, 8557, 8274, 0, 180, 0, 0x00C20000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 9483, 1413, 12977, 0, -90, 0, 0x00C30000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 1664, 8398, 6869, 0, -177, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2700, 6949, -3094, 0, 179, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4290, 6183, 4986, 0, 53, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2372, 6706, 5018, 0, 126, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4020, 4919, -10574, 0, -40, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 14356, 3112, -6676, 0, 160, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8792, 1549, 13019, 0, 91, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6843, 654, -2433, 0, 7, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4593, 364, -8164, 0, 82, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1950, 333, -9371, 0, 92, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10326, -453, -6447, 0, 160, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10512, -381, -4336, 0, 174, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6776, -312, -3338, 0, 174, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1163, -1129, 13167, 0, -89, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_RED_COIN, 7679, 654, 2532, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 9001, 604, 629, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 8839, 545, -1528, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 10509, 505, -3129, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 9024, 440, -4893, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 8305, 353, -7468, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 6124, 242, -9208, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 4152, 137, -9951, 0, -37, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_NONE, 1228, 117, -9533, 0, -37, 0, 0x00000000, bhvHiddenDragonCoin),
		OBJECT(MODEL_DRAGON_COIN, -10852, -670, -554, 0, -37, 0, 0x00000000, bhvDragonCoin),
		OBJECT(MODEL_RED_CIRCLE, 6449, 897, 4875, 0, -37, 0, 0x00000000, bhvRedRing),
		OBJECT(MODEL_NONE, -9484, -6087, 13328, 0, 180, 0, 0x00C40000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -8773, -6221, 10444, 0, 167, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -9031, -6228, 6360, 0, -173, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8695, -6517, 2164, 0, 113, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2653, -6874, 5483, 0, 63, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6370, -7389, 8367, 0, 148, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8272, -7528, 907, 0, -177, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7482, -7716, -4426, 0, 174, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2036, -8249, -3073, 0, -58, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6052, -8229, 85, 0, -95, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_DRAGON_COIN, -10965, -6332, 7178, 0, -37, 0, 0x00000000, bhvDragonCoin),
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
