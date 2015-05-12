CREATE DATABASE IF NOT EXISTS `robodata` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `robodata`;

DROP TABLE IF EXISTS `checkpoint`;
CREATE TABLE IF NOT EXISTS `checkpoint` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `x` int(11) NOT NULL,
  `y` int(11) NOT NULL,
  `z` int(11) NOT NULL,
  `vehicle_id` int(11) NOT NULL,
  `map_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `vehicle_id` (`vehicle_id`),
  KEY `map_id` (`map_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

DROP TABLE IF EXISTS `map`;
CREATE TABLE IF NOT EXISTS `map` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) NOT NULL,
  `creation_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

DROP TABLE IF EXISTS `object`;
CREATE TABLE IF NOT EXISTS `object` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `polygon` polygon NOT NULL,
  `height` int(11) NOT NULL DEFAULT '0',
  `map_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

DROP TABLE IF EXISTS `qr`;
CREATE TABLE IF NOT EXISTS `qr` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `x` int(11) NOT NULL,
  `y` int(11) NOT NULL,
  `z` int(11) NOT NULL,
  `map_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `map_id` (`map_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

DROP TABLE IF EXISTS `vehicle`;
CREATE TABLE IF NOT EXISTS `vehicle` (
  `id` int(11) NOT NULL,
  `height` int(11) NOT NULL,
  `width` int(11) NOT NULL,
  `depth` int(11) NOT NULL,
  `naam` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


ALTER TABLE `checkpoint`
  ADD CONSTRAINT `checkpoint_ibfk_2` FOREIGN KEY (`map_id`) REFERENCES `map` (`id`),
  ADD CONSTRAINT `checkpoint_ibfk_1` FOREIGN KEY (`vehicle_id`) REFERENCES `vehicle` (`id`);
  
ALTER TABLE `qr`
  ADD CONSTRAINT `qr_ibfk_1` FOREIGN KEY (`map_id`) REFERENCES `map` (`id`);
  
ALTER TABLE  `object` ADD SPATIAL(
`polygon`
);

SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '\nThis version of mysql is unsuported.\nIt has worse performances. Please upgrade to mysql 5.7.4';
