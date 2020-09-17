# Audio Generators

This is a compilation of different audio generation programs using [libsndfile](http://www.mega-nerd.com/libsndfile/) to handle audio files.

## Current programs
- sqrgen: generates a mono square wave.
```
$ sqrgen [-d DURATION] [-f FREQUENCY]
```
- sinegen: generates a mono sine wave.
```
$ sinegen [-d DURATION] [-f FREQUENCY]
```
- tablegen: generates a mono wave from a table (currently set to a sine).
```
$ tablegen [-d DURATION] [-f FREQUENCY]
```

## Notes
- Work-in-progress

## TODO
- Add compilation instructions (currently should only compile in UNIX-like systems)
- Translate all C programs into C++
