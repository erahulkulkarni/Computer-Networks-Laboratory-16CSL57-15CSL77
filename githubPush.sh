#!/bin/sh

 git add .
 
 message=$@
 
 if [ ${#message} -eq 0 ]
   then
     echo "Enter commit message: "
     read message
 fi 
 git commit -m "$message"

 git push https://github.com/erahulkulkarni/Computer-Networks-Laboratory-16CSL57-15CSL77
