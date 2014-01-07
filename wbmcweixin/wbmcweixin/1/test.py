import web
from weixinInterface import WeixinInterface


urls = ("/", 'index',
        "/weixin","WeixinInterface",)

class index:
    def GET(self):
        return "hello , world"

if __name__ == '__main__':

    app = web.application(urls, globals())
    app.run()
