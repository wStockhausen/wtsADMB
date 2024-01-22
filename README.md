wtsADMB
=======

## Introduction

A library of ADMB routines, primarily for use with the Tanner crab modeling framework TCSAM02 (https://github.com/wStockhausen/tcsam02).

## Required libraries

The ADMB C++ libraries are required to compile wtsADMB. The relevant ADMB library can be found at http://www.admb-project.org. The current version of wtsADMB uses ADMB version 13.1.

## Installation 

### On OSX or linux

Follow the installation instructions for ADMB (http://www.admb-project.org) to install the required library (and associated header files) prior to creating the wtsADMB library. 

After installation, create environment variable ADMB_HOME the path to the parent folder of the "include" and "lib" directories for the ADMB installation. 

### on Windows

If you don't already have RTools installed on your machine, download and install it. Add the "bin" folder that contains the "g++" executable to the Windows search path. Also, create an environment variable "RToolsUsr" that contains the path to the "usr" folder in the RTools distribution. Then install ADMB as above (and create the associated environment variable), making sure the RTools compiler is the one used for compilation.

## Using CMake 

On Windows, an executable version of cmake comes with the RTools installation (in the same folder as g++.exe). On OSX or linux, download and install a version from https://cmake.org/download/.

To create the wtsADMB library, open a command prompt (Windows) or terminal window (OSX or linux), change to the top folder in the wtsADMB directory tree (the one with src and include sub-folders) and enter the following commands:

    * cmake --S . --build _build
    * cmake --build _build

These will create the "_build" folder and create the wtsADMB library (as libwtsADMB.a). [Note: do not replace "_build" in the above with another folder name of your choosing]. For future reference, create an environment variable WTSADMB_HOME with the path to the paraent folder of _build.


## Setting up wtsADMB as a Netbeans Project

Netbeans should be configured with the C++ modules installed.

    1. Use Team/git/clone to clone the repository into TopFolder/wtsADMB, where "TopFolder" is an arbitrary directory:
        a. select the "master" branch
        b. uncheck "Scan for Netbeans Project"
    2. Create a new C++ static library project called "wtsADMB" in the TopFolder directory (so TopFolder/wtsADMB will be the top-level directory for the Netbeans project). Using the Project Creator:
        a. create a "new" C++ static library project in TopFolder
        b. use "wtsADMB" as the project name
        c. use the default Makefile
        d. save the project
    3. edit the nbproject/configuration.xml file:
        a. change the default makefile to the cloned version


