import os
import sys
import glob
import argparse
import json
import time

def parse_args():
    parser = argparse.ArgumentParser(description="This script fetches analysis events and writes a file with timestamps.")
    parser.add_argument("--basedir",required=False,help="ref/alt allele file used for input",default="/mnt/production_storage/sequencing/ops/admin/workflow_central/2016")
    parser.add_argument("--dockermessagedir",required=False,help="directory with json messages from the docker wrapper",default="/mnt/production_storage/sequencing/ops/admin/workflow_central/automation_messages/docker/incoming")
    parser.add_argument("--output_filename",required=False,help="output prefix for tool results; defaults to timestamps.tsv",default="timestamps.tsv")
    args = parser.parse_args()
    
    return args

def find_docker_messages_with_error(path):
    results = []
    for filename in glob.glob(os.path.join(path,"*.docker_wrapper.json")):
        doc = json.loads(file(filename,"rb").read())
        if not doc.has_key("update") or not doc["update"] == "docker_wrapper_stop":
            continue
        command = doc["command"]
        time = reformat_timestr(doc["timestamp"])
        result=doc["exit_code"]
        image=doc["image"]
        exitcode = doc["exit_code"]
        if exitcode != "1":
            continue # only show errors
        image = image.replace("rd-serv.amdx.local:5000/","")
        results.append([time,image,exitcode,command])
    return results

def reformat_timestr(timestr):
    t=time.strptime(timestr,"%a %b %d %H:%M:%S %Z %Y")
    return "%s-%s-%sT%s:%s:%s" % (t.tm_year,t.tm_mon,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec)
        
def get_fc_and_cat_and_date_for_gwr(path):

    category = "gwr"

    log = os.path.join(path, "pyflow.data","logs","pyflow_log.txt")
    cmdline = None
    for line in open(log,"rb"):
        if line.find("ProcessCmdLine") > -1:
            cmdline = line
            break
        
    if cmdline == None:
        fc = "error"
        time = "error"
    else:
        time = cmdline.split()[0].replace("[","").replace("]","")
        fc_tokens = cmdline.split()
        fc = os.path.basename(fc_tokens[-2])
        tag = fc_tokens[-3]
    return time,tag,fc,log

def get_fc_and_cat_and_date_for_demux(path):

    category = "demux"
    log = os.path.join(path, "pyflow.data","logs","pyflow_log.txt")
    cmdline = None
    for line in open(log,"rb"):
        if line.find("ProcessCmdLine") > -1:
            cmdline = line
            break
    if cmdline == None:
        fc = "error"
        time = "error"
    else:
        time = cmdline.split()[0].replace("[","").replace("]","")
        fc_tokens = cmdline.split()
        fc = os.path.basename(fc_tokens[-1].replace("'",""))
    localdemux = None
    stderrlog = os.path.join(path, "pyflow.data","logs","pyflow_tasks_stderr_log.txt")
    scratchdir=None
    for line in open(stderrlog,"rb"):
        if line.find("Creating directory") > -1:
            scratchdir = line.strip().split("Creating directory")[1].replace("'","")
            break
    scratchdir = "".join([x for x in scratchdir if ord(x) >= 33 and ord(x) < 127])
    # remove some ascii formatting
    scratchdir = scratchdir[:-3]
        
    return time,category,fc,log+" "+scratchdir

def get_fc_and_cat_and_date_for_readycheck(path):


    category = "readycheck"
    log = os.path.join(path, "pyflow.data","logs","pyflow_log.txt")
    cmdline = None
    for line in open(log,"rb"):
        if line.find("ProcessCmdLine") > -1:
            cmdline = line
            break
    if cmdline == None:
        fc = "error"
        time = error
    else:
        time = cmdline.split()[0].replace("[","").replace("]","")
        fc_tokens = cmdline.split()
        fc = os.path.basename(fc_tokens[-2])
        tag = fc_tokens[-3] 
    return time,tag,fc,log

if __name__=='__main__':
    args = parse_args()
    source_dirname = args.basedir
    output_filename = args.output_filename

    paths = glob.glob(os.path.join(source_dirname,"*","*","*"))
    
    demux = []
    readycheck = []
    gwr = []
    for p in paths:
        if p.find("readycheck.pyflow") > -1:
            readycheck.append(p)
        elif p.find("demultiplexer.pyflow") > -1:
            demux.append(p)
        elif p.find("generic_workflow_runner.pyflow") > -1:
            gwr.append(p)

    events = []

    for fn in demux:
        events.append(get_fc_and_cat_and_date_for_demux(fn))

    for fn in readycheck:
        events.append(get_fc_and_cat_and_date_for_readycheck(fn))

    for fn in gwr:
        events.append(get_fc_and_cat_and_date_for_gwr(fn))

    events.extend(find_docker_messages_with_error(args.dockermessagedir))
    events.sort()
    fout = file(output_filename,"wb")
    fout.write("time\ttrack\ta\tb\n")
    for e in events:
        fout.write("\t".join(e)+"\n")
    fout.close()

        
    
                
        
