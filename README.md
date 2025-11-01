# RacCryption
A simple text file encrypter / decrypter.

## How to use:
Dependencies: `gcc cmake`

> [!IMPORTANT]  
> My default location for output files is in `$(pwd)/out` and for text files it is `$(pwd)/txt_files`.

```bash
# Compiling the code
make build

# Running the code
make run ARGS="path_to_file key"
```