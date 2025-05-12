<?php
session_start();
include_once('database/connection.php');
include_once('database/users.php');
include_once('database/news.php');
include_once('database/comments.php');
include_once('templates/common.php');
include_once('templates/news.php');

$db = getDatabaseConnection();

if (userExists($db, $_POST['username'], $_POST['password']))
    $_SESSION['username'] = $_POST['username'];

header('Location: ' . $_SERVER['HTTP_REFERER']);
