#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "tyz.h"
#include "hufmanTree.h"

u8 *decoding(u8 *hufCode, u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode) {
	u8 *decode = NULL;
	u32 i;
	u32 index = 0;
	u32 sum = 0;
	u32 father = 2 * characterCount - 2;

	for (i = 0; i < characterCount; i++) {
		sum += hufmanTreeNode[i].attribute.frequency;
	}
	decode = (u8 *) calloc(sizeof(u8), sum);

	for (i = 0; hufCode[i]; i++) {
		if ('0' == hufCode[i]) {
			decode[index++] = hufmanTreeNode[hufmanTreeNode[father].leftChild].attribute.character;
			father = characterCount * 2 - 2;
		} else {
			father = hufmanTreeNode[father].rightChild;
			if (-1 == hufmanTreeNode[father].leftChild) {
				decode[index++] = hufmanTreeNode[father].attribute.character;
				father = characterCount * 2 - 2;
			}
		}
	}
	return decode;
}

void destoryCode(u8 *hufCode) {
	if (NULL == hufCode) {
		return;
	}
	free(hufCode);
}

u8 *coding(u8 *str, u32 *orientate, u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode) {
	u8 *code = NULL;
	u32 i;
	u32 sum = 0;

	for (i = 0; i < characterCount; i++) {
		sum += hufmanTreeNode[i].attribute.frequency * strlen(hufmanTreeNode[i].hufmanCode);
	}
	code = (u8 *) calloc(sizeof(u8), sum);

	for (i = 0; str[i]; i++) {
		strcat(code, hufmanTreeNode[orientate[str[i]]].hufmanCode);
	}
	return code;
}

void creatHufmanCode(u8 *code, u32 index, u32 root, HUFMAN_TREE_NODE *hufmanTreeNode) {
	if (-1 == hufmanTreeNode[root].leftChild) {
		code[index] = 0;
		strcpy(hufmanTreeNode[root].hufmanCode, code);
		return;
	} else {
		code[index] = '0';
		creatHufmanCode(code, index+1, hufmanTreeNode[root].leftChild, hufmanTreeNode);
		code[index] = '1';
		creatHufmanCode(code, index+1, hufmanTreeNode[root].rightChild, hufmanTreeNode);
	}
}

u32 searchMinimumNode(u32 count, HUFMAN_TREE_NODE *hufmanTreeNode) {
	u32 i;
	u32 minIndex = -1;

	for (i = 0; i < count; i++) {
		if (FALSE == hufmanTreeNode[i].visited 
			&& (-1 == minIndex 
		    || hufmanTreeNode[minIndex].attribute.frequency > hufmanTreeNode[i].attribute.frequency)) {
			minIndex = i;
		}
	}
	hufmanTreeNode[minIndex].visited = TRUE;

	return minIndex;
}

void creatHufmanTree(u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode) {
	u32 i;
	u32 leftChild;
	u32 rightChild;
	u32 count = characterCount;

	for (i = 0; i < count - 1; i++) {
		leftChild = searchMinimumNode(count+i, hufmanTreeNode);
		rightChild = searchMinimumNode(count+i, hufmanTreeNode);
		hufmanTreeNode[count+i].visited = FALSE;
		hufmanTreeNode[count+i].hufmanCode = NULL;
		hufmanTreeNode[count+i].leftChild = leftChild;
		hufmanTreeNode[count+i].rightChild = rightChild;
		hufmanTreeNode[count+i].attribute.character = '@';
		hufmanTreeNode[count+i].attribute.frequency = 
					hufmanTreeNode[leftChild].attribute.frequency + 
					hufmanTreeNode[rightChild].attribute.frequency;
	}
}

void showHufmanTreeNode(u32 characterCount, HUFMAN_TREE_NODE *hufmanTreeNode) {
	u32 i;

	printf("char  freq  Lch  Rch  code\n");
	for (i = 0; i < characterCount; i++) {
		printf("%-5c %-5d %-7d %-7d %-10s\n", 
			hufmanTreeNode[i].attribute.character,
			hufmanTreeNode[i].attribute.frequency,
			hufmanTreeNode[i].leftChild,
			hufmanTreeNode[i].rightChild,
			hufmanTreeNode[i].hufmanCode == NULL ? "NULL" : hufmanTreeNode[i].hufmanCode);
	}
}

void destoryHufmanTreeNode(u32 count, HUFMAN_TREE_NODE *hufmanTreeNode) {
	u32 i;

	if (NULL == hufmanTreeNode) {
		return;
	}
	for (i = 0; i < count; i++) {
		free(hufmanTreeNode[i].hufmanCode);
	}
	free(hufmanTreeNode);
}

HUFMAN_TREE_NODE *initHufmanTreeNode(u32 characterCount, u32 *orientate, ATTRIBUTE *attributeList) {
	u32 i;
	u32 nodeCount;
	HUFMAN_TREE_NODE *hufmanTreeNode;

	nodeCount = characterCount * 2 - 1;

	hufmanTreeNode = (HUFMAN_TREE_NODE *) calloc(sizeof(HUFMAN_TREE_NODE), nodeCount);

	for (i = 0; i < characterCount; i++) {
		hufmanTreeNode[i].visited = FALSE;
		hufmanTreeNode[i].hufmanCode = (u8 *) calloc(sizeof(u8), characterCount);
		hufmanTreeNode[i].leftChild = hufmanTreeNode[i].rightChild = -1;
		hufmanTreeNode[i].attribute = attributeList[i];

		orientate[attributeList[i].character] = i;
	}
	return hufmanTreeNode;
}

void showAttributeList(u32 characterCount, ATTRIBUTE *attributeList) {
	u32 i;

	for (i = 0; i < characterCount; i++) {
		printf("频度:%d 符号:%c\n", attributeList[i].frequency, attributeList[i].character);
	}
}

void destoryAttributeList(ATTRIBUTE *attributeList) {
	if (NULL == attributeList) {
		return;
	}
	free(attributeList);
}

ATTRIBUTE *initAttributeList(u8 *str, u32 *ascii, u32 *characterCount) {
	u32 i;
	u32 index = 0;
	u32 count = 0;
	ATTRIBUTE *attributeList;

	for (i = 0; str[i]; i++) {
		ascii[str[i]]++;
	}
	for (i = 0; i < 256; i++) {
		count += (ascii[i] != 0); 
	}
	*characterCount = count;

	attributeList = (ATTRIBUTE *) calloc(sizeof(ATTRIBUTE), count);
	for (i = 0; i < 256; i++) {
		if (ascii[i] != 0) {
			attributeList[index].character = (u8) i;
			attributeList[index++].frequency = ascii[i];
		}
	}
	return attributeList;
}

int main() {
	u8 str[128];
	u8 code[256];
	u8 *hufCode = NULL;
	u8 *decode = NULL;
	u32 ascii[256] = {0};
	u32 orientate[256] = {0};
	u32 characterCount;
	ATTRIBUTE *attributeList = NULL;
	HUFMAN_TREE_NODE *hufmanTreeNode = NULL;

	printf("Your input, please:\n");
	fgets(str,128,stdin);

	attributeList = initAttributeList(str, ascii, &characterCount);
	showAttributeList(characterCount, attributeList);
	
	hufmanTreeNode = initHufmanTreeNode(characterCount, orientate, attributeList);
	creatHufmanTree(characterCount, hufmanTreeNode);
	creatHufmanCode(code, 0, 2*characterCount-2, hufmanTreeNode);
	
	printf("Hufman Tree Below\n");
	showHufmanTreeNode(2*characterCount-1, hufmanTreeNode);

	hufCode = coding(str, orientate, characterCount, hufmanTreeNode);

	printf("Hufman Code Below\n");
	printf("%s\n", hufCode);

	decode = decoding(hufCode, characterCount, hufmanTreeNode);

	printf("Hufman Decode Below\n");
	printf("%s\n", decode);

	destoryCode(hufCode);
	destoryCode(decode);
	destoryAttributeList(attributeList);
	destoryHufmanTreeNode(characterCount, hufmanTreeNode);

	return 0;
}