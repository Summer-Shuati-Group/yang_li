# Read from the file file.txt and output all valid phone numbers to stdout.
# 1. use grep, -P option interprets in regex
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt

# 2. use sed  -r option interprets in regex
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

# 3. use awk
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt