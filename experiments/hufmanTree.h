#ifndef _TYZ_HUFMAN_TREE_H_
#define _TYZ_HUFMAN_TREE_H_

#include <inttypes.h>

#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

#define SET(value, index)    (value |= 1 << (index ^ 7))
#define CLEAR(value, index)  (value &= ~(1 << (index ^ 7)))
#define GET(value, index)    (((value) & (1 << ((index) ^ 7))) != 0)

typedef unsigned char boolean;
// typedef unsigned int u32;
typedef unsigned short u16;
typedef boolean u8;

int skipBlank(const char *str);
boolean isRealStart(int ch);
boolean isFileExist(const char *filename);
char *creatFilename(const char *sourceFilename, const char *extensionName, char *targetFilename);

typedef struct ATTRIBUTE {
	uint8_t character;
	uint32_t frequency; 
}ATTRIBUTE;

typedef struct HUFMAN_TREE_NODE {
	boolean visited;
	uint8_t *hufmanCode;
	uint32_t leftChild;
	uint32_t rightChild;
	ATTRIBUTE attribute;
}HUFMAN_TREE_NODE;

ATTRIBUTE *initAttributeList(uint8_t *str, uint32_t *ascii, uint32_t *characterCount);
void destoryAttributeList(ATTRIBUTE *attributeList);
void showAttributeList(uint32_t characterCount, ATTRIBUTE *attributeList);
HUFMAN_TREE_NODE *initHufmanTreeNode(uint32_t characterCount, uint32_t *orientate, ATTRIBUTE *attributeList);
void destoryHufmanTreeNode(uint32_t count, HUFMAN_TREE_NODE *hufmanTreeNode);
void showHufmanTreeNode(uint32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
void creatHufmanTree(uint32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
uint32_t searchMinimumNode(uint32_t count, HUFMAN_TREE_NODE *hufmanTreeNode);
void creatHufmanCode(uint8_t *code, uint32_t index, uint32_t root, HUFMAN_TREE_NODE *hufmanTreeNode);
uint8_t *coding(uint8_t *str, uint32_t *orientate, uint32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
void destoryCode(uint8_t *hufCode);
uint8_t *decoding(uint8_t *hufCode, uint32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);

#endif
