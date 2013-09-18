#!/usr/bin/env python
# _*_ coding: utf8 _*_

from socket import *
from time import ctime
import threading
from string import split

HOST = ''
PORT = 21567
BUFSIZE = 1024
ADDR = (HOST, PORT)

def Deal(sck, username, room):
	while True:
		data = sck.recv(BUFSIZE)
		for i in  clients[room].iterkeys():
			if i <> username:
				if data <> "quit":
					clients[room][i].send("[%s] %s: %s" %(ctime(), username, data))
				else:
					clients[room][i].send("用户%s在%s退出房间%s" %(username, ctime(), room ))
		if data == "quit":
			del clients[room][username]	
			sck.send(data)
			sck.close()
			break
			

chatSerSock = socket(AF_INET, SOCK_STREAM)
chatSerSock.bind(ADDR)
chatSerSock.listen(5)

clients = {"":{},}

while True:
	print 'waiting for connection...'
	chatCliSock, addr = chatSerSock.accept()
	print "...connected romt: ", addr
	data = chatCliSock.recv(BUFSIZE)
	username, room = split(data)
	print username
	if not clients.has_key(room):
		clients[room] = {}
	if clients[room].has_key(username):
		chatCliSock.send("reuse")
		chatCliSock.close()
	else:
		chatCliSock.send("success")
		clients[room][username] = chatCliSock
		t = threading.Thread(target=Deal, args=(chatCliSock, username, room))
		t.start()

chatSerSock.close()
