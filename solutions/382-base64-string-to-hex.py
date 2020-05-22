"""
Yesterday you implemented a function that encodes a hexadecimal string into Base64.

Write a function to decode a Base64 string back to a hexadecimal string.

For example, the following string:

3q2+7w==
should produce:

deadbeef
"""

import codecs

def convertBase64ToHex(string: str):
    return codecs.encode(codecs.decode(string, 'base64'), 'hex').decode('utf-8')
    

if __name__ == '__main__':
    print(convertBase64ToHex("3q2+7w=="))
    
