"""
This problem was asked by Paypal.

Implement a function that converts a hex string to base64.

For example, the string:

deadbeef
should produce:

3q2+7w==
"""

import codecs

def convertHexToBase64(string: str):
    return codecs.encode(codecs.decode(string, 'hex'), 'base64').decode('utf-8')
    

if __name__ == '__main__':
    print(convertHexToBase64("deadbeef"))
    
