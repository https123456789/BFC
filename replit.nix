{ pkgs }: {
	deps = [
		pkgs.neovim
		pkgs.llvmPackages_9.clangUseLLVM
		pkgs.pstree
		pkgs.nodejs-16_x
	];
}