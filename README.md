# rayman-splat

instructions for ubuntu jammy (22.04LTS):

add SLUS-000.05 `sha1 4ac1789e118933762cd0ebcb9a970f63dfe2c72f` to project root  
get gcc-2.5.7 (wip, dm me to get it in the meantime), add to tools dir
```
sudo apt install python3 python3-pip binutils-mips-linux-gnu

python3 -m pip install -r ./tools/splat/requirements.txt

make extract
make
```
sha1sum should print OK

## Matching functions

Change an `asm` segment to `c`, re-run `make extract` and `make`, then copy the OK build into the `expected/` directory and run `asm-differ`.

```
cp -r build expected/
python3 tools/asm-differ/diff.py -mwo FunctionToMatch
```
