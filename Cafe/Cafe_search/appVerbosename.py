#-*- coding:utf-8 -*-

from functools import wraps
def rename_app_list(func):
    m = {'Sites':'Web sites',
         'Auth':'帐号管理',
         'Cafe_Search':'数据库',
            }

    @wraps(func)
    def _wrapper(*args, **kwargs):
        response = func(*args, **kwargs)
        app_list = response.context_data.get('app_list')

        if app_list is not None:
            for a in app_list:
                name = a['name']
                a['name'] = m.get(name, name)
        title = response.context_data.get('title')

        if title is not None:
            app_label = title.split(' ')[0]
            if app_label in m:
                response.context_data['title'] = "%s管理" % m[app_label]
        return response
    return _wrapper
