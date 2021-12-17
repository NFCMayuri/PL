package main

import (
	"fmt"
	"log"
	"net/http"
)

//go doc Server
func index(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello world!")
	//fmt.Fprintf(w io.Writer,format string,a ...interface{})(n int, err error)
	//io.WriteString(w io.Writer,String string)
}
func main() {
	http.HandleFunc("/", index)
	//http.HandleFunc(pattern string,handler func(w http.ResponseWriter,w *http.Request)
	err := http.ListenAndServe(":9090", nil)
	//http.ListenAndServe(addr string, handler Handler)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}
