from django.shortcuts import render, render_to_response
from django.template import RequestContext
from django.conf.urls import patterns
from Cafe_search import adminn as admin

from Cafe_search.models import person, group, event, clue

class ClueReviewAdmin(admin.ModelAdmin):
    review_template = 'admin/review.html'
    
    def get_urls(self):
        urls = super(ClueReviewAdmin, self).get_urls()
        my_urls = patterns('',
                (r'\d+/review/$', self.admin_site.admin_view(self.review)),
                )
        return my_urls + urls

    def review(self, request):
        rawid = int(request.path.split('/')[3])
        form = self.get_form(request)
        clueobj = clue.objects.get(pk=rawid)
        persons = clueobj.cluePerson.all()
        groups = clueobj.clueGroup.all()
        events = clueobj.clueEvent.all()
        b =  {
            'clueIdenty':clueobj.clueIdenty,
            'clueTime': clueobj.clueTime,
            'clueSource': clueobj.clueSource,
        }
        
        return render_to_response(self.review_template, {
            'persons': persons , 
            'events': events,
            'groups': groups,
            'clueIdenty':clueobj.clueIdenty,
            'clueTime': clueobj.clueTime,
            'clueSource': clueobj.clueSource,
            }, context_instance = RequestContext(request))

