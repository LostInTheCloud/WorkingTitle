# WorkingTitle
Dot Matrix Game Emulator

### Requirements:
Debian
```
sudo apt-get update
```
Arch
```
sudo pacman -Syu
```
#### SDL2:
Debian: 
```
sudo apt-get install libsdl2-dev -y
```
Arch
```
sudo pacman -S sdl2 --noconfirm
```
#### Clang (++):
Debian
```
sudo apt-get install clang -y
sudo apt-get install clang++ -y
```
Arch
```
sudo pacman -S clang clang++ --noconfirm
```
### To Compile and Run (Debug):

```bash
cmake -DCMAKE_BUILD_TYPE=Debug .
make
./WorkingTitle
```

### To Compile and Run (Release):

```bash
cmake .
make
./WorkingTitle
```
