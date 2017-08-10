from django import forms

class DistrictForm(forms.Form):
    district = forms.CharField(label='District', max_length=100, widget=forms.TextInput(attrs={'class': 'ui-autocomplete-input', 'autocomplete': 'off'}))

class SchoolForm(forms.Form):
    school = forms.CharField(label='School', max_length=100)

class DistrictsForm(forms.Form):
    districts = forms.CharField(label='Districts', max_length=100, widget=forms.TextInput(attrs={'class': 'ui-autocomplete-input', 'autocomplete': 'off'}))

class DistrictssForm(forms.Form):
    districtss = forms.CharField(label='Districtss', max_length=100, widget=forms.TextInput(attrs={'class': 'ui-autocomplete-input', 'autocomplete': 'off'}))
