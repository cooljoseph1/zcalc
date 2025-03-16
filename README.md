# ZCalc
ZCalc is a simple calculator written in C that converts between z-scores and percentages.

# Installation
The default installation configuration is to just install `zcalc`, the shell
that converts between z-scores and percentiles. This can be done via
```sh
make
make install
```
The second command usually requires super-user permissions. If it doesn't work
the first time, try re-running it with `sudo`:
```sh
sudo make install
```

You can also install two other programs: `zpercent` and `zscore`. The program
`zpercent` is used to exclusively convert from z-scores to percentiles, and
the program `zscore` is used to exclusively convert from percentiles to z-scores.
The commands to install them are `make zpercent && make install/zpercent` and
`make zscore && make install/zscore`, respectively. Alternatively, you can install
everything with
```sh
make all
make install/all
```

The programs `zpercent` and `zscore` are provided because they are useful for chaining
with other programs. Unlike `zcalc`, they don't append a "z" or "%" to their output,
and they don't require their input to have one either. They are especially useful when
chaining them with another calculator, such as with `bc -l | zscore`. These programs
also print out their results to higher precision than `zcalc` does.

# Usage
To use `zcalc`, first install it. After installation, it can be run from the command line:
```sh
zcalc
```
This will open up an interactive shell where you can type either a percentile (ending in "%")
or a z-score (ending in "z") and it will print out the conversion. For example:
```sh
zcalc
> 75%
0.674z
> 2z
97.72%
> 50%
0.000z
```
