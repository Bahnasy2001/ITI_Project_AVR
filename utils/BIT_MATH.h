/*
 * BIT_MATH.h
 *
 * Created: 8/25/2023 10:47:25 AM
 *  Author: Pc
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TOG_BIT(REG,BIT) REG^=(1<<BIT)
#define READ_BIT(REG,BIT) (REG>>BIT)&1

#define REG_SET(REG) REG|=0xFF
#define REG_CLR(REG) REG&=0x00
#define REG_TOG(REG) REG^=REG
#define REG_READ(REG) REG&=0xFF
#define REG_WRT(REG,NUM) REG = NUM



#endif /* BIT_MATH_H_ */