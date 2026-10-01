{
  description = "Flake for developing control systems";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { nixpkgs, ... }: {
    devShells = builtins.mapAttrs (system: pkgs: {
      default = pkgs.mkShell {
        name = "ctrl-play";

        buildInputs = with pkgs; [
          mujoco
          glfw
          wayland
          pkg-config

          clang
          clang-tools
          lldb

          cmake
          neocmakelsp
        ];
      };
    }) nixpkgs.legacyPackages;
  };
}
