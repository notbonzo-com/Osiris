# Osiris

![Windows](https://github.com/danielkrupinski/Osiris/workflows/Windows/badge.svg?branch=master&event=push)
![Linux](https://github.com/danielkrupinski/Osiris/workflows/Linux/badge.svg?branch=master&event=push)

Cross-platform (Windows, Linux) game hack for **Counter-Strike 2** with GUI and rendering based on game's Panorama UI. Compatible with the latest game update on Steam.

## What's new

* 27 December 2024
    * Added model glow for grenade projectiles

* 14 December 2024
    * Added model glow for defuse kits on the ground

    ![Defuse Kit Model Glow](https://github.com/user-attachments/assets/43dc555d-8c1d-40dc-b94a-3aa8f8396c7b)

* 11 December 2024
    * Added model glow for ticking bomb

    ![Ticking Bomb Model Glow](https://github.com/user-attachments/assets/6cadde5a-f999-4649-b483-9122e7b350ba)

* 3 December 2024
    * Added model glow for dropped bomb

    ![Dropped Bomb Model Glow](https://github.com/user-attachments/assets/a44d2a8e-399c-4638-8aa8-b49fac732c86)

* 2 December 2024
    * Added model glow for weapons on ground

    ![Weapon model glow](https://github.com/user-attachments/assets/ce1b8853-1644-41bd-ab65-0880ff8e4153)

## Technical features

* C++ runtime library (CRT) is not used in release builds
* No heap memory allocations
* No static imports in release build on Windows
* No threads are created
* Exceptions are not used
* No external dependencies

## Compiling

### Prerequisites

#### Windows

* **Microsoft Visual Studio 2022** with **Desktop development with C++** workload

#### Linux

* **CMake 3.24** or newer
* **g++ 11 or newer** or **clang++ 17 or newer**

### Compiling from source

#### Windows

Open **Osiris.sln** in Visual Studio 2022, set build configuration to **Release | x64**. Press *Build solution* and you should receive **Osiris.dll** file.

#### Linux

Configure with CMake:

    cmake -DCMAKE_BUILD_TYPE=Release -B build

Build:

    cmake --build build -j $(nproc --all)

After following these steps you should receive **libOsiris.so** file in **build/Source/** directory.

### Loading / Injecting into game process

#### Windows

You need a **DLL injector** to inject (load) **Osiris.dll** into game process.

Counter-Strike 2 blocks LoadLibrary injection method, so you have to use a manual mapping (aka reflective DLL injection) injector.

**Xenos** and **Extreme Injector** are known to be **detected** by VAC.

#### Linux

You can simply run the following script in the directory containing **libOsiris.so**:

    sudo gdb -batch-silent -p $(pidof cs2) -ex "call (void*)dlopen(\"$PWD/libOsiris.so\", 2)"

However, this injection method might be detected by VAC as gdb is visible under **TracerPid** in `/proc/$(pidof cs2)/status` for the duration of the injection.

## License

> Copyright (c) 2018-2024 Daniel Krupiński

This project is licensed under the [MIT License](https://opensource.org/licenses/mit-license.php) - see the [LICENSE](https://github.com/danielkrupinski/Osiris/blob/master/LICENSE) file for details.
