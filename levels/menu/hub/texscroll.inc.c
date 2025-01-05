void scroll_hub_000_displaylist_mesh_layer_1_vtx_18() {
	int i = 0;
	int count = 288;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hub_000_displaylist_mesh_layer_1_vtx_18);

	deltaY = (int)(-2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_actor_geo_hub() {
	scroll_hub_000_displaylist_mesh_layer_1_vtx_18();
};
