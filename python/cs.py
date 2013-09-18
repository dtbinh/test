#!/usr/bin/env python

from socket import *
from time import ctime
import threading

HOST = ''
PORT = 21567
BUFSIZE = 1024
ADDR = (HOST, PORT)

def Deal(sck, username):
	while True:
		data = sck.recv(BUFSIZE)
		if data == "quit":
			del clients[username]	
			sck.send(data)
			sck.close()
			break
		for i in  clients.iterkeys():
			if i <> username:
				clients[i].send("[%s] %s: %s" %(ctime(), username, data))
			

chatSerSock = socket(AF_INET, SOCK_STREAM)
chatSerSock.bind(ADDR)
chatSerSock.listen(5)

clients = {}

while True:
	print 'waiting for connection...'
	chatCliSock, addr = chatSerSock.accept()
	print "...connected romt: ", addr
	username = chatCliSock.recv(BUFSIZE)
	print username
	if clients.has_key(username):
		chatCliSock.send("reuse")
		chatCliSock.close()
	else:
		chatCliSock.send("success")
		clients[username] = chatCliSock
		t = threading.Thread(target=Deal, args=(chatCliSock, username))
		t.start()

chatSerSock.close()
