from django.http import HttpResponse
from django.template import loader
from django.shortcuts import render

from .models import DataDictionary, District, MeanaV11, MeandV11, MeangV11, MeanhV11, CovaV11, GapaV11, School

from .forms import DistrictForm, SchoolForm, DistrictsForm, DistrictssForm

#Home page
def index(request):
	template = loader.get_template('sophia/index.html')
    	return HttpResponse(template.render())

#Select information page
def selection(request):

	print("HELLOOOOOOOOOO, WORK YOU SONOFABITCH    ", request.POST)

	if request.method == 'Post':

		print "Here 1"
		ddd_form = DistrictssForm(request.POST)
		dd_form = DistrictsForm(request.POST)

		if dd_form.is_valid():

			print form.errors

			return HttpResponseRedirect('sophia/tables')

	elif request.method == 'Post' and 'd_submit' in request.POST:

		print "Here 2"
		d_form = DistrictForm(request.POST)

		if d_form.is_valid():
			return HttpResponseRedirect('sophia/table')
	
	elif request.method == 'Post' and 's_submit' in request.POST:

		print "Here 3"
		s_form = SchoolForm(request.POST)

		if s_form.is_valid():
			return HttpResponseRedirect('sophia/table')
	else:
		print "Here 4"
		s_form = SchoolForm()
		d_form = DistrictForm()
		dd_form = DistrictsForm()
		ddd_form = DistrictssForm()

	return render(request, 'sophia/selection.html', {'d_form': d_form, 's_form': s_form, 'dd_form': dd_form, 'ddd_form': ddd_form})

#Display available information
def table(request):
	
	try:

		name_d = request.POST.get("district", "false")#.upper()

		name_s = request.POST.get("school", "false")#.upper()

		#district

		if name_d != "false":

			#get information from all the tables
			district = District.objects.get(lea_name = name_d)
			meanaV11 =  MeanaV11.objects.filter(lea_name = name_d)
			meandV11 = MeandV11.objects.filter(lea_name = name_d)
			meangV11 = MeangV11.objects.filter(lea_name = name_d)
			meanhV11 = MeanhV11.objects.filter(lea_name = name_d)
			covaV11 = CovaV11.objects.filter(lea_name = name_d)
			gapaV11 = GapaV11.objects.filter(lea_name = name_d)

		#school

		#if name_s != "false":

			#school = School.objects.get(school_name = name_s)


	except District.DoesNotExist:

		raise Http404("Name Does not exist")

	return render(request, 'sophia/table.html', {'district': district,  'meanaV11': meanaV11, 'meandV11': meandV11, 'meangV11': meangV11, 'meanhV11': meanhV11, 'covaV11': covaV11, 'gapaV11': gapaV11 })

#Display available information
def tables(request):
	
	try:

		name_ddd = request.POST.get("districtss", "false")#.upper()

		name_dd = request.POST.get("districts", "false")#.upper()

		#district

		if name_ddd !='false' and name_dd != "false":

			#get information from all the tables
			districts = District.objects.get(lea_name = name_ddd)
			meanaV11 =  MeanaV11.objects.filter(lea_name = name_ddd)
			meandV11 = MeandV11.objects.filter(lea_name = name_ddd)
			meangV11 = MeangV11.objects.filter(lea_name = name_ddd)
			meanhV11 = MeanhV11.objects.filter(lea_name = name_ddd)
			covaV11 = CovaV11.objects.filter(lea_name = name_ddd)
			gapaV11 = GapaV11.objects.filter(lea_name = name_ddd)

			districts1 = District.objects.get(lea_name = name_dd)
			meanaV111 =  MeanaV11.objects.filter(lea_name = name_dd)
			meandV111 = MeandV11.objects.filter(lea_name = name_dd)
			meangV111 = MeangV11.objects.filter(lea_name = name_dd)
			meanhV111 = MeanhV11.objects.filter(lea_name = name_dd)
			covaV111 = CovaV11.objects.filter(lea_name = name_dd)
			gapaV111 = GapaV11.objects.filter(lea_name = name_dd)


	except District.DoesNotExist:

		raise Http404("Name Does not exist")

	return render(request, 'sophia/tables.html', {'districts': districts,  'meanaV11': meanaV11, 'meandV11': meandV11, 'meangV11': meangV11, 'meanhV11': meanhV11, 'covaV11': covaV11, 'gapaV11': gapaV11, 'districts1': districts1,  'meanaV111': meanaV111, 'meandV111': meandV111, 'meangV111': meangV111, 'meanhV111': meanhV111, 'covaV111': covaV111, 'gapaV111': gapaV111  })
