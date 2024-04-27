#include "src/game/envfx_snow.h"

const GeoLayout hub_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_CULLING_RADIUS(500),
		GEO_OPEN_NODE(),
			GEO_SHADOW(0, 180, 240),
			GEO_OPEN_NODE(),
				GEO_SWITCH_CASE(2, geo_switch_anim_state),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_FORCE, hub_000_displaylist_mesh_layer_0),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hub_000_displaylist_mesh_layer_5),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, hub_000_displaylist_mesh_layer_1),
						GEO_DISPLAY_LIST(LAYER_ALPHA, hub_000_displaylist_mesh_layer_4),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
