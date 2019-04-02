#!/bin/bash
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=16
#SBATCH --time=1:00:00
#SBATCH --job-name pranjal16
#SBATCH --output=diff_16.txt
#SBATCH --mail-type=FAIL

module load gcc hdf5 netcdf boost gnu-parallel

cd $SLURM_SUBMIT_DIR

export OMP_NUM_THREADS=1
./diffring

export OMP_NUM_THREADS=2
./diffring

export OMP_NUM_THREADS=3
./diffring

export OMP_NUM_THREADS=4
./diffring

export OMP_NUM_THREADS=5
./diffring

export OMP_NUM_THREADS=6
./diffring

export OMP_NUM_THREADS=7
./diffring

export OMP_NUM_THREADS=8
./diffring

export OMP_NUM_THREADS=9
./diffring

export OMP_NUM_THREADS=10
./diffring

export OMP_NUM_THREADS=11
./diffring

export OMP_NUM_THREADS=12
./diffring

export OMP_NUM_THREADS=13
./diffring

export OMP_NUM_THREADS=14
./diffring

export OMP_NUM_THREADS=15
./diffring

export OMP_NUM_THREADS=16
./diffring

wait
