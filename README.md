# pit

# Dependencies

* **dirname**

# Install

1. For installing pit put the directory in any folder in your computer

``` bash
mv pit ~/
```

2. Edit your .bashrc file to include pit extension

``` bash
# ~/.bashrc
source /path/to/pit.sh
```

# Using pit

## Paths

Paths is a main functionality in pit. You can define some routes to be used in another commands

**Add a new path**

``` bash
#pit path add <pathname> <path>

pit path add containers ~/docker/containers
```

**List paths**
``` bash
#pit path list [<regex>]

pit path list
pit path list cont
```

**Remove paths**
``` bash
#pit path rm <pathname>

pit path rm containers
```


## Overriden comands

### cd

You can benefit from *paths* to be used in cd.

``` bash
#cd [<pathname> | directory ]

cd containers # go to ~/docker/containers
cd /home/     # go to /home
```