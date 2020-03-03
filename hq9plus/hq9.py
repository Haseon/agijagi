from sys import argv

class hq9_program:
    def __init__(self, code):
        self.code = code
        self.acc = 0
    def hello(self):
        print("Hello, World!", end='')
    def quine(self):
        print(self.code, end='')
    def bottles(self):
        print("99 bottles of beer on the wall,", end='')
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
        ix = argv.index('-f')
        filelist = argv[ix+1:]
        for filename in filelist:
            last_file = filename
            if filename[-3:] not in (".hq", ".h", ".hq9"):
                raise not_an_HQ9plus_script
            with open(filename) as f:
                code = f.read()
            hq9_program(code).run()
    except ValueError:
        print("Invalid arguments structure: '-f' option required before file names.")
    except FileNotFoundError:
        print("No such HQ9+ script file: {0}".format(last_file))
    except not_an_HQ9plus_script:
        print("'{0}' does not seem to be a HQ9+ code. If it surely is, please change its filename extension to '.hq'".format(last_file))
