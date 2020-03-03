from sys import argv

class hq9_program:
    def __init__(self, code, fullsong):
        self.code = code
        self.acc = 0
        self.fullsong = fullsong
    def hello(self):
        print("Hello, World!", end='')
    def quine(self):
        print(self.code, end='')
    def bottles(self):
        if self.fullsong:
            for n in range(99, -1, -1):
                if n == 0:
                    print("No more bottles of beer on the wall, no more bottles of beer.\nGo to the sstore and buy some more, 99 bottles of beer on the wall.\n")
                else:
                    print("{0} bottles of beer on the wall, {0} more bottles of beer.\nTake one down and pass it around, {1} bottles of beer on the wall.\n".format(n, n-1))
        else:
            print("99 bottles of beer on the wall, 99 bottels of beer.", end='')
    def plus(self):
        self.acc += 1
    def run(self):
        for c in self.code:
            if c in "Hh":
                self.hello()
            elif c in "Qq":
                self.quine()
            elif c == '9':
                self.bottles()
            elif c == '+':
                self.plus()
            else:
                pass

class not_an_HQ9plus_script(Exception):
    pass

if __name__ == "__main__":
    try:
        current_file = ''

        fullsong = '--full' in argv
        if fullsong:
            f_ix = argv.index('--full')
            argv = argv[:f_ix] + argv[f_ix+1:]

        ix = argv.index('-f')
        filelist = argv[ix+1:]
        for filename in filelist:
            last_file = filename
            if filename[-3:] not in (".hq", ".h", ".hq9"):
                raise not_an_HQ9plus_script
            with open(filename) as f:
                code = f.read()
            hq9_program(code, fullsong).run()

    except ValueError:
        print("Invalid arguments structure: '-f' option required before file names.")
    except FileNotFoundError:
        print("No such HQ9+ script file: {0}".format(last_file))
    except not_an_HQ9plus_script:
        print("'{0}' does not seem to be a HQ9+ code. If it surely is, please change its filename extension to '.hq'".format(last_file))
