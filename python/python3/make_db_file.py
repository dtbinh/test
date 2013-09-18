#!/usr/bin/env python
#-*-coding:utf-8-*-

dbfilename = 'people'
ENDDB = 'enddb.'
ENDREC = 'endrec.'
RECSEP = '=>'

def storeDbase(db, dbfilename = dbfilename):
    dbfile = open(dbfilename, 'w')
    for key in db:
        print(key, file = dbfile)
        for (name, value) in db[key].items():
            print(name + RECSEP + repr(value), file = dbfile)
        print(ENDREC, file = dbfile)
    print(ENDDB, file = dbfile)
    dbfile.close()

def loadDbase(dbfilename = dbfilename):
    dbfile = open(dbfilename)
    import sys
    sys.stdin = dbfilename
    db = {}
    key = input()
    while key != ENDDB:
        rec = {}
        field = input()
        while field != ENDREC:
            name, value = field.split(RECSEP)
            rec[name] = eval(value)
            field = input()
        db[key] = REC
        key = input()
    return db

if __name__ == '__main__':
    from initdata import db
    storeDbase(db)
