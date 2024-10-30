printf "#Architecture : "
uname -a

printf "#CPU physical : "
nproc

printf "#vCPU : "
grep -c processor /proc/cpuinfo

printf "Memory Usage : "
free --mega | grep Mem | awk '{ use += $3; total += $2 } END {printf use"/"total"MB"; printf " (%.2f%%)\n", use/total * 100}'

printf "Disk Usage : "
df -a -BM | grep dev/map | awk '{ sum+=$3 } END { printf sum"/" }'
df -a -BM | grep dev/map | awk '{ sum += $4 } END { printf sum"GB" }'
df -a -BM | grep dev/map | awk '{ sum += $5 } END { printf " ("sum"%%)\n"}'

# "CPU load : "
mpstat | grep all | awk '{printf "CPU load : %.2f%%\n", 100-$13}'

# "Last boot : "
who -b | awk '{print "Last boot : "$3" "$4}'

printf "LVM use : "
lsblk | grep -c lvm | awk '{if ($0 > 0) print "yes"; else print $0 "no"; }'

printf "Connections TCP : "
ss | grep -c tcp | awk '{print $0 " ESTABLISHED"}'

printf "User log : "
who | grep -c pts | awk '{print $0}'

printf "Network : "
hostname -I | awk '{print "IP " $1}'
ip link | grep ether | awk '{print "(" $2 ")"}'

printf "Sudo : "
journalctl -q _COMM=sudo | grep -c COMMAND | awk '{print $1 " cmd"}'
