#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=16
#SBATCH --time=1:00:00
#SBATCH --job-name openmp_job
#SBATCH --output=openmp_output_%j.txt
#SBATCH --mail-type=FAIL

module load gcc hdf5 netcdf boost gnu-parallel

cd $SLURM_SUBMIT_DIR

./diffring

wait
