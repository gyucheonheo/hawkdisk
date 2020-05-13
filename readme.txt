Hawkdisk

1. Build
$>make

2. Generate files for read experiments

$> ./dataset/gen_read_data.sh

Note that if you encounter permission denied issue, change mode of the file and resume the file again.

$> chmod +x ./dataset/gen_read_data.sh

Note that this will take some time.

3. Run Experiments

3.1 Write Sequentially
$>make run_seq_write

3.2 Read Sequentially
$>make run_seq_read

3.3 Write Randomly
$>make run_rnd_write

3.4 Read Randomly
$>make run_rnd_read

3.5 Write Randomly for IOPS with 4KB
$>make run_rnd_write_iops

3.6 Read Randomly for IOPS with 4KB
$>make run_rnd_read_iops


Each command will run against each dataset, concurrency, and record size

If you want to run an individual experiment, print usage by running the below
$>./hawkdisk

4. Clear Results

Those experiments will generate outputs under ./results/<experiment_name> directory. 
The below command will clear results of each experiment

4.1 Clear Write Sequentially 
$>make clear_seq_write

4.2 Clear Read Sequentially
$>make clear_seq_read

4.3 Clear Write Randomly
$>make clear_rnd_write

4.4 Clear Read Randomly
$>make clear_rnd_read

4.5 Clear Write Randomly for IOPS
$>make clear_rnd_write_iops
	
4.6 Clear Read randomly for IOPS 
$>make clear_rnd_read_iops

