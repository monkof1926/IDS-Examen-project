package sample;

public class Controller {

    UdpBroadcastServer udpBroadcastServer;
    UdpConnector udpConnector;

    // this method is executed when our GUI is ready
    public void initialize()
    {
        // start broadcastserver in thread
        udpBroadcastServer = new UdpBroadcastServer();
        new Thread(udpBroadcastServer).start();

        udpConnector = new UdpConnector(this);
        new Thread(udpConnector).start();


    }

    public void toggleBtnEchoServer()
    {
        System.out.println("toggle echo server");
    }

    public void toggleBroadcastBtn()
    {
        System.out.println("toggle broadcast");
    }

    public void clearTable()
    {
        System.out.println("clear table");
    }

    public void handleMessage()
    {
        // executed by my echoserver instance
    }
}
