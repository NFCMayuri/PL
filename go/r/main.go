package main

import (
	"flag"
	"fmt"
)

func main() {
	r1 := (flag.Int("r1", -1, "the value of R1"))
	r2 := (flag.Int("r2", -1, "the value of R2"))
	r := (flag.Int("r", -1, "the value of R"))
	flag.Parse()
	if (-1 != *r) && (-1 != *r1) && (-1 != *r2) {
		fmt.Printf("(R R1)R2=%f\n(R1 R2)R=%f\n", float64((*r1)*(*r))/float64(*r1-*r), float64((*r1)*(*r2))/float64((*r1)+(*r2)))
		return
	}
	if (-1 == *r1) && (-1 != *r2) {
		*r1 = *r2
		*r2 = -1
	}
	if -1 == *r1 || ((-1 == *r) && (-1 == *r2)) {
		fmt.Printf("plz input args\n")
		return
	}
	if *r != -1 {
		fmt.Printf("R2=%f\n", float64((*r1)*(*r))/float64(*r1-*r))
		return
	}
	if *r2 != -1 {
		fmt.Printf("R=%f\n", float64((*r1)*(*r2))/float64((*r1)+(*r2)))
		return
	}
}
