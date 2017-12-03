package main


import "net"


import "fmt"


import "bufio"


import "os"




func main() {


  fmt.Println("Launching server...")

  
  
  ln, _ := net.Listen("tcp", ":7777")

  
  
  conn, _ := ln.Accept()

 
  
  if(clientsentence.contains("morning")) {	
    
    conn, _ := net.Dial("tcp","192.168.80.133",8888)  
    
    reader := bufio.NewReader(os.Stdin)
    
    fmt.Print("Text to send: ")
  
    
    text, _ := reader.ReadString('\n')
    
    
    fmt.Fprintf(conn, text + "\n")

  
  }
  
  else if(clientsentence.contains("night")) {	
    
    conn2, _ := net.Dial("tcp","192.168.80.136",9999)  
    
    reader := bufio.NewReader(os.Stdin)
 

    fmt.Print("Text to send: ")
 

    text, _ := reader.ReadString('\n')
    
    
    fmt.Fprintf(conn2, text + "\n")

   
  }
}