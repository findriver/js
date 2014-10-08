#set new build name
echo -n BUILD_NAME= > buildname
git log |
  head -5 |                                                               #get latest commit info
  sed -e '3d' -e '4d' -e 's/\(Author: \|commit \)//g' |   #delete unnecessary lines 
  awk '{if(NR==2) print $1$2; else print $0}' |          #delete space between author name and email 
  tr '\n' '-' | sed 's/.$//' >> buildname                   #use - as delimiter, delete last dash, save to file

#run karma test
karma start jobs/Test101/workspace/up/karma.conf.js