package main

import "net"

import "fmt"

import "bufio"

import "os"



func main() {
  
  conn, _ := net.Dial("tcp",192.168.94.129",7777) 
  
  reader := bufio.NewReader(os.Stdin)
  
  fmt.Print("Text to send: ")
  
  text, _ := reader.ReadString('\n')
    
  fmt.Fprintf(conn, text + "\n")

}
