#-*- coding: utf-8 -*-

import hashlib
import web

class WeixinInterface:


    def GET(self):
        data = web.input()
        signature = data.signature
        timestamp = data.timestamp
        nonce = data.nonce
        echostr = data.echostr

        token = "1q2w3e4r5tqwertyuikfdjsfj239534"
        listp = [token, timestamp, nonce]
        listp.sort()
        sha1 = hashlib.sha1()
        map(sha1.update, listp)
        hashcode = sha1.hexdigest()

        if hashcode == signature:
            return echostr

