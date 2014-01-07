#-*- coding:utf-8 -*-

from Cafe_search.models import clue, person, event, group
#from django.contrib import admin
from Cafe_search import adminn as admin
from Ie.admin import ImportExportMixin
from Cafe_search import appVerbosename
from Cafe_search.views import ClueReviewAdmin
class personAdmin(ImportExportMixin,admin.ModelAdmin):
    list_display = ('name','sex', 'livingPlace','working','idType')
    search_fields =('name', 'hometown', 'idNum', 'huji', 'livingPlace', 'working', 'contact') 
    ordering = ('name','sex','livingPlace','working','idType')
    list_filter = ('sex','idType','isCapital')



class eventAdmin(ImportExportMixin,admin.ModelAdmin):
    list_display = ('eventNote','eventTime','eventPerson','eventPlace','eventResult','eventOnline','eventAlien')
    search_fields = ('eventNote','eventTime','eventPlace','eventPerson','eventResult','eventOnline','eventAlien')
    ordering = ('eventTime','eventPerson')

class groupAdmin(ImportExportMixin,admin.ModelAdmin):
    list_display = ('groupName', 'groupNote')
    search_fields = ('groupName','groupNote')
    ordering = ('groupName','groupNote')

class clueAdmin(ImportExportMixin,admin.ModelAdmin):
    list_display = ('clueIdenty','clueTime','join_person','join_event','join_group', 'join_show',)
    search_fields = ('clueTime','clueIdenty','cluePerson__name','cluePerson__hometown',
            'cluePerson__idNum','cluePerson__huji','cluePerson__livingPlace',
            'cluePerson__working','cluePerson__contact','clueEvent__eventNote',
            'clueEvent__eventTime','clueEvent__eventPlace','clueEvent__eventResult',
            'clueEvent__eventOnline','clueEvent__eventAlien','clueGroup__groupName','clueGroup__groupNote',)
    filter_horizontal = ('cluePerson','clueEvent','clueGroup',)

admin.site.__class__.index = appVerbosename.rename_app_list(admin.site.__class__.index)
admin.site.__class__.app_index = appVerbosename.rename_app_list(admin.site.__class__.app_index)
    
admin.site.register(clue, clueAdmin)
admin.site.register(person, personAdmin)
admin.site.register(event,eventAdmin)
admin.site.register(group,groupAdmin)

# Register your models here.
