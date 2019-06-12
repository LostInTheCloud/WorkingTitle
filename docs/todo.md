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

- boot rom

- ppu

    -FiFo (2)

    - SDL2 
    
        - screen create
        
        - screen update

        - output blocking Vs unblocking (?)
        
    - without palettes for sprites
    
    - without windows
    
    - without blanks
    
    - debug window / info
        
         - Background Tiles/Sprites Output (1)

    - sync CPU & PPU: single thread counter imprecise, then clock every picture.

- Core dump / restore from dump (0)
 
- Profiler    

- input: SDL thread writes into struct, main reads that struct
