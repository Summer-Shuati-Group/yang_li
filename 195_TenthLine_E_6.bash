# Read from the file file.txt and output the tenth line to stdout.
sed -n '10p' < file.txt 
# l10=`head -n 10 file.txt | wc -l`
# if [ "$l10" = "10" ]; then
# head -n 10 file.txt | tail -1
# fi