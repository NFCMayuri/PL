package main

import (
	"fmt"
	"log"
	"net/http"
)

var indexhtml = `
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-type" content="test/html" ; charset="utf-8">
<title> This is Mayuri  </title> 
</head>
<body>
	<h2>Title </h2>
	<p>Paragraph<p>
</body>
</html>
`

func index(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, indexhtml)
}
func main() {
	http.HandleFunc("/test", index)
	err := http.ListenAndServe(":3344", nil)
	if err != nil {
		log.Fatal("ListenAndServe", err)
	}
}
