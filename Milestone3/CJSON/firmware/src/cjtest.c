#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include <string.h>


char * test()
{
	char *out, *in, Rbit;
	cJSON *root, *temp;
	
	root = cJSON_CreateObject();
    
    //input data here
	cJSON_AddStringToObject(root, "Source", "Source Test");
	cJSON_AddStringToObject(root, "MsgType", "MsgType Test");
	cJSON_AddNumberToObject(root, "FSRs", 0b1100000011);
	cJSON_AddStringToObject(root, "Symbol", "Symbol Test");
	cJSON_AddStringToObject(root, "NextLoc", "NextLoc Test");
	cJSON_AddStringToObject(root, "Move", "Move Test");
	cJSON_AddStringToObject(root, "Encoder", "Encoder Test");

    temp = cJSON_CreateNumber(10);
    
    //Get the JSON string string, use cJSON_Print for white space formatting added in
	out = cJSON_PrintUnformatted(root);
	printf("%s\n",out);
	
    
    
	int outlen = strlen(out) + 1; //Add 1 for null terminator '\0'
	//int val = (outlen + 1); 
	//printf("%i\n%i",outlen,val);

	char* t1 = "";
	char t2[2];
	int i;
	for (i = 0; i < outlen; i++)
    {
		printf("%c\n", out[i]);		
		t2[0] = out[i];
		t2[1] = '\0';
		strcat(t1, t2);
    }
	printf("%s\n", t1);

	cJSON_Delete(root);

	while (1) {}

	return in;
}

//Sends the JSON object as a string
void UART_Send(char *out)
{
    int i;
    int outlen = strlen(out) + 1;
	for (i = 0; i < outlen; i++)
    {
        //UART_Send(out[i]) //USE YOUR UART FUNCTION
    }
}

/*//Receives the String not the JSON object
void strApp(char *in, char Rbit) 
{
    char* temp = Rbit;
    strcat(in, temp);
}*/

