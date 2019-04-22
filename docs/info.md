# GameBoy

*compendium based on Game Boy CPU Manual by DP*

## Hardware

### Memory

|||
|:---:|:---:|
Interrupt Enable Regs | 0xffff
Internal RAM | 0xff80
empty | 0xff4c
I/O | 0xff00
empty | 0xfea0
OAM | oxfe00
echo | 0xe000
8kB Internal RAM | 0xc000
8kB switchable RAM bank | 0xa000
8kB VRAM | 0x8000
16kB switchable ROM bank | 0x4000
16 kB ROM bank #0 | 0x0000

#### echo

```// todo: find out why this exists```

#### reserved memory

`0000` Restart, called by `RST`  
...

`0040` vertical blank interrupt start addr

`0050` timer overflow interrupt start addr

`0058` serial transfer completion interrupt start addr

`0100` ... `0103` entry point (?) of cart

`0104` ... `0133` scrolling Nintendo graphic, needs to be as is, otherwise program will not start

`0134` ...`0142` Title

`0143` ... if `80`, it's a GBColor, otherwise without colour support

`0144` and `0145` license code

`0146` `03` signals SGB support

`0147` Cartridge type

`0148` ROM size

`0149` RAM size

`014a` 0 for Japanese, 1 for non Japanese

`014b` license code

`014d` complement check !!!

`014e` ... `014f` checksum, ignored by gameboy ???

### Cartridge Types

...

### Special Modes

#### Power Up

`0`... `255` are being executed

- showing logo and comparing with trademark

- checking checksums

- internal RAM is random on startup

- cart RAM is also random on startup

#### Stop Mode 