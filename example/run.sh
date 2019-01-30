#!/bin/sh
cd ${0%/*} || exit 1    # Run from this directory
./clean.sh
# Source tutorial run functions
. $WM_PROJECT_DIR/bin/tools/RunFunctions

application=`getApplication`

runApplication blockMesh
# cp 0/k.orig 0/k
# runApplication setFields
# gmshToFoam test.msh
# gmsh -3 mesh.geo
# gmshToFoam mesh.msh

# runApplication setFields
runApplication $application
paraFoam
