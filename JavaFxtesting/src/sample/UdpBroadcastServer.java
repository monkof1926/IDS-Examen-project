package sample;

import java.io.IOException;
import java.net.*;

public class UdpBroadcastServer implements Runnable {

    private boolean broadcast = true;
    private DatagramSocket socket;
    private int portBroadcast = 7007;
    private String message = "echo server listens on port 7000, answers on port 7007";

    public boolean isBroadcast() {
        return broadcast;
    }

    public void setBroadcast(boolean broadcast) {
        this.broadcast = broadcast;
    }

    public void broadcastLoop()
    {
        while (true) {
            try {

                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if (broadcast) broadcastMessage(message);
        }
    }

    private void broadcastMessage(String message) {
        try {
            socket = new DatagramSocket();
            socket.setBroadcast(true);
            byte[] buffer = message.getBytes();
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, InetAddress.getByName("255.255.255.255"), portBroadcast);
            socket.send(packet);
            socket.close();

        } catch (SocketException | UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    @Override
    public void run() {
        // this metho9d is whatr starts the thread!!!!!
        broadcastLoop();
    }
}
