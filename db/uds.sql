-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 25, 2022 at 07:47 AM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `uds`
--

-- --------------------------------------------------------

--
-- Table structure for table `registration`
--

CREATE TABLE `registration` (
  `id` int(255) DEFAULT NULL,
  `serialno` varchar(255) NOT NULL,
  `name` text NOT NULL,
  `age` varchar(255) NOT NULL,
  `gender` text NOT NULL,
  `address` varchar(255) NOT NULL,
  `phone` varchar(255) NOT NULL,
  `date&time` datetime DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `registration`
--

INSERT INTO `registration` (`id`, `serialno`, `name`, `age`, `gender`, `address`, `phone`, `date&time`) VALUES
(0, '', '', '', '', '', '', '0000-00-00 00:00:00'),
(0, '', '', '', '', '', '', '0000-00-00 00:00:00'),
(0, '', '', '', '', '', '', '0000-00-00 00:00:00'),
(0, '', '', '', '', '', '', '0000-00-00 00:00:00'),
(0, '', '', '', '', '', '', '0000-00-00 00:00:00'),
(0, '', '', '', '', '', '', '0000-00-00 00:00:00'),
(0, 'qwwwe', 'rewrwef', '23', 'mafgf', '309', '0713297997', '0000-00-00 00:00:00'),
(0, 'qwwwe', 'rewrwef', '23', 'mafgf', '309', '0713297997', '0000-00-00 00:00:00'),
(0, 'UDS 001', 'Martin', '23', 'male', '309-20100 nakuru', '0713297997', '0000-00-00 00:00:00'),
(0, 'UDS 002', 'Eileen Njoki', '20', 'Female', '2015-20100 Nakuru', '0715803274', '0000-00-00 00:00:00'),
(0, 'UDS 003', 'Peter Mwangi', '10', 'male', '2015-20100 Nakuru', '0715803274', '2022-02-24 20:17:56');

-- --------------------------------------------------------

--
-- Table structure for table `reported`
--

CREATE TABLE `reported` (
  `id` int(255) NOT NULL,
  `serialno` varchar(255) DEFAULT NULL,
  `latitude` varchar(255) DEFAULT NULL,
  `longitude` varchar(255) DEFAULT NULL,
  `date&time` datetime DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `reported`
--
ALTER TABLE `reported`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `reported`
--
ALTER TABLE `reported`
  MODIFY `id` int(255) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
