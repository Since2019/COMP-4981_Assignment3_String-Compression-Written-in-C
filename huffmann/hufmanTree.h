#ifndef _TYZ_HUFMAN_TREE_H_
#define _TYZ_HUFMAN_TREE_H_

#include "tyz.h"

typedef struct ATTRIBUTE {
	u8 character;
	u32 frequency; 
}ATTRIBUTE;

typedef struct HUFMAN_TREE_NODE {
	boolean visited;
	u8 *hufmanCode;
	u32 leftChild;
	u32 rightChild;
	ATTRIBUTE attribute;
}HUFMAN_TREE_NODE;

ATTRIBUTE *initAttributeList(u8 *str, u32 *ascii, u32 *characterCount);
void destoryAttributeList(ATTRIBUTE *attributeList);
void showAttributeList(u32 characterCount, ATTRIBUTE *attributeList);
HUFMAN_TREE_NODE *initHufmanTreeNode(u32 characterCount, u32 *orientate, ATTRIBUTE *attributeList);
void destoryHufmanTreeNode(u32 count, HUFMAN_TREE_NODE *hufmanTreeNode);
void showHufmanTreeNode(u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
void creatHufmanTree(u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
u32 searchMinimumNode(u32 count, HUFMAN_TREE_NODE *hufmanTreeNode);
void creatHufmanCode(u8 *code, u32 index, u32 root, HUFMAN_TREE_NODE *hufmanTreeNode);
u8 *coding(u8 *str, u32 *orientate, u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
void destoryCode(u8 *hufCode);
u8 *decoding(u8 *hufCode, u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);

#endif
