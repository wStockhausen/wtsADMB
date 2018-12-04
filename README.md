wtsADMB
=======

## Introduction
A library of ADMB routines, primarily for use with the Tanner crab modeling frameworks 
TCSAM2013 (https://github.com/wStockhausen/tcsam2013) and, more recently, 
TCSAM02 (https://github.com/wStockhausen/tcsam02).

## Required libraries
The admb C++ libraries are required to compile wtsADMB. The relevant ADMB library can be found at http://www.admb-project.org. The
current version of wtsADMB uses ADMB version 12.

## Setting up wtsADMB as a Netbeans Project
Netbeans should be configured with the C++ modules installed. 
1. Use Team/git/clone to clone the repository into TopFolder/wtsADMB, where "TopFolder" is an arbitrary directory.
    \cr\t a. select the "master" branch
    \cr\t b. uncheck "Scan for Netbeans Project"
2. Create a new C++ static library project called "wtsADMB" in the TopFolder directory (so TopFolder/wtsADMB
will be the top-level directory for the Netbeans project). Using the Project Creator:
    \cr\t a. create a "new" C++ static library project in TopFolder
    \cr\t b. use "wtsADMB" as the project name
    \cr\t c. use the default Makefile
    \cr\t d. save the project
3. edit the nbproject/configuration.xml file.
    \cr\t change the default makefile to the cloned version


