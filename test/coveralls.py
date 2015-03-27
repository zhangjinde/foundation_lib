#!/usr/bin/env python

import sys
import argparse
import os
import subprocess
import json
import hashlib
import requests
from coverage import parse_gcov

def merge_reports( basereport, addreport ):
  baselen = len(basereport)
  addlen = len(addreport)
  for line in range( 0, addlen ):
    if line >= baselen:
      basereport.append( addreport[line] )
    elif basereport[line] == None:
      basereport[line] = addreport[line]
    elif basereport[line] == 0 and addreport[line] != None:
      basereport[line] = addreport[line]
    elif addreport[line] != None:
      basereport[line] += addreport[line]
  return basereport

def post_report( coverage ):
  response = requests.post( 'https://coveralls.io/api/v1/jobs', files= { 'json_file': json.dumps( coverage ) } )
  try:
    result = response.json()
  except ValueError:
    result = { 'error': 'Failure to submit data. '
               'Response [%(status)s]: %(text)s' % {
               'status': response.status_code,
               'text': response.text } }
  return result

argparser = argparse.ArgumentParser( description = 'Ninja build generator' )
argparser.add_argument( '-o', '--objectdir', required = True,
                     help = 'Object directory' )
argparser.add_argument( '-s', '--sourcedir', required = True,
                     help = 'Source directory' )
options = argparser.parse_args()

infiles = {}
for file in os.listdir( options.objectdir ):
  basefile = os.path.splitext(file)[0]
  if file.endswith(".gcda"):
    if not basefile in infiles:
      infiles[basefile] = ( False, False )
    infiles[basefile] = ( True, infiles[basefile][1] )
  elif file.endswith(".gcno"):
    if not basefile in infiles:
      infiles[basefile] = ( False, False )
    infiles[basefile] = ( infiles[basefile][0], True )

sourcefiles = {}
for file in os.listdir( options.sourcedir ):
  if file.endswith(".c") or file.endswith(".m"):
    sourcefiles[file] = []

for key, pair in infiles.iteritems():
  if pair[0] and pair[1]:
    subprocess.call( [ "gcov", "-gcda=" + os.path.join( options.objectdir, key + ".gcda" ), "-gcno=" + os.path.join( options.objectdir, key + ".gcno" ), "source" ] )
    for file in os.listdir('.'):
      if file.endswith(".gcov"):
        sourcefile = os.path.splitext(file)[0]
        if sourcefile in sourcefiles:
          results = parse_gcov( file )
          sourcefiles[sourcefile] = merge_reports( sourcefiles[sourcefile], results )
        os.remove( file )

sourcelist = []
for sourcefile, report in sourcefiles.iteritems():
  sourcereport = {}
  sourcereport['name'] = os.path.join( options.sourcedir, sourcefile )
  sourcereport['source_digest'] = hashlib.md5( open( sourcereport['name'], 'rb').read() ).hexdigest()
  sourcereport['coverage'] = report
  sourcelist.append( sourcereport )

coveralls = {}
coveralls['repo_token'] = 'yiZoExCQa8uW2CmJd7MmmqmzZPOEphG4B'
coveralls['source_files'] = sourcelist

result = post_report( coveralls )
print result

#generate output coveralls report

#for count in report:
#  print str( count )
