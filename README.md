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
Netbeans should be configured with the C++ modules installed.<br/>
&nbsp; 1. Use Team/git/clone to clone the repository into TopFolder/wtsADMB, where "TopFolder" is an arbitrary directory:<br/>
    &nbsp; &nbsp; a. select the "master" branch<br/>
    &nbsp; &nbsp; b. uncheck "Scan for Netbeans Project"<br/>
&nbsp; 2. Create a new C++ static library project called "wtsADMB" in the TopFolder directory (so TopFolder/wtsADMB
will be the top-level directory for the Netbeans project). Using the Project Creator:<br/>
    &nbsp; &nbsp; a. create a "new" C++ static library project in TopFolder<br/>
    &nbsp; &nbsp; b. use "wtsADMB" as the project name<br/>
    &nbsp; &nbsp; c. use the default Makefile<br/>
    &nbsp; &nbsp; d. save the project<br/>
&nbsp; 3. edit the nbproject/configuration.xml file:<br/>
    &nbsp; &nbsp; change the default makefile to the cloned version<br/>


