/*
 * BitMath.h
 *
 * Created: 08-Dec-20 5:56:23 PM
 *  Author: Jean
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,BitNo) (Reg |= (1 << BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~ (1 << BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1 << BitNo))
#define GetBit(Reg,BitNo) ((Reg >> BitNo) & 1)

#endif /* BITMATH_H_ */