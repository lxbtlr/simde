{
  description = "A Nix-flake-based C/C++ development environment";
  inputs.nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.1.*.tar.gz";
  inputs.flake-utils.url = github:numtide/flake-utils;

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let

        name = "SIMDE RISC-V";

        pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        devShells.default = pkgs.mkShell.override {
          # Override stdenv in order to change compiler:
          stdenv = pkgs.clangStdenv;
        }{
          packages = with pkgs; [
            (python314.withPackages (ps: [
            ]))
            gdb
            gcc
            asmjit
            llvmPackages.libstdcxxClang
            clang-tools
            clang
            cmake
            codespell
            conan
            cppcheck
            doxygen
            gtest
            lcov
            vcpkg
            vcpkg-tool
            valgrind
            gnuplot
            #]{ pkgs = nixpkgs.legacyPackages.${system}; };
            ];
        buildInputs = [pkgs.clang-tools];
        shellHook = ''
          export YEL='\033[1;33m'
          export RED='\033[0;31m'
          export NC='\033[0m'

          PATH="${pkgs.clang-tools}/bin:$PATH"
          echo -e "\t\t#$YEL Now in ${name} Shell$NC #"
          git status -s
        '';

          };

      }
    );
}
