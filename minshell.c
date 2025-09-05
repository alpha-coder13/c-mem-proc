// this code is meant to create a child process with fork and wait ,
//  and is expected to run the system commands in the resulting shell


#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>

char** argumentParser(char *s){
    char **argumentList = (char *)malloc(50);
    char *str = NULL;

    int i = 0;
    int argumentCounter = 0;
    int breakIdx  = 0;
    while(s!=NULL && *(s+i)!='\0'){
        if(!str){
            str=(char)malloc(127);
        }else{

            if(*(s+i)==' '){
                breakIdx = i;
                str[i+1] = '\0';
                argumentList[argumentCounter++]=str;
                str =NULL;
            }else{
                str[i-(breakIdx+1)] = *(s+i);  
            }
            i++;
        }
    }

    if(str!=NULL){
        argumentList[argumentCounter++]=str;
        str = NULL;
    }



    return argumentList;
}


int main(int argc , char *argv[]){
    // 1 create  a child process
    // int child_p = fork();
    // if(child_p == -1){
    //     // error exit : process creation failed
    // }else if(child_p == 0){
    //     // run a infinite loop to listen to commands and args
    //      for(;;){
    //         // take a line in input:
    //         // assume arg 0 as the program 
    //      }
    // }else{
    //     // parent process;
    // }
    char *s;
    scanf("%s",s);
    char **argumentList = argumentParser(s);
    printf("%ld",sizeof(argumentList)/sizeof(char*));
    for(int i = 0 ; i< sizeof(argumentList)/sizeof(char*) ; i++){
        printf("%s\n",*(argumentList+i));
    }
    return 0;
}