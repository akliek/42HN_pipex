# 42HN_pipex
Summary:

This project is the discovery in detail and by programming of a UNIX mechanism.

Foreword:

Cristina: "Go dance salsa somewhere :)"

Links:

Wikipedia article about pipelines: https://de.wikipedia.org/wiki/Pipeline_(Unix)

Wikipedia article about redirections: https://en.wikipedia.org/wiki/Redirection_(computing)

Subject PDF: https://github.com/akliek/42HN_pipex/blob/master/en.subject.pdf

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# Instalation
Then go to created repository and run following command:
```
make
```
# Run
After insatalation run following command:
```
./pipex <infile> <cmd1> <cmd2> <outfile>
```
The execution of the pipex program should do the same as the next shell command:
```
$> file1 < cmd1 | cmd2 > file2
```
