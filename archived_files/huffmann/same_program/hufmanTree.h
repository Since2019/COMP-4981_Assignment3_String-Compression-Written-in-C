#ifndef _TYZ_HUFMAN_TREE_H_
#define _TYZ_HUFMAN_TREE_H_

#include "tyz.h"

typedef struct ATTRIBUTE {
	uin8_t character;
	uin32_t frequency; 
}ATTRIBUTE;

typedef struct HUFMAN_TREE_NODE {
	boolean visited;
	uin8_t *hufmanCode;
	uin32_t leftChild;
	uin32_t rightChild;
	ATTRIBUTE attribute;
}HUFMAN_TREE_NODE;

ATTRIBUTE *initAttributeList(uin8_t *str, uin32_t *ascii, uin32_t *characterCount);
void destoryAttributeList(ATTRIBUTE *attributeList);
void showAttributeList(uin32_t characterCount, ATTRIBUTE *attributeList);
HUFMAN_TREE_NODE *initHufmanTreeNode(uin32_t characterCount, uin32_t *orientate, ATTRIBUTE *attributeList);
void destoryHufmanTreeNode(uin32_t count, HUFMAN_TREE_NODE *hufmanTreeNode);
void showHufmanTreeNode(uin32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
void creatHufmanTree(uin32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
uin32_t searchMinimumNode(uin32_t count, HUFMAN_TREE_NODE *hufmanTreeNode);
void creatHufmanCode(uin8_t *code, uin32_t index, uin32_t root, HUFMAN_TREE_NODE *hufmanTreeNode);
uin8_t *coding(uin8_t *str, uin32_t *orientate, uin32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);
void destoryCode(uin8_t *hufCode);
uin8_t *decoding(uin8_t *hufCode, uin32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode);

#endif
