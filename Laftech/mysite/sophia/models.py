# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey has `on_delete` set to the desired behavior.
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from __future__ import unicode_literals

from django.db import models


class AuthGroup(models.Model):
    name = models.CharField(unique=True, max_length=80)

    class Meta:
        managed = False
        db_table = 'auth_group'


class AuthGroupPermissions(models.Model):
    group = models.ForeignKey(AuthGroup, models.DO_NOTHING)
    permission = models.ForeignKey('AuthPermission', models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_group_permissions'
        unique_together = (('group', 'permission'),)


class AuthPermission(models.Model):
    name = models.CharField(max_length=255)
    content_type = models.ForeignKey('DjangoContentType', models.DO_NOTHING)
    codename = models.CharField(max_length=100)

    class Meta:
        managed = False
        db_table = 'auth_permission'
        unique_together = (('content_type', 'codename'),)


class AuthUser(models.Model):
    password = models.CharField(max_length=128)
    last_login = models.DateTimeField(blank=True, null=True)
    is_superuser = models.BooleanField()
    username = models.CharField(unique=True, max_length=150)
    first_name = models.CharField(max_length=30)
    last_name = models.CharField(max_length=30)
    email = models.CharField(max_length=254)
    is_staff = models.BooleanField()
    is_active = models.BooleanField()
    date_joined = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'auth_user'


class AuthUserGroups(models.Model):
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)
    group = models.ForeignKey(AuthGroup, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_user_groups'
        unique_together = (('user', 'group'),)


class AuthUserUserPermissions(models.Model):
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)
    permission = models.ForeignKey(AuthPermission, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_user_user_permissions'
        unique_together = (('user', 'permission'),)


class CovaV11(models.Model):
    nces_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(primary_key=True)
    year = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    fips = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stateabb = models.TextField(blank=True, null=True)
    metroid = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    metromicro = models.TextField(blank=True, null=True)
    czid = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    countyid = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    cdcode = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    urban = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pernid = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    perasn = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    perhsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    perblk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    perwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    perfrl = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pernonfrl = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    perell = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    perspeced = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ind = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    asn = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    frl = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    nonfrl = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    totenrl = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    nsch = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ncharters = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ell = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    speced = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    elmgui = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    aides = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    elmtch = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    corsup = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    tottch = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gslo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gshi = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stutch_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stutch_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stutch_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stutch_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    diffstutch_blkwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    diffstutch_hspwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ratstutch_whtblk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ratstutch_whthsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    flunch_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    flunch_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    flunch_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    flunch_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    diffexplch_blkwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    diffexplch_hspwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    percharter_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    percharter_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    percharter_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    percharter_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    hswhtblk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    hswhthsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    hsflnfl = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ppex_tot = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pexp_inst = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pprev_tot = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    totppe_fleslope = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    instppe_fleslope = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    profocc_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    baplus_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    poverty517_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    snap_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    rent_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    singmom_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    samehouse_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    unemp_wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    profocc_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    baplus_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    poverty517_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    snap_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    rent_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    singmom_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    samehouse_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    unemp_hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    profocc_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    baplus_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    poverty517_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    snap_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    rent_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    singmom_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    samehouse_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    unemp_blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    profocc_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    baplus_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    poverty517_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    singmom_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    snap_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    rent_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    samehouse_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    unemp_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pctenglish = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pctforeign = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pctmexico = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pctpuerto = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pctcuba = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pctcentral = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pctsouth = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    inc50all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9010all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9050all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat5010all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    inc50blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9010blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9050blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat5010blk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    inc50hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9010hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9050hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat5010hsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    inc50wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9010wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat9050wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incrat5010wht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    giniall = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    giniwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    giniblk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ginihsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    paredvblkwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    paredvhspwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incvblkwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incvhspwht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    baplus_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    baplus_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pov_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pov_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occbus_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occbus_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occsci_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occsci_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occeduc_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occeduc_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occhealth_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occhealth_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occserv_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occserv_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occsasles_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occsales_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occtrade_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    occtrade_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    inlf_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    inlf_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    unemp_mal = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    unemp_fem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    incvmalfem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    educvmalfem = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    teenbirth_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sesall = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    seswht = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sesblk = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    seshsp = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sesallimp1 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sesallimp2 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    seswhtimp1 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    seswhtimp2 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sesblkimp1 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sesblkimp2 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    seshspimp1 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    seshspimp2 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    def get_fields(self):
        return [(field.name, field.value_to_string(self)) for field in CovaV11._meta.get_fields()]

    class Meta:
        managed = False
        db_table = 'cova_v11'


class DataDictionary(models.Model):
    relation_name = models.CharField(max_length=80, blank=True, null=True)
    source_attribute_name = models.CharField(max_length=30)
    description = models.CharField(max_length=160, blank=True, null=True)
    domain = models.CharField(max_length=50, blank=True, null=True)
    source_organization = models.CharField(max_length=50, blank=True, null=True)
    source_id = models.CharField(max_length=50)
    attribute_name = models.CharField(max_length=50, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'data_dictionary'
        unique_together = (('source_id', 'source_attribute_name'),)


class District(models.Model):
    lea_name = models.TextField(primary_key=True)
    nces_lea_id = models.IntegerField()
    state_lea_id = models.IntegerField()
    city = models.TextField(blank=True, null=True)
    urb_cen_locale_code = models.TextField(blank=True, null=True)
    met_mic_area_code = models.TextField(blank=True, null=True)
    county = models.TextField(blank=True, null=True)
    iu_id = models.IntegerField(blank=True, null=True)
    iu_name = models.TextField(blank=True, null=True)
    latitude = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    longitude = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stateabb = models.TextField(blank=True, null=True)
    fips = models.IntegerField(blank=True, null=True)

    def get_fields(self):
        return [(field.name, field.value_to_string(self)) for field in District._meta.get_fields()]

    class Meta:
        managed = False
        db_table = 'district'
        unique_together = (('nces_lea_id', 'state_lea_id'),)
# Unable to inspect table 'district_old'
# The error was: permission denied for relation district_old



class DjangoAdminLog(models.Model):
    action_time = models.DateTimeField()
    object_id = models.TextField(blank=True, null=True)
    object_repr = models.CharField(max_length=200)
    action_flag = models.SmallIntegerField()
    change_message = models.TextField()
    content_type = models.ForeignKey('DjangoContentType', models.DO_NOTHING, blank=True, null=True)
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'django_admin_log'


class DjangoContentType(models.Model):
    app_label = models.CharField(max_length=100)
    model = models.CharField(max_length=100)

    class Meta:
        managed = False
        db_table = 'django_content_type'
        unique_together = (('app_label', 'model'),)


class DjangoMigrations(models.Model):
    app = models.CharField(max_length=255)
    name = models.CharField(max_length=255)
    applied = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_migrations'


class DjangoSession(models.Model):
    session_key = models.CharField(primary_key=True, max_length=40)
    session_data = models.TextField()
    expire_date = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_session'


class GapaV11(models.Model):
    nces_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(primary_key=True)
    fips = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stateabb = models.TextField(blank=True, null=True)
    year = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gapblk_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gapseblk_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gaphsp_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gapsehsp_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gapblk_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gapseblk_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gaphsp_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gapsehsp_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    racepercent_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    racepercent_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    fipst = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    def get_fields(self):
        return [(field.name, field.value_to_string(self)) for field in GapaV11._meta.get_fields()]

    class Meta:
        managed = False
        db_table = 'gapa_v11'


class MeanaV11(models.Model):
    nces_lea_id = models.IntegerField()
    lea_name = models.TextField(primary_key=True)
    fips = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stateabb = models.TextField(blank=True, null=True)
    year = models.DecimalField(max_digits=65535, decimal_places=65535)
    grade = models.DecimalField(max_digits=65535, decimal_places=65535)
    gstdmn_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gstdmnva_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gstdmn_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    gstdmnva_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    def get_fields(self):
        return [(field.name, field.value_to_string(self)) for field in MeanaV11._meta.get_fields()]

    class Meta:
        managed = False
        db_table = 'meana_v11'
        unique_together = (('nces_lea_id', 'grade', 'year'),)


class MeandV11(models.Model):
    nces_lea_id = models.IntegerField()
    lea_name = models.TextField(primary_key=True)
    fips = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stateabb = models.TextField(blank=True, null=True)
    year = models.DecimalField(max_digits=65535, decimal_places=65535)
    grade = models.DecimalField(max_digits=65535, decimal_places=65535)
    cstdmn_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    cstdmnva_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    cstdmn_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    cstdmnva_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    def get_fields(self):
        return [(field.name, field.value_to_string(self)) for field in MeandV11._meta.get_fields()]

    class Meta:
        managed = False
        db_table = 'meand_v11'
        unique_together = (('nces_lea_id', 'grade', 'year'),)


class MeangV11(models.Model):
    nces_lea_id = models.IntegerField()
    lea_name = models.TextField(primary_key=True)
    fips = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stateabb = models.TextField(blank=True, null=True)
    year = models.DecimalField(max_digits=65535, decimal_places=65535)
    grade = models.DecimalField(max_digits=65535, decimal_places=65535)
    mean_link_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    se_link_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    mean_link_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    se_link_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    def get_fields(self):
        return [(field.name, field.value_to_string(self)) for field in MeangV11._meta.get_fields()]

    class Meta:
        managed = False
        db_table = 'meang_v11'
        unique_together = (('nces_lea_id', 'grade', 'year'),)


class MeanhV11(models.Model):
    nces_lea_id = models.IntegerField()
    lea_name = models.TextField(primary_key=True)
    fips = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    stateabb = models.TextField(blank=True, null=True)
    year = models.DecimalField(max_digits=65535, decimal_places=65535)
    grade = models.DecimalField(max_digits=65535, decimal_places=65535)
    mean_edfa_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    se_edfa_ela = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    mean_edfa_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    se_edfa_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    def get_fields(self):
        return [(field.name, field.value_to_string(self)) for field in MeanhV11._meta.get_fields()]

    class Meta:
        managed = False
        db_table = 'meanh_v11'
        unique_together = (('nces_lea_id', 'grade', 'year'),)


class MrxPrivateSchoolLowPercentage(models.Model):
    state_lea_id = models.IntegerField()
    percent = models.FloatField(blank=True, null=True)
    end_year = models.IntegerField()
    start_year = models.IntegerField()
    school_id = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'mrx_private_school_low_percentage'
        unique_together = (('state_lea_id', 'end_year', 'start_year'),)


class School(models.Model):
    lea_name = models.TextField()
    lea_type = models.TextField()
    nces_lea_id = models.IntegerField(blank=True, null=True)
    lea_id = models.IntegerField()
    county = models.TextField(blank=True, null=True)
    iu_id = models.IntegerField(blank=True, null=True)
    iu_name = models.TextField(blank=True, null=True)
    latitude = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    longitude = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    school_name = models.TextField()
    school_id = models.IntegerField(primary_key=True)
    nces_school_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'school'
        unique_together = (('school_id', 'lea_id'),)
# Unable to inspect table 'school_old'
# The error was: permission denied for relation school_old



class SquadEdproj(models.Model):
    sourceid = models.TextField(blank=True, null=True)
    sourceattributename = models.TextField(blank=True, null=True)
    attributedescription = models.TextField(blank=True, null=True)
    relationname = models.TextField(blank=True, null=True)
    domain = models.TextField(blank=True, null=True)
    classattributename = models.TextField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'squad_edproj'


class SquadMyr(models.Model):
    school_id = models.IntegerField()
    startyear = models.TextField()
    time_period = models.IntegerField()
    total_cohort = models.TextField(blank=True, null=True)
    total_grads = models.TextField(blank=True, null=True)
    male = models.FloatField(blank=True, null=True)
    female = models.FloatField(blank=True, null=True)
    white = models.FloatField(blank=True, null=True)
    hispanic = models.FloatField(blank=True, null=True)
    black = models.FloatField(blank=True, null=True)
    asian = models.FloatField(blank=True, null=True)
    multiracial = models.FloatField(blank=True, null=True)
    americanindianalaskan = models.FloatField(blank=True, null=True)
    specialed = models.FloatField(blank=True, null=True)
    econdisadv = models.FloatField(blank=True, null=True)
    migrant = models.FloatField(blank=True, null=True)
    ell = models.FloatField(blank=True, null=True)
    nativehawaiianpacificislander = models.FloatField(blank=True, null=True)
    endyear = models.TextField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'squad_myr'
        unique_together = (('school_id', 'startyear', 'time_period'), ('school_id', 'startyear', 'time_period'),)


class SquadSources(models.Model):
    source_id = models.IntegerField(blank=True, null=True)
    source_organization = models.TextField(blank=True, null=True)
    short_name = models.TextField(blank=True, null=True)
    source_name = models.TextField(blank=True, null=True)
    source_url = models.TextField(blank=True, null=True)
    last_accessed = models.TextField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'squad_sources'


class SquadTemcoh(models.Model):
    lea_type = models.TextField(blank=True, null=True)
    state_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(blank=True, null=True)
    school_id = models.IntegerField(blank=True, null=True)
    school_name = models.TextField(blank=True, null=True)
    school_type = models.TextField(blank=True, null=True)
    total_grads = models.TextField(blank=True, null=True)
    total_cohorts = models.TextField(blank=True, null=True)
    male = models.FloatField(blank=True, null=True)
    female = models.FloatField(blank=True, null=True)
    white = models.FloatField(blank=True, null=True)
    hispanic = models.FloatField(blank=True, null=True)
    black = models.FloatField(blank=True, null=True)
    americanindianalaskan = models.FloatField(blank=True, null=True)
    multiracial = models.FloatField(blank=True, null=True)
    nativehawaiianpacificislander = models.FloatField(blank=True, null=True)
    asian = models.FloatField(blank=True, null=True)
    econdisadv = models.FloatField(blank=True, null=True)
    migrant = models.FloatField(blank=True, null=True)
    ell = models.FloatField(blank=True, null=True)
    specialed = models.FloatField(blank=True, null=True)
    startyear = models.IntegerField(blank=True, null=True)
    timeperiod = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'squad_temcoh'


class SquadTemgrad(models.Model):
    county = models.TextField(blank=True, null=True)
    state_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(blank=True, null=True)
    school_id = models.IntegerField(blank=True, null=True)
    school_name = models.TextField(blank=True, null=True)
    total_grads = models.TextField(blank=True, null=True)
    total_collegebound = models.FloatField(blank=True, null=True)
    total_collegebound_percent = models.FloatField(blank=True, null=True)
    twofourcollege_year = models.FloatField(blank=True, null=True)
    twofourcollege_year_percent = models.FloatField(blank=True, null=True)
    total_postsecondary_bound = models.FloatField(blank=True, null=True)
    total_postsecondary_bound_percent = models.FloatField(blank=True, null=True)
    ndg_pss = models.FloatField(blank=True, null=True)
    ndg_pss_percent = models.FloatField(blank=True, null=True)
    specialized_degree = models.FloatField(blank=True, null=True)
    specialized_degree_percent = models.FloatField(blank=True, null=True)
    startyear = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'squad_temgrad'


class SquadYrlrat(models.Model):
    school_id = models.IntegerField()
    startyear = models.IntegerField()
    total_grads = models.TextField(blank=True, null=True)
    twofourcollege_year_percent = models.FloatField(blank=True, null=True)
    specialized_degree_percent = models.FloatField(blank=True, null=True)
    total_collegebound_percent = models.FloatField(blank=True, null=True)
    total_ndg_pss_percent = models.FloatField(blank=True, null=True)
    total_postsecondary_percent = models.FloatField(blank=True, null=True)
    endyear = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'squad_yrlrat'
        unique_together = (('school_id', 'startyear'), ('school_id', 'startyear'),)


class Team3Drpout(models.Model):
    school_year = models.TextField()
    county = models.TextField()
    state_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(blank=True, null=True)
    school_id = models.IntegerField(blank=True, null=True)
    school_name = models.TextField()
    lea_type = models.TextField(blank=True, null=True)
    enrollment = models.TextField(blank=True, null=True)
    male_dropouts = models.TextField(blank=True, null=True)
    female_dropouts = models.TextField(blank=True, null=True)
    dropouts = models.TextField(blank=True, null=True)
    dropout_rate = models.TextField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'team3_drpout'


class Team3Edproj(models.Model):
    source = models.TextField(blank=True, null=True)
    name = models.TextField(blank=True, null=True)
    description = models.TextField(blank=True, null=True)
    samplevalue = models.TextField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'team3_edproj'


class Team3Exam(models.Model):
    school_year = models.TextField()
    school_id = models.IntegerField()
    subject = models.TextField()
    student_group = models.TextField()
    grade = models.TextField()
    numscored = models.TextField(blank=True, null=True)
    pct_advanced = models.TextField(blank=True, null=True)
    pct_proficient = models.TextField(blank=True, null=True)
    pct_basic = models.TextField(blank=True, null=True)
    pct_belowbasic = models.TextField(blank=True, null=True)
    growth = models.TextField(blank=True, null=True)
    source = models.TextField()

    class Meta:
        managed = False
        db_table = 'team3_exam'


class TickDistrictFacts(models.Model):
    americanindian_alaskan = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ap_courses = models.IntegerField(blank=True, null=True)
    asian = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    state_lea_id = models.IntegerField()
    avg_yrs_edu_exp_dist = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    avg_yrs_edu_exp_lea = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    avg_yrs_edu_exp_total = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    black = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    career_tech_center_name = models.TextField(blank=True, null=True)
    career_tech_center_website = models.TextField(blank=True, null=True)
    district_add_city = models.TextField(blank=True, null=True)
    district_add_state = models.CharField(max_length=2, blank=True, null=True)
    district_add_street = models.TextField(blank=True, null=True)
    district_add_zipcode = models.TextField(blank=True, null=True)
    district_enrollment = models.IntegerField(blank=True, null=True)
    district_geog_size = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    district_num_career_tech_prog = models.IntegerField(blank=True, null=True)
    dropout_rate = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    econ_disadvtg = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    eng_lang_learner = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    enrollment_career_tech_center = models.IntegerField(blank=True, null=True)
    enrollment_charter_school = models.IntegerField(blank=True, null=True)
    female = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grades_offered = models.TextField(blank=True, null=True)  # This field type is a guess.
    hawaiian_pacific_islander = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    hispanic = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    iu_name = models.TextField(blank=True, null=True)
    iu_website = models.TextField(blank=True, null=True)
    male = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    multiracial = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    num_schools = models.IntegerField(blank=True, null=True)
    pct_classes_high_qual_teachers = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pct_gifted_students = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    school_id = models.IntegerField()
    academic_year_end = models.IntegerField()
    academic_year_start = models.IntegerField()
    special_ed = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    telephone_no = models.TextField(blank=True, null=True)
    website = models.TextField(blank=True, null=True)
    white = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'tick_district_facts'
        unique_together = (('state_lea_id', 'school_id', 'academic_year_end', 'academic_year_start'),)
# Unable to inspect table 'tick_district_fiscal'
# The error was: permission denied for relation tick_district_fiscal



class TickSchoolFacts(models.Model):
    act_english = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    act_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    act_reading = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    act_science = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    americanindian_alaskan = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ap_courses = models.IntegerField(blank=True, null=True)
    asian = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    state_lea_id = models.IntegerField()
    avg_yrs_edu_exp_lea = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    avg_yrs_edu_exp_total = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    black = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    career_tech_center_name = models.TextField(blank=True, null=True)
    career_tech_center_programs = models.TextField(blank=True, null=True)  # This field type is a guess.
    career_tech_center_website = models.TextField(blank=True, null=True)
    dropout_rate = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    econ_disadvtg = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    eng_lang_learner = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    eng_lang_lit_ap = models.NullBooleanField()
    eng_lang_lit_ib = models.NullBooleanField()
    eng_lang_lit_other = models.NullBooleanField()
    female = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grades_offered = models.TextField(blank=True, null=True)  # This field type is a guess.
    grades_pssa_keystone_prof = models.TextField(blank=True, null=True)  # This field type is a guess.
    hawaiian_pacific_islander = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    hispanic = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    iu_name = models.TextField(blank=True, null=True)
    iu_website = models.TextField(blank=True, null=True)
    life_phys_sci_ap = models.NullBooleanField()
    life_phys_sci_ib = models.NullBooleanField()
    life_phys_sci_other = models.NullBooleanField()
    male = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_ap = models.NullBooleanField()
    math_ib = models.NullBooleanField()
    math_other = models.NullBooleanField()
    multiracial = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pct_classes_high_qual_teachers = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pct_gifted_students = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    postsec_articulation_agreements_ins = models.TextField(blank=True, null=True)  # This field type is a guess.
    sat_math = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sat_reading = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sat_writing = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    scholarship_tax_credit_eligi = models.NullBooleanField()
    school_add_city = models.TextField(blank=True, null=True)
    school_add_state = models.CharField(max_length=2, blank=True, null=True)
    school_add_street = models.TextField(blank=True, null=True)
    school_add_zipcode = models.TextField(blank=True, null=True)
    school_enrollment = models.IntegerField(blank=True, null=True)
    school_id = models.IntegerField()
    academic_year_end = models.IntegerField()
    academic_year_start = models.IntegerField()
    social_sci_his_ap = models.NullBooleanField()
    social_sci_his_ib = models.NullBooleanField()
    social_sci_his_other = models.NullBooleanField()
    special_ed = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    telephone_no = models.TextField(blank=True, null=True)
    test_participation_math_algebra = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    test_participation_reading_lit = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    test_participation_sci_bio = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    test_participation_writing = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    title_i_school = models.NullBooleanField()
    website = models.TextField(blank=True, null=True)
    white = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'tick_school_facts'
        unique_together = (('state_lea_id', 'school_id', 'academic_year_end', 'academic_year_start'),)
# Unable to inspect table 'tick_school_fiscal'
# The error was: permission denied for relation tick_school_fiscal



class TickSchoolPerformanceMeasure(models.Model):
    achievement_gap_combined_huf = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    advanced_placement = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ap_above_3_percent = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    attendance_rate = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    attendance_rate_prior_amo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    attendance_rate_reported_amo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    state_lea_id = models.IntegerField()
    calculated_score = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    college_core_areas_offered = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    competency_assessment_percent = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    current_sig = models.TextField(blank=True, null=True)
    ela_lit_annual_growth_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ela_lit_percent_gap_closure_met_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    ela_lit_percent_gap_closure_met_huf = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    esea_progress = models.TextField(blank=True, null=True)
    federal_accountability_desig = models.TextField(blank=True, null=True)
    final_academic_score = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grad_rate_all_amo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grad_rate_cohort = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grad_rate_cohort_4_previous = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grad_rate_cohort_4_prior = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grad_rate_cohort_5_previous = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grad_rate_cohort_5_prior = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grad_rate_cohort_6_previous = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_act_above_22 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_ap_above_3 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_enrollment = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_high_performanceindex = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_on_total_percent = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_plan_num = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_psat_num = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_psat_plan_percent = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_12_sat_above_1550 = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    grade_3_reading_proficiency_percent = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_algebra_all_amo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_algebra_annual_growth_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_algebra_huf_amo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_algebra_percent_gap_closure_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_algebra_percent_proficient = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_algebra_proficient_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    math_algebra_proficient_huf = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    percent_competency_assessment = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    profic_combined_math_reading_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    progress_math_reading_gap_closure = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    progress_math_reading_growth = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    promotion_rate_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    psat_plan_participation = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pssa_percent_math_algebra = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pssa_percent_reading_lit = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pssa_percent_science_bio = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    pssa_percent_writing_advanced = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    reading_lit_all_amo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    reading_lit_annual_growth_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    reading_lit_huf_amo = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    reading_lit_percent_proficient_pssa = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    reading_lit_percent_req_gap_closure_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    reading_lit_proficient_all = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    reading_lit_proficient_huf = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    sat_act_ready_benchmark = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    school_id = models.IntegerField()
    academic_year_end = models.IntegerField()
    academic_year_start = models.IntegerField()
    scibio_annual_growth_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    scibio_percent_proficient_pssa = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    scibio_percent_req_gap_closure_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    spp_score = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    test_participation_math_algebra = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    test_participation_reading_lit = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    writing_annual_growth_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    writing_percent_proficient_pssa = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)
    writing_req_gap_closure_met = models.DecimalField(max_digits=65535, decimal_places=65535, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'tick_school_performance_measure'
        unique_together = (('state_lea_id', 'school_id', 'academic_year_end', 'academic_year_start'),)


class UcPublicLeaRaceBackup(models.Model):
    academic_year_start = models.IntegerField(blank=True, null=True)
    academic_year_end = models.IntegerField(blank=True, null=True)
    state_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(blank=True, null=True)
    lea_type = models.TextField(blank=True, null=True)
    county = models.TextField(blank=True, null=True)
    race = models.TextField(blank=True, null=True)
    pka = models.IntegerField(blank=True, null=True)
    pkp = models.IntegerField(blank=True, null=True)
    pkf = models.IntegerField(blank=True, null=True)
    k4a = models.IntegerField(blank=True, null=True)
    k4p = models.IntegerField(blank=True, null=True)
    k4f = models.IntegerField(blank=True, null=True)
    k5a = models.IntegerField(blank=True, null=True)
    k5p = models.IntegerField(blank=True, null=True)
    k5f = models.IntegerField(blank=True, null=True)
    grade1 = models.IntegerField(blank=True, null=True)
    grade2 = models.IntegerField(blank=True, null=True)
    grade3 = models.IntegerField(blank=True, null=True)
    grade4 = models.IntegerField(blank=True, null=True)
    grade5 = models.IntegerField(blank=True, null=True)
    grade6 = models.IntegerField(blank=True, null=True)
    eug = models.IntegerField(blank=True, null=True)
    grade7 = models.IntegerField(blank=True, null=True)
    grade8 = models.IntegerField(blank=True, null=True)
    grade9 = models.IntegerField(blank=True, null=True)
    grade10 = models.IntegerField(blank=True, null=True)
    grade11 = models.IntegerField(blank=True, null=True)
    grade12 = models.IntegerField(blank=True, null=True)
    sug = models.IntegerField(blank=True, null=True)
    total = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'uc_public_lea_race_backup'


class UcPublicLeaRaceEnrollment(models.Model):
    academic_year_start = models.IntegerField()
    academic_year_end = models.IntegerField()
    state_lea_id = models.IntegerField()
    race = models.TextField()
    pka = models.IntegerField(blank=True, null=True)
    pkp = models.IntegerField(blank=True, null=True)
    pkf = models.IntegerField(blank=True, null=True)
    k4a = models.IntegerField(blank=True, null=True)
    k4p = models.IntegerField(blank=True, null=True)
    k4f = models.IntegerField(blank=True, null=True)
    k5a = models.IntegerField(blank=True, null=True)
    k5p = models.IntegerField(blank=True, null=True)
    k5f = models.IntegerField(blank=True, null=True)
    grade1 = models.IntegerField(blank=True, null=True)
    grade2 = models.IntegerField(blank=True, null=True)
    grade3 = models.IntegerField(blank=True, null=True)
    grade4 = models.IntegerField(blank=True, null=True)
    grade5 = models.IntegerField(blank=True, null=True)
    grade6 = models.IntegerField(blank=True, null=True)
    eug = models.IntegerField(blank=True, null=True)
    grade7 = models.IntegerField(blank=True, null=True)
    grade8 = models.IntegerField(blank=True, null=True)
    grade9 = models.IntegerField(blank=True, null=True)
    grade10 = models.IntegerField(blank=True, null=True)
    grade11 = models.IntegerField(blank=True, null=True)
    grade12 = models.IntegerField(blank=True, null=True)
    sug = models.IntegerField(blank=True, null=True)
    total = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'uc_public_lea_race_enrollment'
        unique_together = (('academic_year_start', 'academic_year_end', 'state_lea_id', 'race'),)


class UcPublicLeaSchoolBackup(models.Model):
    academic_year_start = models.IntegerField(blank=True, null=True)
    academic_year_end = models.IntegerField(blank=True, null=True)
    state_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(blank=True, null=True)
    lea_type = models.TextField(blank=True, null=True)
    county = models.TextField(blank=True, null=True)
    school_id = models.IntegerField(blank=True, null=True)
    school_name = models.TextField(blank=True, null=True)
    pka = models.IntegerField(blank=True, null=True)
    pkp = models.IntegerField(blank=True, null=True)
    pkf = models.IntegerField(blank=True, null=True)
    k4a = models.IntegerField(blank=True, null=True)
    k4p = models.IntegerField(blank=True, null=True)
    k4f = models.IntegerField(blank=True, null=True)
    k5a = models.IntegerField(blank=True, null=True)
    k5p = models.IntegerField(blank=True, null=True)
    k5f = models.IntegerField(blank=True, null=True)
    grade1 = models.IntegerField(blank=True, null=True)
    grade2 = models.IntegerField(blank=True, null=True)
    grade3 = models.IntegerField(blank=True, null=True)
    grade4 = models.IntegerField(blank=True, null=True)
    grade5 = models.IntegerField(blank=True, null=True)
    grade6 = models.IntegerField(blank=True, null=True)
    eug = models.IntegerField(blank=True, null=True)
    grade7 = models.IntegerField(blank=True, null=True)
    grade8 = models.IntegerField(blank=True, null=True)
    grade9 = models.IntegerField(blank=True, null=True)
    grade10 = models.IntegerField(blank=True, null=True)
    grade11 = models.IntegerField(blank=True, null=True)
    grade12 = models.IntegerField(blank=True, null=True)
    sug = models.IntegerField(blank=True, null=True)
    total = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'uc_public_lea_school_backup'


class UcPublicLeaSchoolGenderBackup(models.Model):
    academic_year_start = models.IntegerField(blank=True, null=True)
    academic_year_end = models.IntegerField(blank=True, null=True)
    state_lea_id = models.IntegerField(blank=True, null=True)
    lea_name = models.TextField(blank=True, null=True)
    lea_type = models.TextField(blank=True, null=True)
    county = models.TextField(blank=True, null=True)
    school_id = models.IntegerField(blank=True, null=True)
    school_name = models.TextField(blank=True, null=True)
    gender = models.TextField(blank=True, null=True)
    pka = models.IntegerField(blank=True, null=True)
    pkp = models.IntegerField(blank=True, null=True)
    pkf = models.IntegerField(blank=True, null=True)
    k4a = models.IntegerField(blank=True, null=True)
    k4p = models.IntegerField(blank=True, null=True)
    k4f = models.IntegerField(blank=True, null=True)
    k5a = models.IntegerField(blank=True, null=True)
    k5p = models.IntegerField(blank=True, null=True)
    k5f = models.IntegerField(blank=True, null=True)
    grade1 = models.IntegerField(blank=True, null=True)
    grade2 = models.IntegerField(blank=True, null=True)
    grade3 = models.IntegerField(blank=True, null=True)
    grade4 = models.IntegerField(blank=True, null=True)
    grade5 = models.IntegerField(blank=True, null=True)
    grade6 = models.IntegerField(blank=True, null=True)
    eug = models.IntegerField(blank=True, null=True)
    grade7 = models.IntegerField(blank=True, null=True)
    grade8 = models.IntegerField(blank=True, null=True)
    grade9 = models.IntegerField(blank=True, null=True)
    grade10 = models.IntegerField(blank=True, null=True)
    grade11 = models.IntegerField(blank=True, null=True)
    grade12 = models.IntegerField(blank=True, null=True)
    sug = models.IntegerField(blank=True, null=True)
    total = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'uc_public_lea_school_gender_backup'


class UcPublicSchoolEnrollment(models.Model):
    academic_year_start = models.IntegerField()
    academic_year_end = models.IntegerField()
    school_id = models.IntegerField()
    lea_id = models.IntegerField(blank=True, null=True)
    pka = models.IntegerField(blank=True, null=True)
    pkp = models.IntegerField(blank=True, null=True)
    pkf = models.IntegerField(blank=True, null=True)
    k4a = models.IntegerField(blank=True, null=True)
    k4p = models.IntegerField(blank=True, null=True)
    k4f = models.IntegerField(blank=True, null=True)
    k5a = models.IntegerField(blank=True, null=True)
    k5p = models.IntegerField(blank=True, null=True)
    k5f = models.IntegerField(blank=True, null=True)
    grade1 = models.IntegerField(blank=True, null=True)
    grade2 = models.IntegerField(blank=True, null=True)
    grade3 = models.IntegerField(blank=True, null=True)
    grade4 = models.IntegerField(blank=True, null=True)
    grade5 = models.IntegerField(blank=True, null=True)
    grade6 = models.IntegerField(blank=True, null=True)
    eug = models.IntegerField(blank=True, null=True)
    grade7 = models.IntegerField(blank=True, null=True)
    grade8 = models.IntegerField(blank=True, null=True)
    grade9 = models.IntegerField(blank=True, null=True)
    grade10 = models.IntegerField(blank=True, null=True)
    grade11 = models.IntegerField(blank=True, null=True)
    grade12 = models.IntegerField(blank=True, null=True)
    sug = models.IntegerField(blank=True, null=True)
    total = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'uc_public_school_enrollment'
        unique_together = (('academic_year_start', 'academic_year_end', 'school_id'),)


class UcPublicSchoolGenderEnrollment(models.Model):
    academic_year_start = models.IntegerField()
    academic_year_end = models.IntegerField()
    school_id = models.IntegerField()
    lea_id = models.IntegerField(blank=True, null=True)
    gender = models.TextField()
    pka = models.IntegerField(blank=True, null=True)
    pkp = models.IntegerField(blank=True, null=True)
    pkf = models.IntegerField(blank=True, null=True)
    k4a = models.IntegerField(blank=True, null=True)
    k4p = models.IntegerField(blank=True, null=True)
    k4f = models.IntegerField(blank=True, null=True)
    k5a = models.IntegerField(blank=True, null=True)
    k5p = models.IntegerField(blank=True, null=True)
    k5f = models.IntegerField(blank=True, null=True)
    grade1 = models.IntegerField(blank=True, null=True)
    grade2 = models.IntegerField(blank=True, null=True)
    grade3 = models.IntegerField(blank=True, null=True)
    grade4 = models.IntegerField(blank=True, null=True)
    grade5 = models.IntegerField(blank=True, null=True)
    grade6 = models.IntegerField(blank=True, null=True)
    eug = models.IntegerField(blank=True, null=True)
    grade7 = models.IntegerField(blank=True, null=True)
    grade8 = models.IntegerField(blank=True, null=True)
    grade9 = models.IntegerField(blank=True, null=True)
    grade10 = models.IntegerField(blank=True, null=True)
    grade11 = models.IntegerField(blank=True, null=True)
    grade12 = models.IntegerField(blank=True, null=True)
    sug = models.IntegerField(blank=True, null=True)
    total = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'uc_public_school_gender_enrollment'
        unique_together = (('academic_year_start', 'academic_year_end', 'school_id', 'gender'),)
