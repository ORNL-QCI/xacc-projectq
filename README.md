[![Build Status](https://travis-ci.org/ORNL-QCI/xacc-projectq.svg?branch=master)](https://travis-ci.org/ORNL-QCI/xacc-projectq)

# XACC Plugins for working with ProjectQ
This plugin for XACC provides a Compiler implementation for the ProjectQ QASM syntax. 

Installation
------------
With the XACC framework installed, users can choose a couple ways to install these plugins - using Python/Pip
```bash
$ python -m pip install --user .
```
or CMake and Make without Python support
```bash
$ mkdir build && cd build
$ cmake .. -DXACC_DIR=$HOME/.xacc (or wherever you installed XACC)
$ make install 
```
or with Python support
```bash
$ cmake .. -DXACC_DIR=$(python -m pyxacc -L)
$ make install
```

Documentation
-------------

* [XACC Website and Documentation ](https://xacc.readthedocs.io)

Questions, Bug Reporting, and Issue Tracking
--------------------------------------------

Questions, bug reporting and issue tracking are provided by GitHub. Please
report all bugs by creating a new issue with the bug tag. You can ask
questions by creating a new issue with the question tag.

License
-------

XACC-ProjectQ is licensed - [BSD 3-Clause](LICENSE).
