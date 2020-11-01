#include <stdio.h>
#include <string.h>
// #include <malloc.h>
#include <unistd.h>
#include <fcntl.h> 
#include "hufmanTree.h"
#include <stdlib.h>



/**
  * Freee the memory.
  * @param hufCode : the one you want to delete
  */
void destoryCode(uint8_t *hufCode) {
	if (NULL == hufCode) {
		return;
	}
	free(hufCode);
}

/**
  *  @param : the string you want to code
  *  @param : u
  */
uint8_t *coding(uint8_t *str, uint32_t *orientate, uint32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode) {
	uint8_t *code = NULL;
	uint32_t i;
	uint32_t sum = 0;

	for (i = 0; i < characterCount; i++) {
		sum += hufmanTreeNode[i].attribute.frequency * strlen(hufmanTreeNode[i].hufmanCode);
	}
	code = (uint8_t *) calloc(sizeof(uint8_t), sum);

	for (i = 0; str[i]; i++) {
		strcat(code, hufmanTreeNode[orientate[str[i]]].hufmanCode);
	}
	return code;
}

/**
  * @param code : The code array
  * @param index : which code it is?
  * @param hufmanTreeNode : Struct
  */
void creatHufmanCode(uint8_t *code, uint32_t index, uint32_t root, HUFMAN_TREE_NODE *hufmanTreeNode) {
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

/**
  * Necessary Algo logic
  * @param count: number of counts
  * @param huffmanTreeNode :HUFMAN_TREE_NODE structure.  
  */
uint32_t searchMinimumNode(uint32_t count, HUFMAN_TREE_NODE *hufmanTreeNode) {
	uint32_t i;
	uint32_t minIndex = -1;


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

void creatHufmanTree(uint32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode) {
	uint32_t i;
	uint32_t leftChild;
	uint32_t rightChild;
	uint32_t count = characterCount;

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

void showHufmanTreeNode(uint32_t characterCount, HUFMAN_TREE_NODE *hufmanTreeNode) {
	uint32_t i;

	fprintf(stderr,"char  freq  Lch  Rch  code\n");
	for (i = 0; i < characterCount; i++) {
		fprintf(stderr,"%-5c %-5d %-7d %-7d %-10s\n", 
			hufmanTreeNode[i].attribute.character,
			hufmanTreeNode[i].attribute.frequency,
			hufmanTreeNode[i].leftChild,
			hufmanTreeNode[i].rightChild,
			hufmanTreeNode[i].hufmanCode == NULL ? "NULL" : (char*) hufmanTreeNode[i].hufmanCode);
	}
}

void destoryHufmanTreeNode(uint32_t count, HUFMAN_TREE_NODE *hufmanTreeNode) {
	uint32_t i;

	if (NULL == hufmanTreeNode) {
		return;
	}
	for (i = 0; i < count; i++) {
		free(hufmanTreeNode[i].hufmanCode);
	}
	free(hufmanTreeNode);
}

HUFMAN_TREE_NODE *initHufmanTreeNode(uint32_t characterCount, uint32_t *orientate, ATTRIBUTE *attributeList) {
	uint32_t i;
	uint32_t nodeCount;
	HUFMAN_TREE_NODE *hufmanTreeNode;

	nodeCount = characterCount * 2 - 1;

	hufmanTreeNode = (HUFMAN_TREE_NODE *) calloc(sizeof(HUFMAN_TREE_NODE), nodeCount);

	for (i = 0; i < characterCount; i++) {
		hufmanTreeNode[i].visited = FALSE;
		hufmanTreeNode[i].hufmanCode = (uint8_t *) calloc(sizeof(uint8_t), characterCount);
		hufmanTreeNode[i].leftChild = hufmanTreeNode[i].rightChild = -1;
		hufmanTreeNode[i].attribute = attributeList[i];

		orientate[attributeList[i].character] = i;
	}
	return hufmanTreeNode;
}

void showAttributeList(uint32_t characterCount, ATTRIBUTE *attributeList) {
	uint32_t i;

	for (i = 0; i < characterCount; i++) {
		printf("freq:%d character:%c\n", attributeList[i].frequency, attributeList[i].character);
	}
}

void destoryAttributeList(ATTRIBUTE *attributeList) {
	if (NULL == attributeList) {
		return;
	}
	free(attributeList);
}

ATTRIBUTE *initAttributeList(uint8_t *str, uint32_t *ascii, uint32_t *characterCount) {
	uint32_t i;
	uint32_t index = 0;
	uint32_t count = 0;
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
			attributeList[index].character = (uint8_t) i;
			attributeList[index++].frequency = ascii[i];
		}
	}
	return attributeList;
}





  int read_input_bytes(uint8_t* byte_content){
     
    uint8_t* buffer = malloc(sizeof(uint8_t)*2); //each 12 bit code  
	

    size_t index = 0; //keep track of how many code words are there
    size_t ret;       //see if the read() has reach its end. 


   
    while(1){
		
        byte_content = (uint8_t*) realloc(byte_content, (index*1 + 3)*sizeof(uint8_t) );
		

        // read 8 bits(one byte) per time.
        ret = read(STDIN_FILENO,buffer,1);
        if(ret == 0)
            break;

        // put the read stuff into the byte_content.
        byte_content[index] = buffer[0];
		// fprintf(stderr,"%c",buffer[0]);
        ++index;
        
    }
    // The buffer ends.
    byte_content[index]='\0';

    return index;
}





int main() {
	// uint8_t str[128];
	uint8_t code[256];
	uint8_t *hufCode = NULL;

	uint32_t ascii[256] = {0};
	uint32_t orientate[256] = {0};
	uint32_t characterCount;
	ATTRIBUTE *attributeList = NULL;
	HUFMAN_TREE_NODE *hufmanTreeNode = NULL;


	
	// make a fd input read() for str
	// 
	// 
	// 

	uint8_t* input_bytes_content = malloc(sizeof(uint8_t)*10);;
	fprintf(stderr,"Your input, please:\n");
	// fgets(str,128,stdin); //Encoding part
	read_input_bytes(input_bytes_content);
	

	

	




	// attributeList = initAttributeList(str, ascii, &characterCount);
	attributeList = initAttributeList(input_bytes_content, ascii, &characterCount);


	

	showAttributeList(characterCount, attributeList);
	
	hufmanTreeNode = initHufmanTreeNode(characterCount, orientate, attributeList);
	creatHufmanTree(characterCount, hufmanTreeNode);
	creatHufmanCode(code, 0, 2*characterCount-2, hufmanTreeNode);
	

	fprintf(stderr,"Hufman Tree Below\n");
	showHufmanTreeNode(2*characterCount-1, hufmanTreeNode);

    // hufCode = coding(str, orientate, characterCount, hufmanTreeNode); // Encoding:
	hufCode = coding(input_bytes_content, orientate, characterCount, hufmanTreeNode);
	

	fprintf(stderr,"Hufman Code Below\n");
	fprintf(stderr,"%s", hufCode);


	// We later need to change this to outputting in real bits. 
	//
	//
	//It's printing out to the file..
	printf("%s", hufCode);



	//Release Memory
	destoryCode(hufCode);

	destoryAttributeList(attributeList);
	destoryHufmanTreeNode(characterCount, hufmanTreeNode);

	return 0;
}
