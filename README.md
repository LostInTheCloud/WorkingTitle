# WorkingTitle
Dot Matrix Game Emulator

### Requirements:
Ubuntu
```
sudo apt-get update
```
Arch
```
sudo pacman -Syu
```
#### SDL2:
Ubuntu: 
```
sudo apt-get install libsdl2-dev -y
```
Arch
```
sudo pacman -S sdl2 --noconfirm
```
#### Clang/Clang++ (gcc/g++ works too):
Ubuntu
```
sudo apt-get install clang clang++ -y
```
Arch
```
sudo pacman -S clang clang++ --noconfirm
```

#### CMake:
Ubuntu
```
sudo apt-get install cmake -y
```
Arch
```
sudo pacman -S cmake --noconfirm
```

### To Compile and Run (Debug):

```bash
cmake -DCMAKE_BUILD_TYPE=Debug .
make
./WorkingTitle <CARTRIDGE_PATH>
```

### To Compile and Run (Release):

```bash
cmake .
make
./WorkingTitle <CARTRIDGE_PATH>
```

### Try this out:

```bash
cmake . 
make
./WorkingTitle ./thirdparty/bgbtest.gb
```