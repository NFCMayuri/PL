CREATE TABLE IF NOT EXISTS `user` (
    `id` int AUTO_INCREMENT,
    `name` varchar(255),
    `sex` varchar(255),
    `class` int,
    PRIMARY KEY(id)
);
CREATE TABLE IF NOT EXISTS `account` (
    `username` VARCHAR(100) NOT NULL,
    `password` VARCHAR(100) NOT NULL
);