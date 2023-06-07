CREATE TABLE `users` (
	`id` INT(11) NOT NULL AUTO_INCREMENT,
	`username` VARCHAR(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
	`pass` VARCHAR(45) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
	PRIMARY KEY (`id`)
) ENGINE=INNODB;

INSERT INTO users(username, pass) VALUES('daniel', 'sekula');
INSERT INTO users(username, pass) VALUES('ante', 'antic');

DROP TABLE users;

CREATE TABLE IF NOT EXISTS `users` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(45) NOT NULL,
  `pass` VARCHAR(45) NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `table1col_UNIQUE` (`username` ASC))
ENGINE = INNODB;


SET SESSION sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));
SET GLOBAL sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));
SET GLOBAL sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));

GRANT ALL ON sql11498555 TO 'root';

GRANT ALL PRIVILEGES ON testdb TO 'root'@'34.154.39.68';

SELECT @@sql_mode;

/* information.schema.statistics.non_unique */


CREATE TABLE IF NOT EXISTS `testdb`.`testTable` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `col1` VARCHAR(45) NOT NULL,
  `col2` VARCHAR(45) NULL,
  PRIMARY KEY (`id`)
  )
ENGINE = INNODB;

INSERT INTO testTable(col1, col2) VALUES ("test1", "test2");


SET nocount ON






