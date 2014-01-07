#-*- coding: UTF-8 -*-

import os

import sae
import web

from weixinInterface import WeixinInterface

urls = ('/','Hello',
        '/weixin','WeixinInterface',)

class Hello:
    def GET(self):
        return render.hello("你好")

app_root = os.path.dirname(__file__)
templates_root = os.path.join(app_root, 'templates')
render = web.template.render(templates_root)

app = web.application(urls, globals()).wsgifunc()
application = sae.create_wsgi_app(app)
