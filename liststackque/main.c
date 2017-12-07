//
//  main.c
//  liststackque
//
//  Created by 津田準 on 2017/12/01.
//  Copyright © 2017 津田準. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "error.h"

typedef long ELEM;

#define STACK_SIZE 100
#define QUEUE_SIZE 100

ELEM stack[STACK_SIZE];
//スタックの要素数
int n;

ELEM queue[QUEUE_SIZE];
//キューの先頭
int front;
//キューの末尾
int rear;
//キューに入っているある要素の、次の要素の添え字を求める
#define next(a) (( (a) + 1 ) % QUEUE_SIZE)

struct CELL{
    struct CELL *next;
    struct CELL *prev;
    long value;
};
//連結リストの先頭
struct CELL header;

//スタック
void init(){
    n = 0;
}

void push(ELEM x){
    if(n >= STACK_SIZE)
        error("stack overflow\n");
     stack[n++] = x;
}

ELEM pop(){
    if(n <= 0)
        error("stack underflow\n");
    return stack[--n];
}

int empty(){
    return n == 0;
}

//キュー
void init_queue(){
    front = rear = 0;
}

void enqueue(ELEM x){
    if(next(rear) == front)
        error("que overflow\n");
    queue[rear] = x;
    rear = next(rear);
}

ELEM dequeue(){
    ELEM x;
    
    if(front == rear)
        error("queue underflow\n");
    x = queue[front];
    front = next(front);
    return x;
}

int empty_quque(){
    return front == rear;
}

//連結リスト
//struct CELL* makeCell(int value, struct CELL* next, struct CELL* prev){
//    struct CELL* cell;
//
//    cell = malloc(sizeof(struct CELL));
//    if(cell == NULL){
//        return NULL;
//    }else{
//        cell -> value = value;
//        cell -> next = next;
//        cell -> prev = prev;
//        return cell;
//    }
//}

//int prependCell(int value){
//    struct CELL* prepend = makeCell(value, NULL, NULL);
//    if (prepend == NULL)
//        return 0;
//    prepend -> next = header;
//    header = prepend;
//    return 1;
//}
//
//int appendCell(int value){
//    struct CELL* append = makeCell(value, NULL, NULL);
//    struct CELL* current;
//    if(append == NULL)
//        return 0;
//    current = header;
//    while(current -> next != NULL){
//        current = current -> next;
//    }
//    current -> next = append;
//    append -> prev = current;
//    return 1;
//}

//int deleteCell(int number){
//    struct CELL* p;
//    if(number == 1){
//        p = header;
//        header = header -> next;
//        header -> prev = NULL;
//        free(p);
//    }else if(number > 1){
//        struct CELL* current = header;
//        for(int i = 2; i <= number-1 ;i++ ){
//            current = current -> next;
//            if(current -> next == NULL)
//                error("The cell doesn't exist\n");
//        }
//        p = current -> next;
//        current -> next = p -> next;
//        if(current -> next != NULL){
//            struct CELL* currentpl = current -> next;
//            currentpl -> prev = current;
//        }
//        free(p);
//    }
//    return 1;
//}

int insert(long value){
    struct CELL *p, *new;
    new = malloc(sizeof(struct CELL));
    p = &header;
    while( 1 ){
        if(p -> next == &header)
            break;
        if(value < p -> next -> value)
            break;
        p = p -> next;
    }
    new -> prev = p;
    new -> next = p -> next;
    new -> value = value;
    p ->next -> prev = new;
    p ->next = new;

    return 1;
}

int delete(int number){
    struct CELL *current, *p;
    current = &header;
    for(int i = 1; i < number; i++){
        if(current -> next == &header)
            error("the cell doesnt exists\n");
        current = current -> next;
        
    }
    p = current -> next;
    if(p == NULL)
        error("the cell doesnt exist\n");
    current -> next = p -> next;
    free(p);
    return 1;
}

void printList(){
    struct CELL *p;
    for( p = header.next; p != &header; p = p -> next){
        printf("%ld\n", p -> value );
    }
}



int main(int argc, const char * argv[]) {
    //while文のフラグに使われる変数
    int flg = 1;
    //連結リストがすでに存在するかどうかをチェック
    int check = 1;
    
    while( flg ){
        
        int a = 0;
        printf("スタック : 1\n");
        printf("キュー : 2\n");
        printf("リスト : 3\n");
        printf("終了 : 4\n");
        scanf("%d", &a);
        switch( a ){
            case 1:
                a = 0;
                printf("スタックに積む : 1\n");
                printf("スタックから取り出す : 2\n");
                printf("スタックを初期化 : 3\n");
                scanf("%d", &a);
                if( a == 1){
                    int flg = 1;
                    while( flg ){
                        int a = 0;
                        printf("数字を入力 : 1\n");
                        printf("終了 : 2\n");
                        scanf("%d", &a );
                        if( a == 1){
                            int a = 0;
                            printf("好きな数字を入力してください\n");
                            scanf("%d", &a );
                            push(a);
                            printf("スタックに数字が積まれました\n");
                        }else if( a == 2){
                            flg = 0;
                        }else{
                            
                        }
                    }
                }else if( a == 2){
                    int flg = 1;
                    while( flg ){
                        int a = 0;
                        printf("数字を取り出す : 1\n");
                        printf("終了 : 2\n");
                        scanf("%d", &a );
                        if( a == 1){
                            long x = pop();
                            printf("取り出した数字は%ldです\n", x);
                        }else if( a == 2){
                            flg = 0;
                        }else{
                            
                        }
                    }
                }else if( a == 3 ){
                    init();
                    printf("スタックが初期化されました\n");
                }else{
                    
                }
                break;
            case 2:
                a = 0;
                printf("キューに積む : 1\n");
                printf("キューから取り出す : 2\n");
                printf("キューを初期化 : 3\n");
                scanf("%d", &a);
                if( a == 1 ){
                    int flg = 1;
                    while( flg ){
                        int a = 0;
                        printf("数字を入力 : 1\n");
                        printf("終了 : 2\n");
                        scanf("%d", &a );
                        if( a == 1){
                            int a = 0;
                            printf("好きな数字を入力してください\n");
                            scanf("%d", &a );
                            enqueue(a);
                            printf("キューに数字が入りました\n");
                        }else if( a == 2){
                            flg = 0;
                        }else{
                            
                        }
                    }
                }else if(a == 2){
                    int flg = 1;
                    while( flg ){
                        int a = 0;
                        printf("数字を取り出す : 1\n");
                        printf("終了 : 2\n");
                        scanf("%d", &a );
                        if( a == 1){
                            long x = dequeue();
                            printf("取り出した数字は%ldです\n", x);
                        }else if( a == 2){
                            flg = 0;
                        }else{
                            
                        }
                    }
                    
                }else if(a == 3){
                    init_queue();
                    printf("キューが初期化されました\n");
                }else{
                    
                }
                break;
            case 3:
                a = 0;
                printf("セルをインサート : 1\n");
                printf("リストを一覧表示 : 2\n");
                printf("セルを削除 : 3\n");
                scanf("%d", &a);
                if( a == 1 ){
                    int flg = 1;
                    while( flg ){
                        int a = 0;
                        printf("数字を入力 : 1\n");
                        printf("終了 : 2\n");
                        scanf("%d", &a);
                        if( a == 1){
                            int b;
                            printf("好きな数字を入力してください\n");
                            scanf("%d", &b );
                            if( check == 1 ){
                                header.next = &header;
                                header.prev = &header;
                                header.value = 0;
                                insert(b);
                                check = 0;
                            }else{
                                insert(b);
                            }
                            printf("セルがインサートされました\n");
                        }else if( a == 2){
                            flg = 0;
                        }else{
                            
                        }
                    }
                }else if(a == 2){
                    printf("リストに入っているデータは以下の通りです\n");
                    printList();
                }else if(a == 3){
                    int a = 0;
                    printf("好きな数字を入力してください\n");
                    scanf("%d", &a);
                    delete(a);
                    printf("a番目の数字が削除されました。\n");
                }else{
                    
                }
                break;
            case 4:
                flg = 0;
                break;
            default:
                flg = 1;
        }
    }
    
    return 0;
}
