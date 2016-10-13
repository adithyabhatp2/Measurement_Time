
rm -f *_baseline.txt
rm -f *_diff.txt

for clk in monotonic monotonic_raw cpu_process_cputime realtime
do
	head -1001 $clk.txt | tail -1000 > ${clk}_baseline.txt
done


for clk in monotonic monotonic_raw cpu_process_cputime realtime
do
	tail -1000 $clk.txt > ${clk}_diff.txt
done
