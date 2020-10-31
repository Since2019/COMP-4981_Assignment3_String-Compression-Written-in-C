#ifndef _TYZ_H_
#define _TYZ_H_

#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

#define SET(value, index)    (value |= 1 << (index ^ 7))
#define CLEAR(value, index)  (value &= ~(1 << (index ^ 7)))
#define GET(value, index)    (((value) & (1 << ((index) ^ 7))) != 0)

typedef unsigned char boolean;
typedef unsigned int u32;
typedef unsigned short u16;
typedef boolean u8;

int skipBlank(const char *str);
boolean isRealStart(int ch);
boolean isFileExist(const char *filename);
char *creatFilename(const char *sourceFilename, const char *extensionName, char *targetFilename);

#endif