#!/bin/sh

 git add .
 
 message=$@
 git commit -m "$message"

 git push https://github.com/erahulkulkarni/Computer-Networks-Laboratory-16CSL57-15CSL77
