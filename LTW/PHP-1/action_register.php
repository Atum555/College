<?php
session_start();
include_once('database/connection.php');
include_once('database/users.php');
include_once('database/news.php');
include_once('database/comments.php');
include_once('templates/common.php');
include_once('templates/news.php');

$db = getDatabaseConnection();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username']);
    $password = trim($_POST['password']);

    if (empty($username) || empty($password)) {
        $_SESSION['error'] = 'Username and password cannot be empty.';
        header('Location: register.php');
        exit();
    }

    try {
        if (createUser($db, $username, $password)) {
            $_SESSION['username'] = $username;
            header('Location: /');
        } else {
            $_SESSION['error'] = 'Username already exists.';
            header('Location: register.php');
        }
    } catch (Exception $e) {
        $_SESSION['error'] = 'An error occurred. Please try again later.';
        header('Location: register.php');
    }
    exit();
}
