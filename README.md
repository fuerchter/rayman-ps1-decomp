# rayman-splat

instructions for ubuntu jammy (22.04LTS):

add slus-000.05 `sha1 4ac1789e118933762cd0ebcb9a970f63dfe2c72f` to project root  
get psyq3.6 from https://github.com/Xeeynamo/wine-psyq, add to tools dir  
get psyq-obj-parser from https://github.com/mkst/pcsx-redux/releases/, add to tools dir
```
sudo add-apt-repository ppa:dosemu2/ppa
sudo apt update
sudo apt install python3 python3-pip binutils-mips-linux-gnu dos2unix dosemu2

python3 -m pip install -r ./tools/splat/requirements.txt

make dirs
make extract
make
```
sha1sum should print OK

## Matching functions

Change an `asm` segment to `c`, re-run `make extract` and `make`, then copy the :OK: build into the `expected/` directory and run `asm-differ`.

```
cp -r build expected/
python3 tools/asm-differ/diff.py -mwo FunctionToMatch
```
