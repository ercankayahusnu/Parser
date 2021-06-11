#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// deneme.txt
int main(int argc, char *argv[]) {
	
    char *fileName = malloc(sizeof(char) * 20);
	printf( "Dosya ismini giriniz: ");
	scanf("%s", fileName);
    FILE *file;
    
	file=fopen(fileName, "r"); 
	char *letter;
	
	printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- SOURCE CODE WITH INDENTATION  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n\n");
	
	if(file != NULL){
		
		while (! feof(file)) {
		    letter = fgetc(file);
			printf("%c ", letter);
		}
		
	} else {
		printf("File was not found.");
		return 0;
	}
	
	fclose(file);
	
	printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* SOURCE CODE WITH COMMA -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n\n");
	
	file=fopen(fileName,"r");
	
	if(file != NULL){
		
		printf("{ ");
		
		while( !feof(file) ){
			
		    letter = fgetc(file);
		    
		    if(letter != ' ' && letter != '\n' && letter != EOF) {
		    	printf("%c, ", letter);
			}
		}
		
		printf(" }");
		
	} else {
		printf("File was not found.");
		return 0;
	}
	
	fclose(file);
	
	printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- RESULT OF TOKENILIZER -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n\n");
	
	file=fopen(fileName,"r");
	char ch;
	//char[100][40] words;
	//int ind = 0;
	
	if(file != NULL){
		
		char *previousCharType = "other";
		
		printf("{ ");
		
		while( !feof(file) ){
			
		    ch = fgetc(file);
		    
		    if(ch == ' ' || ch == '  ' || ch == '\n' && letter == EOF) continue;
		    
		    bool isDelimiter = ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' ||  
		                         ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' 
							   );
								  
			bool isOperator = ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' );
		    
		    bool isNumber = ( ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' );		
			
			if(previousCharType == "other"){
				if(isOperator){
					previousCharType = "operator";
					printf(", %c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf(", %c", ch);
				
				} else {
					previousCharType = "other";
					printf("%c", ch);
				}	
			} else if(previousCharType == "operator") {
				if(isOperator){
					previousCharType = "operator";
					printf("%c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf(", %c", ch);
				
				} else {
					previousCharType = "other";
					printf(", %c", ch);
				}
			} else if(previousCharType == "delimiter") {
				if(isOperator){
					previousCharType = "operator";
					printf(", %c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf(", %c", ch);
				
				} else {
					previousCharType = "other";
					printf(", %c", ch);
				}
			} else if(previousCharType == "number") {
				if(isOperator){
					previousCharType = "operator";
					printf(", %c", ch);
					
				} else if(isDelimiter) {
				    previousCharType = "delimiter";
					printf(", %c", ch);
				
				} else if(isNumber) {
					previousCharType = "number";
					printf("%c", ch);
				
				} else {
					previousCharType = "other";
					printf(", %c", ch);
				}
			} 
		}
		
		printf(" }");
		
	} else {
		printf("File was not found.");
	}
	
	
	fclose(file);
	
	file=fopen(fileName,"r");
	
	if(file != NULL){
		
		char *previousChar = "other";
		int paranthesesCount = 0;
		int squareBrackets = 0;
		int curlyBraces = 0;
		bool inNormalParantheses = false;
		int identifierCount = 0;
		int opt = 0;
		int mustBeEquals = false;
		
		while( !feof(file) ){
			
		    ch = fgetc(file);
		    
		    if(ch == ' ' || ch == '  ' || ch == '\n' && letter == EOF) continue;
		    
		    bool isDelimiter = ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == ' ');
			bool isParentheses = ( ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' );
			bool isOperator = ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' );
		    bool isNumber = ( ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' );

		
			if(isParentheses) {
					
					//control of normal parantheses
					if(ch == '('){
						inNormalParantheses = true;
						previousChar = '(';
						paranthesesCount++;
					} else if(ch == ')') {
						inNormalParantheses = false;
						previousChar = ')';
						paranthesesCount--;
					}
					
					//control of normal squareBrackets
					if(ch == '['){
						previousChar = '[';
						squareBrackets++;
					} else if(ch == ']') {
						previousChar = ']';
						squareBrackets--;
					}
					
					//control of normal curlyBraces
					if(ch == '{') {
						previousChar = '{';
						curlyBraces++;
					} else if(ch == '}') {
						previousChar = '}';
						curlyBraces--;
					}
					
					if(paranthesesCount < 0 || squareBrackets < 0 || curlyBraces < 0){
						printf("Parantez hatasý !");
						return;					
					}
					
				} 
		}
		
		printf("\n\n");
				
		if(paranthesesCount != 0 || squareBrackets != 0 || curlyBraces != 0) 
			printf("Kaynak kod gecerli degil! ");
		else
			printf("Kaynak kod gecerli.");
				
	} else {
		printf("File was not found.");
	}
	
	fclose(file);
	
	return 0;
}
