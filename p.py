import socket
import alsaaudio
from os import system


def volume_up():
    system("vlc-ctrl volume +10%")

def volume_down():
    system("vlc-ctrl volume -0.1")


listen_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
listen_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
listen_socket.bind(('', 8090))
listen_socket.listen(0)
print('Serving HTTP on port %s' % 8090)

is_paused = False

while True:
    client_connection, client_address = listen_socket.accept()
    request = client_connection.recv(1024)
    print(request)
    print('   %d' % len(request))
    if request in [b'Up', b'Clockwise']:
        volume_up()
    
    elif request in [b'Down', b'anti-clockwise']:
        
        volume_down()
    
    elif request in [b'wave']:
        if is_paused:
            system("vlc-ctrl play")
        else:
            system("vlc-ctrl pause")
        
        is_paused = not is_paused
        

    client_connection.close()
