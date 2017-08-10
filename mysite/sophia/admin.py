from django.contrib import admin
from .models import DataDictionary, District, MeanaV11, MeandV11, MeangV11, MeanhV11, CovaV11, GapaV11, School

# Register your models here.
admin.site.register(DataDictionary)
admin.site.register(District)
admin.site.register(MeanaV11)
admin.site.register(MeandV11)
admin.site.register(MeangV11)
admin.site.register(MeanhV11)
admin.site.register(CovaV11)
admin.site.register(GapaV11)
admin.site.register(School)
