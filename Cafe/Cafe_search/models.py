#-*- coding:utf-8 -*-
from django.db import models
from django.utils.html import format_html


# Create your models here.

class person(models.Model):
    isCapital = models.CharField(max_length = 4, verbose_name = u'是否涉京', choices = (('Y',u'涉京'), ('N',u'非涉京')) )
    name = models.CharField(max_length = 128, verbose_name = u'姓名',)
    sex = models.CharField(max_length = 8, verbose_name = u'性别', choices =(('F',u'女'),('M',u'男')))
    hometown = models.CharField(max_length = 256, verbose_name = u'籍贯', blank = True)
    idType = models.CharField(max_length = 8, verbose_name = u'证件类型', choices = (('shen',u'身份证'),('hu',u'护照'),('gang',u'港澳通行证'),('qian',u'签证')), default = ('身份证',u'身份证'))
    idNum = models.CharField(max_length = 64, verbose_name = u'证件号码')
    huji = models.CharField(max_length = 256, verbose_name = u'户籍所在地', blank = True)
    livingPlace = models.CharField(max_length = 256, verbose_name = u'现住址', blank = True)
    working = models.CharField(max_length = 256, verbose_name = u'工作单位', blank = True)
    contact = models.CharField(max_length = 64, verbose_name = u'通讯方式', blank = True)

    def __unicode__(self):
        return self.name

    class Meta:
        verbose_name = u"涉及人员信息"
        verbose_name_plural = u"涉及人员信息"
        unique_together = (("idType", "idNum"),)

class event(models.Model):
    eventNote = models.TextField( verbose_name = u"事件信息")
    eventTime = models.CharField( verbose_name = u"发生时间", default = 'YYYY-MM-DD', max_length = '16')
    eventPlace = models.CharField(max_length = 256, verbose_name = u"发生地点", blank = True)
    eventPerson = models.CharField(max_length = 256, verbose_name = u"涉及人员", blank = True)
    eventResult = models.CharField(max_length = 256, verbose_name = u"处理结果", blank = True)
    eventOnline = models.CharField(max_length = 256, verbose_name = u"网络信息", blank = True)
    eventAlien = models.CharField(max_length = 256, verbose_name = u"涉外信息", blank = True)

    def __unicode__(self):
        return self.eventNote

    class Meta:
        verbose_name = u"涉及事件信息"
        verbose_name_plural = u"涉及事件信息"


class group(models.Model):
    groupName = models.CharField(max_length = 128, verbose_name = u"组织名称")
    groupNote = models.TextField(max_length = 512, verbose_name = u"备注", blank = True)

    def __unicode__(self):
        return self.groupName

    class Meta:
        verbose_name = u"涉及组织相关信息"
        verbose_name_plural = u"涉及组织相关信息"


class clue(models.Model):
    clueTime = models.CharField(max_length = 16, verbose_name = u"线索时间", default = u"YYYY-MM-DD")
    clueIdenty = models.CharField(max_length = 64, verbose_name = u"线索文号")
    clueSource = models.CharField(max_length = 1024, verbose_name = u"线索来源" , blank = True)
    cluePerson = models.ManyToManyField(person, blank = False, verbose_name = u"涉及人员")
    clueEvent = models.ManyToManyField(event, blank = False, verbose_name = u"涉及事件")
    clueGroup = models.ManyToManyField(group, blank = True, verbose_name = u"涉及组织")

    def join_person(self):
        name_list = []
        for obj in self.cluePerson.all():
            name_list.append(format_html(u'<a href="/Cafe_search/person/{0}/">{1}</a>', obj.id,obj.name))
        return ','.join(name_list)

    def join_event(self):
        id_list = []
        for obj in self.clueEvent.all():
            id_list.append(format_html(u'<a href="/Cafe_search/event/{0}/">{1}</a>', obj.id, obj.eventTime))
        return ','.join(id_list)

    def join_show(self):
        id_list = []
        return format_html(u'<a href="/Cafe_search/clue/{0}/review"><b>显示</b></a><a href="/Cafe_search/clue/{0}/">&nbsp;<b>修改</b></a>', self.id, self.id)


    def join_group(self):
        id_list = []
        for obj in self.clueGroup.all():
            id_list.append(format_html(u'<a href="/Cafe_search/group/{0}/">{1}</a>', obj.id, obj.groupName))
        return ','.join(id_list)

    join_person.short_description = u"涉及人员"
    join_person.allow_tags = True
    join_event.short_description = u"涉及事件"
    join_event.allow_tags = True
    join_group.short_description = u"涉及组织"
    join_group.allow_tags = True
    join_show.short_description = u"可选项"
    join_show.allow_tags = True
        
        
        

    def __unicode__(self):
        return self.clueIdenty

    class Meta:
        verbose_name = u"线索信息"
        verbose_name_plural = u"线索信息"

