void scroll_gfx_mat_bob_dl_Water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_Water_layer5);
	static int interval_tex_bob_dl_Water_layer5 = 2;
	static int cur_interval_tex_bob_dl_Water_layer5 = 2;
	static int interval_tex_bob_dl_Water_layer5_2 = 2;
	static int cur_interval_tex_bob_dl_Water_layer5_2 = 2;

	if (--cur_interval_tex_bob_dl_Water_layer5 <= 0) {
		shift_s(mat, 14, PACK_TILESIZE(0, 1));
		cur_interval_tex_bob_dl_Water_layer5 = interval_tex_bob_dl_Water_layer5;
	}

	if (--cur_interval_tex_bob_dl_Water_layer5_2 <= 0) {
		shift_s_down(mat, 16, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 16, PACK_TILESIZE(0, 1));
		cur_interval_tex_bob_dl_Water_layer5_2 = interval_tex_bob_dl_Water_layer5_2;
	}

};

void scroll_bob() {
	scroll_gfx_mat_bob_dl_Water_layer5();
};
