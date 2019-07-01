- ~~Flags~~

- ~~OPs~~

- Timer

- ~~Interrups~~

- ~~memory regions~~

- ~~PPU research~~

- ~~inline function (inline)~~

- fix clock

    - Alarm - Signal - settimer (setting an alarm)

    - shed wait (yield)

    - rdtscp, rdtsc

    - ~~limit fps by __~~

- ~~rom ausgabe ding~~

- CPU: stop, halt, ..

- boot rom (3)

- ppu
    - substitute generic 0x9000 base address for BG Tiles with actual logic based on the memory flags

    -~~fiFo~~

    - SDL2 
    
        - screen create
        
        - screen update

        - output blocking Vs unblocking (?)
        
    - without palettes for sprites
    
    - without windows
    
    - without blanks
    
    - debug window / info
        
         - ~~Background Tiles/Sprites Output~~

    - sync CPU & PPU: single thread counter imprecise, then clock every picture.

    - ~~fetcher (1)~~

        - test: endless loop  
            manual write tile into middle of screen

        - ~~maybe without fifo~~

    - sync PPU and CPU & get clock fixed (0)

        -   vblank / hblank


- ~~Core dump / restore from dump~~
 
- Profiler (C code analysis tool)   

- input: SDL thread writes into struct, main reads that struct
