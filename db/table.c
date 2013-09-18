#include "table.h"

Table_info *InitTable(char *buf,int num){
    int i;
    Table_info *info = (Table_info *) malloc (sizeof(Table_info));
    info->table = (TB *) malloc (sizeof(TB));
    info->name = (char *) malloc (sizeof(char)*20);
    strcpy(info->name , buf);
    info->elem_num = 0;
    info->key_num = 0;
    info->table->key = (int *) malloc (sizeof(int)*num);
    for (i = 0; i < num; i++) {
        info->table->key[i] = i + 1;
    }
    info->table->elem = (Elemtype **) malloc(sizeof(Elemtype *)*num);
    info->table->elemname = (char *) malloc (sizeof(char)*20);
    return info;
};

int TB_change_name (Table_info *info,char *buf) {
    strcpy(info->name , buf);
    if (strcmp (info->name, buf) == 0)
        return 0;
    else {
        printf("change table name failed\n");
        return -1;
    }
};

int TB_change_attribute (Table_info *info, char *buf, int mode) {
    if (mode == 0) {
        int i;
        info->elem_num++;
        strcpy(info->table->elemname, buf);
        return 0;
    }
}

int TB_insert_elem(Table_info *info, char *buf, int key, int mode) {
    int key_num = info->key_num;
    int i;
    if (mode == 0) {   /*append mode*/
        info->table->elem[key_num] = (Elemtype *) malloc (sizeof(Elemtype));
        strcpy(info->table->elem[key_num]->CHAR, buf);
        info->key_num++;
        return 0;
    } 
}


int TB_save (Table_info *info, char *buf) {
    FILE *fd = fopen (buf, "wb+");
    int key_num = info->key_num;
    int i;
        fwrite (&info->key_num, sizeof(int), 1, fd);
        fwrite (&info->name, sizeof(char), 20, fd);
        fwrite (&info->table->elemname, sizeof(char), 20,fd);
    for (i = 0; i < key_num; i++) {
        fwrite (&info->table->key[i], sizeof(int), 1, fd);
        fwrite (&info->table->elem[i]->CHAR, sizeof(char), 20, fd);
    }
    fclose (fd);
    return 0;
}

int TB_load (Table_info *info, char *buf) {
    FILE *fd = fopen (buf, "rb+");
    int key_num, i;
    TB_insert_elem (info, "\0", 0, 0);
    fread(&info->key_num, sizeof(int), 1, fd);
    key_num = info->key_num;
    fread(&info->name, sizeof(char), 20, fd);
    fread(&info->table->elemname, sizeof(char), 20,fd);
    for (i = 0; i < key_num; i++) {
        fread (&info->table->key[i], sizeof(int), 1, fd);
        fread (&info->table->elem[i]->CHAR, sizeof(char), 20,fd);
    }
    fclose (fd);
    return 0;
}




int main () {
    char *s = "baimochen";

    Table_info *DB_info = InitTable(s, 10000);
    TB_change_name(DB_info, "wbmc");
    printf ("%d\n", DB_info->key_num);
    TB_change_attribute (DB_info, "name", 0);
    printf ("%s\n", DB_info->table->elemname);
    TB_insert_elem(DB_info,"baimochen",0, 0);
    printf ("%s\n", DB_info->table->elem[0]->CHAR);
    TB_save(DB_info, "./bak");

    Table_info *x = InitTable (s, 10000);
    TB_load (x, "./bak");


}

/*int main () {
    char *s = "baimochen";
    Table_info *DB_info = InitTable (s, 10000);
    TB_insert_elem(DB_info,"baimochen",0, 0);
    TB_load (DB_info, "./bak");
    
    printf ("%d\n", DB_info->key_num);
    printf ("%s\n", DB_info->table->elemname);
    printf ("%s\n",DB_info->table->elem[0]->CHAR);
}*/
