# Hawkdisk

## Build
``` bash
[you@machine]make
```

## Generate files for read experiments
``` bash
[you@machine]./dataset/gen_read_data.sh
```
Note that if you encounter `permission denied issue`, change mode of the file and resume the file again.
``` bash
[you@machine]chmod +x ./dataset/gen_read_data.sh
```
Note that this will take some time.

## Run Experiments

### 3.1 Write Sequentially
``` bash
[you@machine]make run_seq_write
```

### 3.2 Read Sequentially
``` bash
[you@machine]make run_seq_read
```

### 3.3 Write Randomly
``` bash
[you@machine]make run_rnd_write
```
### 3.4 Read Randomly
``` bash
[you@machine]make run_rnd_read
```
### 3.5 Write Randomly for IOPS with 4KB
``` bash
[you@machine]make run_rnd_write_iops
```

### Read Randomly for IOPS with 4KB
``` bash
[you@machine]make run_rnd_read_iops
```

Each command will run against each dataset, concurrency, and record size

If you want to run an individual experiment, print usage by running the below
``` bash
[you@machine]./hawkdisk
```
## Clear Results

Those experiments will generate outputs under ./results/<experiment_name> directory. 
The below command will clear results of each experiment


### 4.1 Clear Write Sequentially 
``` bash
[you@machine]make clear_seq_write
```

### 4.2 Clear Read Sequentially
``` bash
[you@machine]make clear_seq_read
```

### 4.3 Clear Write Randomly
``` bash
[you@machine]make clear_rnd_write
```

### 4.4 Clear Read Randomly
``` bash
[you@machine]make clear_rnd_read
```
### 4.5 Clear Write Randomly for IOPS
``` bash
[you@machine]make clear_rnd_write_iops
```	
### 4.6 Clear Read randomly for IOPS 
``` bash
[you@machine]make clear_rnd_read_iops
```

## Copyright and License

Permission is hereby granted, free of change, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute and/or sublicense copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions.

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTIO WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Credits and Acknowledgements

Author of the hawkdisk

Gyucheon Heo
Author of the hawkdisk version 1.0

Gyucheon Heo
Contact Information

Gyucheon Heo
email : gheo1[at]hawk[dot]iit[dot]edu
mobile: +1 224 209 3797
