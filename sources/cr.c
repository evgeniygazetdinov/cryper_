
const char LOWERCASE_ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
const char UPPERCASE_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



int find_position(char for_find, char* current_case){
    for(int i=0;i<len(sizeof(LOWERCASE_ALPHABET)); i++){
        if(LOWERCASE_ALPHABET[i] == for_find){
            *current_case = "lower";
            return i;
        }
    }
    for(int i=0;i<len(sizeof(UPPERCASE_ALPHABET)); i++){
        if(UPPERCASE_ALPHABET[i] == for_find){
            *current_case = "upper";
            return i;
        }
    }
}



void crypt(){

}
void decript(){

}
