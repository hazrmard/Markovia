# Markovia
Generate random text using Markov chains.  

##Running
```bash
> markovia -f <filename> -n <number of threads> -o <order of chain> -l <approx. output length>
```
  
##Compilation  
This application was developed on Windows with *Cygwin* installed (with `make` tools) and added to system path. Simply browse in command line to the directory and type:  
```bash
> make
```  
It should create `markovia.exe` or `markovia` in the `bin\` directory.  
