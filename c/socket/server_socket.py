from socket import *
import ujson as json


res = "HTTP/1.1 200 OK\r\n\r\n" + json.dumps({'code': 200})

def main():
    tcp_server_socket = socket(AF_INET, SOCK_STREAM)
    tcp_server_socket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    
    tcp_server_socket.bind(("0.0.0.0", 8000))
    tcp_server_socket.listen(128)
    
    while True:
        
        new_client, client_addr = tcp_server_socket.accept()
        print(client_addr)
        
        recv_data = new_client.recv(1024)
        print(recv_data.decode())
        
        new_client.send(res.encode())
    
        new_client.close()
    tcp_server_socket.close()
    

if __name__ == "__main__":
    main()