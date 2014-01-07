#-*- coding: utf-8 -*-

import hashlib
import web
import lxml
import time
import os
import urllib2, json
from lxml import etree

class WeixinInterface:

    def __init__(self):
        self.app_root = os.path.dirname(__file__)
        self.templates_root = os.path.join(self.app_root, 'templates')
        self.render = web.template.render(self.templates_root)

    def GET(self):
        data = web.input()
        signature = data.signature
        timastamp = data.timestamp
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

