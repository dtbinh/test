#!/usr/bin/env python
#-*-coding:utf-8-*-


import urllib2, re, os, sys


deepth = 0   #爬虫深度
args = []   #args[1] 是网址 ,args[2]是深度
starturl = "" #初始url
webpage = {}  #爬虫网址
current_deepth = 0 #当前层数
current_url_offset = 0 #当前层网址偏移
current_url = "" #当前处理的网址
result = file('result.txt','w+')

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print "usage:  "+ "python "+ sys.argv[0]+" "+ "[url]"+" "+"[deepth]"  
    args = sys.argv 
    deepth = eval(args[1])
    starturl = args[2]
    if starturl[0:3] != "http":
        starturl = "http://" + starturl
    webpage[0] = list()
    webpage[0].append(starturl)
    
    for i in range(0, deepth): #深度为i遍历url
        webpage[i+1] = []
        current_deepth = i
        for j in range(0, len(webpage[i])): #遍历当前深度第i个url
            current_url_offset = j
            jump = re.search("(gif|jpg|png|zip|exe|rar|css)",webpage[i][j]) #需要跳过的后缀
            if jump != None:
                continue
            try:
                current_url = urllib2.urlopen(webpage[i][j]) 
            except:
                print ("urlopen ERROR : %s", webpage[i][j])
                continue 
            current_url = current_url.readline()
            webpage[i+1] = webpage[i+1] + re.findall("http://[^\<,^\>,^\",^\',^\",^\;]*[^\",^\']",current_url) #匹配url的正则表达式
    
    
    for i in webpage:                 #结果显示并保存
        print >> result, "deepth is %d" % i
        for j in range(0,len(webpage[i])):
            print >> result, webpage[i][j]
    
    result.close()
