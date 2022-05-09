---
title: Contributing
---
# Contributing

## Assumptions

It is assumed that you have experience with C++ and C, and know how to build/compile projects with `make`. It is also assumed that you have the following dependancies installed on your system:

- `make`
- `git`
- `clang++`
- `clang` or `gcc`

## Introduction

Before your make any changes, please do the following:

1. Fork the repository from github
2. Clone your repository
 
 ```
 git pull https://github.com/[yourname]/BFC.git
 ```
 
2. Make a new branch using the following syntax:

 Syntax: `dev-[myname]`
 Git commands:
 ```
 git branch dev-[myname]
 git checkout dev-[myname]
 ```

## Making Changes

Once you have make changes to the repository:

1. Push the changes to your GitHub repository

 ```
 git push https://github.com/[yourname]/BFC.git
 ```
 
2. Open a pull request

## Important things

- Don't include built files in your PR unless they are located in the dist folder with the following name syntax: `dist/[os]-[architecture]-bfc` or `dist/[os]-[architecture]-bfc.exe`
- Making changes may require changes to the documentation. Make sure you adjust the documentation according to your changes.