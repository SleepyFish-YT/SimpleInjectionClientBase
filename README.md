# Simple Injection Client Base for Lunar 1.8.9

This is a simple Lunar Client injection cheat base written in C++ and built with CMake.

## Getting Started

To get started with this project, you'll need to have the following software installed:

- [CLion](https://www.jetbrains.com/clion/)
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/community/) (for the toolchain)

### Visual Studio 2022 Installation Requirements

When installing Visual Studio 2022, make sure to select the following components:

#### Workloads:
- Universal Windows Platform development

#### Individual Components:
- MSVC v143 - VS 2022 C++ x64/x86 build tools (v14.38-17.8)
- MSVC v143 - VS 2022 C++ x64/x86 build tools (Latest)
- Windows 11 SDK (10.0.22621.0)
- C++ CMake tools for Windows
- IntelliCode

Once you have CLion and the required components installed:

1. Open CLion and optionally install any plugins you're familiar with from IntelliJ, as they may also be available for CLion.
2. Go to `Settings` → `Build, Execution, Deployment` → `Toolchains`.
3. Click on the `+` button, select `Visual Studio`, and choose your Visual Studio installation path.
4. Under `Toolchains`, click on `CMake`, then click the `+` button twice to generate both `Debug` and `Release` configurations.
5. Select the `Release` configuration and ensure the `Toolchain` is set to `Visual Studio`.

### Usage

To use the client base, build the executable and inject it using your preferred injector.

## Discord Server

Join our community on Discord:

<a href="https://discord.gg/7JXXvkufJK"><img src="https://invidget.switchblade.xyz/7JXXvkufJK" alt="Discord Invite Link"/></a>

###### Signed by SleepyFish.
