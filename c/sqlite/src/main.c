#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
int main(int argc ,char *argv[]){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open("test.db",&db);
    if (rc){
    fprintf(stderr,"Open database failed:%s\n",sqlite3_errmsg(db));
    exit(0);
    }
    else{
    fprintf(stderr,"Open database successfully\n");
    }
    sqlite3_close(db);
    return 0;
}
