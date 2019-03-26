#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=8
#SBATCH --time=4:00:00
#SBATCH --job-name openmp_job
#SBATCH --output=openmp_output_%j.txt
#SBATCH --mail-type=FAIL

module load gcc hdf5 netcdf boost gnu-parallel

cd $SLURM_SUBMIT_DIR

for ((i=1;i<41;i++)); do

    ./antsontable --length=100 --seed=i --total_ants=20000 --time_steps=100000 --screen_output_steps=0 --netcdf_output_steps=0
    ./antsontable --length=150 --seed=i --total_ants=20000 --time_steps=100000 --screen_output_steps=0 --netcdf_output_steps=0
    ./antsontable --length=200 --seed=i --total_ants=20000 --time_steps=100000 --screen_output_steps=0 --netcdf_output_steps=0
    ./antsontable --length=250 --seed=i --total_ants=20000 --time_steps=100000 --screen_output_steps=0 --netcdf_output_steps=0

done
wait
