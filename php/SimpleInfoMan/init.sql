CREATE DATABASE IF NOT EXISTS ruankai_test1 CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
-- 切换到 user_management 数据库
USE ruankai_test1;
-- 在 user_management 数据库中创建名为 users 的表
CREATE TABLE IF NOT EXISTS users (
  id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
  username VARCHAR(255) NOT NULL,
  password VARCHAR(255) NOT NULL,
  email VARCHAR(255) NOT NULL UNIQUE
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_general_ci;
CREATE TABLE IF NOT EXISTS `ruankai_test1`.`info` (
  `id` INT(11) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `name` VARCHAR(255) NOT NULL,
  `age` INT(11) NOT NULL,
  `gender` VARCHAR(50) NOT NULL,
  `birthday` DATE NOT NULL,
  `club` VARCHAR(255) NOT NULL
);
CREATE TABLE  IF NOT EXISTS tokens (
  id INT(11) NOT NULL AUTO_INCREMENT,
  username VARCHAR(50) NOT NULL,
  token VARCHAR(255) NOT NULL,
  expiration_time DATETIME NOT NULL,
  PRIMARY KEY (id),
  INDEX (username),
  FOREIGN KEY (username) REFERENCES users(username)
);