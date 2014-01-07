#!/usr/bin/env python
#-*- coding:utf-8 -*-
import os, sys


os.environ['PYTHON_EGG_CACHE'] = '/tmp/.python-eggs'
os.environ['DJANGO_SETTINGS_MODULE'] = 'Cafe.settings'
current_dir = os.path.dirname(__file__)
if current_dir not in sys.path:
    sys.path.append(current_dir)


import django.core.handlers.wsgi
application = django.core.handlers.wsgi.WSGIHandler()
