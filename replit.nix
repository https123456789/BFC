{ pkgs }: {
    deps = [
        pkgs.openssh_with_kerberos
        pkgs.nasm
        pkgs.neovim
        pkgs.llvmPackages_9.clangUseLLVM
        pkgs.pstree
        pkgs.nodejs-16_x
        pkgs.git-filter-repo
    ];
}