// this code is meant to create a child process with fork and wait ,
//  and is expected to run the system commands in the resulting shell


#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>


// char** argumentParser(char *s, size_t *argumentCounter){
//     if(s == NULL)return NULL;
//     char **argumentList = (char **)malloc(50 * sizeof(char*));
//     char *str = NULL;

//     int i = 0;
    
//     int breakIdx  = -1;

//     while(*(s+i)!='\0'){
//         if(!str){
//             str=(char*)malloc(127 * sizeof(char));
//         }else{
//             if(*(s+i)==' ' || *(s+i)=='\0' ){
//                 breakIdx = i;
//                 str[i+1] = '\0';
//                 argumentList[*argumentCounter]=str;
//                 *argumentCounter+=1;
//                 free(str);
//             }else{
//                 str[i-(breakIdx+1)] = *(s+i);  
//             }
//             i++;
//         }
//     }

//     if(str!=NULL){
//         argumentList[*argumentCounter]=str;
//         free(str);
//         *argumentCounter+=1;
//     }
//     return argumentList;
// }
//use strtok

int main(int argc , char *argv[]){
    // 1 create  a child process
    
    for(;;){
        int child_p = fork();
            if(child_p == -1){
                // error exit : process creation failed
            }else if(child_p == 0){
                // run a infinite loop to listen to commands and args
                    char *input_str = (char*)malloc(100 * sizeof(char));
                    if(input_str == NULL){
                        printf("unable to assign memory");
                        exit(-1);
                    }
                
                    if(fgets(input_str,100,stdin) != NULL){
                        const char *reject_str = "\n";
                        strcspn(input_str,reject_str);
                    } 
                
                    // char **argumentList = (char**)malloc(100*sizeof(char*)); 
                    // const char *delim = " ";
                    // char *token = strtok(input_str,delim);

                    // size_t arg_count = 0;
                
                
                    // for(int i = 0 ; token!= NULL ; i++){
                    //     *(argumentList+i) = token;
                    //     ++arg_count;
                    //     token = strtok(NULL,delim);
                    // }
                
                    execl("/bin/sh", "sh" , "-c" ,input_str, (char*)NULL);
                
                    // if(argumentList!=NULL){
                    //     free(argumentList);
                    // }
                
                    if(input_str!=NULL){
                        free(input_str);
                    }
            }else{
                // parent process;
                wait(NULL);
                
            }

    }
}