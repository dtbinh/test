#include <stdio.h>
#include <string.h>

#define DATA ./data

struct TB;

typedef struct Elemtype {
    char CHAR[20];
    struct Elemtype *next;
} Elemtype;

typedef struct Table_info {
    char *name;
    int key_num;    
    int elem_num;
    struct TB *table;
} Table_info;

typedef struct TB {
    int *key;
    struct Elemtype **elem;
    char *elemname;
} TB;


Table_info *InitTable(char *buf, int num);

int TB_change_name(Table_info *info, char *buf);

int TB_change_attribute (Table_info *info, char *buf , int mode);

int TB_insert_elem (Table_info *info, char *buf, int key, int mode );

int TB_save (Table_info *info ,char *buf);
