from django.conf.urls import url

from . import views

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^selection/', views.selection, name='selection'),
    url(r'^tables/', views.tables, name='tables'),
    url(r'^table/', views.table, name='table'),
]
