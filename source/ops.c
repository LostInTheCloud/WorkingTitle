#include "main.h"

void OP_NOP(void)
{

}

void OP_LD_BC_D16(void)
{
    BC = *((uint16_t*) (MEM+PC+1));
}