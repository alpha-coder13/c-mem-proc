#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//  get memory pool custom priorto runTime
// free allocator

#ifndef MEM_SIZE
    #define MEM_SIZE (10*8)  // 1 MB
#endif
typedef  struct Memalloc Memalloc;
typedef  struct String String;

 struct Memalloc{
    char* ptr ;
    char* start;
} ;

struct String{
    char *pointer;
    int size ;
} ;

void allocate(char *s,String* st , Memalloc *ref){

    int i = 0;
    st->pointer = ref->ptr;
    while(*(s+i) !='\0' && (ref->ptr - ref->start) <= MEM_SIZE){
        *(ref->ptr) = *(s+i);
        ref->ptr++;
        i++;
    }
    *(ref->ptr) = '\0';
    i++;
    ref->ptr++;
    st->size = i;
    return ;
}

void readString(String* st){
    printf("%s\n",st->pointer);
    return;
}

void releaseMemory(String* st){
    int i =0 ;
    while(i <= st->size){
        *(st->pointer + (i++)) = '\0';
    }

    printf("%s","memory freed");
}

void showAllMemBlocks(Memalloc *ref){
    int i =0;
    while(i < MEM_SIZE){
        printf("%p : %c\n",(ref->start+i), *(ref->start + i));
       i++;
    }
    return;
}
void releaseStringPoolMem(Memalloc *ref){
    if(ref->start!= NULL){
        free(ref->start);
        printf("memory released from custom allocator");
    }
    return;
}

void main(int argc,  char *argv[]){
    if(argc == 1){
        printf("usage : .\\a.exe <string name> ");
        return;
    }
    if(argc > 1 && strcmp(argv[1], "--help") == 0){
            printf("pass the string to be allocated as a argument");
            return;
    }

    
    Memalloc mem ;
    mem.start = (char*)malloc((size_t)MEM_SIZE);
    if(mem.start == NULL){
        printf("unable to allocate memory");
    }
    mem.ptr = mem.start;
    char *s = argv[1];

    for(int i = 0 ; i < 4 ; i++){
        String st;
        allocate(s,&st,&mem);
        readString(&st);

        if(i == 2){
            printf("here");
            releaseMemory(&st);
        }
    }

    showAllMemBlocks(&mem);
    releaseStringPoolMem(&mem);
    return;
}



