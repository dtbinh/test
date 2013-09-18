#!/usr/bin/env python
# _*_ coding: utf8 _*_

from socket import *
from time import ctime
import threading
import random
from sys import argv, exit, stdout
from getopt import gnu_getopt, GetoptError




help_info = ["cs.py [ -h | --help | -u | --username] username",
	"\t-h or --help\t显示帮助信息",
	"\t-u or --username\指定用户名",
	"\t-r or --room\t指定房间",
    "\tCopyright By Baimochen\t"]
def help():
	for i in help_info:
		print i



def Send(sck, test):
	while True:
		data = raw_input('>')
		sck.send(data)
		if  data == "quit":
			break
def Recieve(sck, test):
	while True:
		data = sck.recv(BUFSIZ)
		if data == "quit":
			sck.close()
			break
		str = "\n" + data + "\n>" 
		stdout.write(str)

HOST = 'localhost'
PORT= 21567
BUFSIZ = 1024
ADDR = (HOST, PORT)
threads = []

if __name__ == "__main__":
	# 解析命令行参数
	try:
		opts, args = gnu_getopt(argv[1:], "hu:r:", ["help", "username=", "room="])		
	except GetoptError, err:
		print str(err)
		help()
		exit(2)
	username = ""
	room = ""
	for o, a in opts:
		if o in ("-h", "--help"):
			help()
			exit(0)
		elif o in ("-u", "--username"):
			username = a
		elif o in ("-r", "--room"):
			room = a
		else:
			print "未知选项"
			help()
			exit(2)
	if not username or not room:
		help()
		exit(2)
	chatCliSock = socket(AF_INET, SOCK_STREAM)
	chatCliSock.connect(ADDR)
	chatCliSock.send("%s %s" %(username, room))
	data = chatCliSock.recv(BUFSIZ)
	if data == "reuse":
		print "用户%s已登录房间%s" %(username, room)
		raw_input()
		exit(1)
	elif data == "success":
		print "用户%s成功登录房间%s" %(username, room)
		t = threading.Thread(target=Send, args = (chatCliSock, None))
		threads.append(t)
		t = threading.Thread(target=Recieve, args = (chatCliSock, None))
		threads.append(t)
		for i in range(len(threads)):
			threads[i].start()
		threads[0].join()

