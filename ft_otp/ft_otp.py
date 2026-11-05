import hashlib
import argparse
import sys
import itertools

def hmac(K, C):
    k_ipad = bytearray(K, 'latin-1')
    k_opad = bytearray(K, 'latin-1')

    for i in range(20):
        k_ipad[i] ^= 0x36
        k_opad[i] ^= 0x5c

    inner_hash = hashlib.sha1(k_ipad + C).digest()

    return hashlib.sha1(k_opad + inner_hash).digest()

def hopt(K, C):
    String = hmac(K, C)
    Offset = String[19] & 0x0f
    P = String[Offset:Offset+4]
    P = P & 0x7FFFFFFF

    Snum = int.from_bytes(P, "big")
    return Snum % 10**len(String)

def encryption(fname):
    try:
        f = open(fname, 'rb')
    except OSError:
        print("Could not open/read file: ", fname)
        sys.exit(1)

    with f:
        key = f.read()
        if (len(key) != 64):
            print("error: key must be 64 hexadecimal characters.")
            f.close()
            sys.exit(1)
        hash_object = hashlib.sha1(key)
    f.close()

    try:
        with open("ft_otp.key", "w") as f:
            f.write(hash_object.hexdigest())

    except OSError:
        print("Could not open/write file: ft_otp.key")
        sys.exit(1)
    

def parser():
    parser = argparse.ArgumentParser(
        prog='ProgramName',
        description='What the program does',
        epilog='Text at the bottom of help')
    parser.add_argument('-g')
    parser.add_argument('-k')

    return parser.parse_args()

def main():
    args = parser()

    if type(args.g) is str:
        encryption(args.g)
    print(hopt("01234567890123456789", 0))

    

if __name__ == "__main__":
    main()
