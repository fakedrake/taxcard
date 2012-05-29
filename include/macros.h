#ifndef _MACROS_H_
#define _MACROS_H_

#define B8(i) ((((i)/10000000)%10)*0x80 + (((i)/1000000)%10)*0x40 + (((i)/100000)%10)*0x20 + (((i)/10000)%10)*0x10 + (((i)/1000)%10)*0x8 + (((i)/100)%10)*0x4 + (((i)/10)%10)*0x2 + (((i)/1)%10))

inline unsigned POW(b,e)
{
	unsigned ret = 1;
	while(e--) ret*=b;
	return ret;
}

#define ATOI(s, e, t) do{						\
		while (s++<e) {						\
			assert( *s<='9'&& *s>='0');			\
			t += (*s & B8(11001111)) * POW(10, exp);	\
		}							\
	}while(0)

#define CAPITAL_LETTER(c) ((c) & B8(11100000) == B8(01000000) )
#define CAPITALIZE(c) ((c) | B8(00100000))

#endif /* _MACROS_H_ */
