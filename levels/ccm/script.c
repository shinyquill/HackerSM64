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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x00, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x02, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x06, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x07, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x08, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_CASTLE_COURTYARD, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0x64, LEVEL_CASTLE_COURTYARD, 0x01, 0x64, WARP_NO_CHECKPOINT),
		WARP_NODE(0x66, LEVEL_CASTLE_COURTYARD, 0x01, 0x66, WARP_NO_CHECKPOINT),
		WARP_NODE(0x34, LEVEL_CASTLE_COURTYARD, 0x01, 0x34, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_DRAGON_COIN, -779, 384, 1344, 0, 180, 0, 0x00000000, bhvDragonCoin),
		OBJECT(MODEL_RED_COIN, 153, 199, -1194, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_NONE, -783, -36, -876, 0, 180, 0, 0x01000000, bhvHiddenDragonCoin),
		OBJECT(MODEL_RED_COIN, 628, 199, -1194, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 1015, 199, -1194, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 1364, 199, -1194, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 153, 199, -754, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 628, 199, -754, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 1015, 199, -754, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_COIN, 1364, 199, -754, 0, 180, 0, 0x00000000, bhvHiddenRedCoin),
		OBJECT(MODEL_RED_CIRCLE, -798, 635, 216, 0, 180, 0, 0x000A0000, bhvRedRing),
		OBJECT(MODEL_NONE, -785, 299, 786, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 180, -785, 299, 786),
		OBJECT(MODEL_NONE, -785, 607, 786, 0, 180, 0, 0x00F1000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -785, 607, 786, 0, 180, 0, 0x00F0000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_STAR, 1014, 1989, 873, 0, 180, 0, 0x000A0000, bhvStar),
		OBJECT(MODEL_NONE, 862, 299, 5230, 0, 180, 0, 0x0064000, bhvPaintingDeathWarp),
		OBJECT(MODEL_NONE, 862, 299, 5230, 0, 180, 0, 0x0032000, bhvPaintingStarCollectWarp),
		OBJECT(MODEL_NONE, 2330, 299, 3837, 0, -90, 0, 0x0066000, bhvPaintingDeathWarp),
		OBJECT(MODEL_NONE, 2330, 299, 3837, 0, -90, 0, 0x0034000, bhvPaintingStarCollectWarp),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, -785, 299, 786),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
