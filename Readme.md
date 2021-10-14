Tgen ( Tranduder Input Generator & Output Parser )
------------


1. Compile

```
$ gcc tgen.c -o tgen 
```

2. Generate Input Transducer

```
$ ./tgen -i 2013
or
$ ./tgen --input=2013
```

3. Parse Transducer Output (with epislon filtering)

```
$ ./tgen -o examples/a.txt
or
$ ./tgen --output=examples/a.txt
```
