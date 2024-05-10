package main

import (
	"github.com/gin-gonic/gin"
)

func main() {
    r := gin.Default()
    r.GET("/ping", func(c *gin.Context) {
        c.JSON(200, gin.H{
            "message": "pong",
        })
    })
	// login func username root password root
	r.POST("/login", func(c *gin.Context) {
		username := c.PostForm("username")
		password := c.PostForm("password")
		if username == "root" && password == "root" {
			c.JSON(200, gin.H{
				"status": "you are logged in",
			})
		} else {
			c.JSON(401, gin.H{
				"status": "unauthorized",
			})
		}
	})
    r.Run() // listen and serve on 0.0.0.0:8080
}