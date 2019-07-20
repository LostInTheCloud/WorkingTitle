# GameBoy

*compendium based on Game Boy CPU Manual by DP*

## Hardware

### Memory

| | |
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
16 kB ROM bank #0 | 0x0000```// todo: find out about the upper bound of interrupt enable regs```

#### echo

A copy of the 8kB internal *(? check this)* RAM  
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

```// todo```

### Special Modes

#### Power Up

`0`... `255` are being executed

- showing logo and comparing with trademark

- checking checksums

- internal RAM is random on startup

- cart RAM is also random on startup

#### Stop Mode 

Halts the CPU and displays a white screen (GB) until a button is pressed

#### Low-Power Mode

`HALT` instruction stopping the system clock and suspending the CPU, until interrupt. In *disabled interrupts (DI)* mode the instruction after the `HALT` is skipped on GB, not though on the GBC in GB mode (`0x0143` = `0x00`), so better follow up with a NOP.   
```// todo: more detail```

### Video

#### Tiles

- 32x32 Tiles (à 8x8)

- 256x256 pixels Buffer

- 160x144 pixels displayed

- `SCROLLX` and `SCROLLY` contain coordinates

- Background Tile Map

- Window

```// todo: add more detail on draing, background, scrolling, window timings etc```

#### Sprites

- up to 40 sprites

- up to 10 per line (vertical ?)

- 8x8 or 8x16

```// todo: add more detail on priority, coordinates etc```

```// todo: especially consider the SPRITE RAM BUG```

### Sound

- two channels

- multiple patterns can be mixed

```// todo: more detail```

### Timer

With the Timer Counter interrupts can be achieved after defined time windows

```// todo: understand the code and exact functionality```

### Serial I/O

```// todo```

### Interrupts

Interupt:

-   push PC onto stack   

-   jump to interrupt instructions

```// todo: detail```

#### Some Interrupts

-   V-Blank

    -   59.7Hz

    -   at begin of v-blank period

    -   roughly 1.1 ms long period *(? check on this)*

    -   VRAM may be accessed

-   LCDC Status

    -   ```// todo```

-   Timer Overflow

    -   when `TIMA`/`0xFF05` overflows

-   Serial Transfer Completion

    -   descriptive name, duh

-   High to Low of P10-P13

    -   button presses

    -   ```// todo: more detail```

### Special Registers

