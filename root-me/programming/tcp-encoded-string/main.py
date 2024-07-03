import socket
import re
import base64

HOST, PORT = 'challenge01.root-me.org', 52023

def parse_data(data: str) -> str:
    match = re.search(r'[a-zA-Z0-9]+=+?', data)
    return match.group(0) if match else None

def connect(host: str, port: int) -> str:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        data = s.recv(1024).decode('utf-8').strip()
        if data:
            print(f"Received data: {data}")
            encoded_string = parse_data(data)
            if encoded_string:
                print(f"Encoded string: {encoded_string}")
                decoded_bytes = base64.b64decode(encoded_string)
                decoded_string = decoded_bytes.decode('utf-8')
                print(f"Decoded string: {decoded_string}")
                decoded_string = decoded_string + "\n"
                s.send(decoded_string.encode('utf-8'))
                res = s.recv(1024).decode('utf-8')
                print(f"Server response: {res}")
                return res
        return "No data received"

if __name__ == '__main__':
    print(connect(HOST, PORT))
