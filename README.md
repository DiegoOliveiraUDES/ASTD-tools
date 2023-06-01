# ASTD-tools
ASTD support tools

# Installation of eASTD and cASTD 

## eASTD 

eASTD is the editor for ASTD specifications.  It is written in Javascript and runs on most operating systems using the Electron platform. An ASTD specification is saved in two files 

- <spec-name>.eastd : it contains the detailed json representation of the ASTD specification. 

- <spec-name>.json : it contains the ASTD specification in the format required by cASTD, the ASTD compiler. 

### Dependencies eASTD

Node.js 

### Installation eASTD

1. Download eastd.zip and unzip it 

2. Start a terminal in the unzipped directory eASTD-master 

3. Run command “npm install”  

### Run eASTD 

1. Run command “npm start” from the unzipped directory eASTD-master 

## cASTD 

cASTD is the compiler for ASTD specifications.  It is written in Java and it generates C++ programs. It takes as input an ASTD specification file “<spec-name>.json” produced by eASTD when an eASTD specification is saved. 

### Dependencies cASTD

- Java : at least JDK 1.8 (i.e., Jave SE 8 or later) 

- C++ compiler v14 or later, than can be run as command “g++” 

  - MAC OS: use clang from Xcode or Brew 

  - Windows: use https://www.mingw-w64.org/ or  https://www.cygwin.com/ 

- Make utility 

  - Windows: 

    - The simplest choice is using Chocolatey. First you need to install this package manager. Once installed you simply need to install make (you may need to run it in an elevated/admin command prompt): 
choco install make 
 
- Pthreads lib for windows users. 

  - Available with MinGW https://sourceforge.net/projects/mingw/ 

  - Available with MSYS2 https://www.mingw-w64.org/downloads/#msys2 

### Installation cASTD

1. Download castd.jar in some directory <dir> 

### Run cASTD 

1. Run command: java -jar \<dir\>/castd.jar -s <spec-name>.json  -o <output-dir>
   1. It will produce in <output-dir> 
      1. <A>.cpp : the C++ source code implementing the first top level ASTD found in the ASTD specification, denoted here by <A>. 
         1. Use option -m to choose another top-level ASTD 
      2. <A> : the compiled and linked version of <A>.cpp 
   2. You can run the generated program by executing “<A>” in a terminal. 
2. Run command “java -jar <dir>/castd.jar -h” to get a full list of cASTD options 
